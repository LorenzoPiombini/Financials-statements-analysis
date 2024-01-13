#ifndef _INTRINSICVALUECALCULATION_H_
#define  _INTRINSICVALUECALCULATION_H_

#include <string>
#include <cmath>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>
#include <curl/curl.h>
#include "Cashflowstatement.h"
#include "Getfunctions.h"
#include "Incomestatement.h"
#include "Balancesheet.h"
#include "HistoryStockPrices.h"
#include "Keyratios.h"
#include "Responseparsing.h"

double get_growth_rate(std::vector<Income_statement> is){
    
    std::reverse(is.begin(),is.end());
    std::vector<double> growth_rates;
    
    double beginning_value = static_cast<double>(is.front().get_revenue());
    double last_value = static_cast<double>(is.back().get_revenue());
    int number_years = is.size()-1;
     
   
     return std::pow((last_value / beginning_value),(1.0/number_years)) -1; 
}

double median_historical_pe(const std::string &ticker){
    
    std::vector<double> median_pes; 
    
    std::string response = get_company_key_ratios(ticker);
    std::vector<Key_ratios> ratios = parsing_json_from_api<Key_ratios>(response,ticker);
    
    //median pe calculation
    for(auto item : ratios){
                median_pes.push_back(item.get_pe_ratio());
     }
     
     
     std::sort(median_pes.begin(),median_pes.end());
     
     if(median_pes.size() % 2 == 0){
         // even number of element
         
         return (median_pes[median_pes.size() / 2 -1 ] + median_pes[median_pes.size() /2])/2;
     } else {
         
         return median_pes[median_pes.size()/2];
        }
        
}

double get_pe_evaluetion(const std::string &ticker){
    std::string is = get_company_income_statement(ticker,"annual");
    std::vector<Income_statement> i = parsing_json_from_api<Income_statement>(is,ticker);
    
    
    double eps = i[0].get_eps();
    double growth_rate = get_growth_rate(i);
    double margin_of_safety = 0.25;
    double conservative_growth_rate = growth_rate*(1-margin_of_safety);
    double discout_rate = 0.09; 
    double m_h_pe = median_historical_pe(ticker);
    double value_in_five_years = eps;

    for(int i{1}; i < 5;++i){
        value_in_five_years *= (1+ conservative_growth_rate);
    }
    
    //5 are the numbers of years   
    return (value_in_five_years * m_h_pe)/(pow(1 + discout_rate,5));
    
    
}



double get_dcf_model(const std::string &ticker){
    std::vector<Cashflowstatement> cfs = parsing_json_from_api<Cashflowstatement>(get_company_cash_flow(ticker, "anual"),ticker);
    double free_cash_flow = static_cast<double>(cfs[0].get_free_cash_flow());
    
    std::vector<Balancesheet> bs = parsing_json_from_api<Balancesheet>(get_company_balance_sheet(ticker,"annual"),ticker);
    
    double cash_and_cash_equevalent = static_cast<double>(bs[0].get_cash_and_cash_equivalents());
   
    double total_liabilities = static_cast<double>(bs[0].get_total_current_liabilities()) + bs[0].get_total_non_current_liabilities();
    

    double growth_rate = get_growth_rate(parsing_json_from_api<Income_statement>(get_company_income_statement(ticker,"annual"),ticker));
     
    
        
    double margin_of_safety = 0.25;
    double grow_of_decline = 0.05;
    double conservative_growth_rate = growth_rate*(1-margin_of_safety);
    if(conservative_growth_rate < 0.0)
        conservative_growth_rate= 0.0;
        
    double discout_rate = 0.09; 
    double outstanding_shares = static_cast<double>(bs[0].get_common_stock());
    double npv_fcf_total = 0.0;
    double year_10_fcf_multiplier = 12.0;
    
    
    for(int year =1 ; year <=10; ++year){
        free_cash_flow *= (1+ conservative_growth_rate);
        
        double npv_fcf = free_cash_flow / std::pow(1.0+discout_rate,year);
        
        npv_fcf_total += npv_fcf;
        conservative_growth_rate -= grow_of_decline;
        
        if(conservative_growth_rate < 0.0 )
             conservative_growth_rate = 0.0;
    }
    
    
    double year_10_value = free_cash_flow * year_10_fcf_multiplier / discout_rate;
    double npv_year_10_value = year_10_value / std::pow(1+discout_rate, 10);
    
    //company total value:
    double company_value = npv_fcf_total + npv_year_10_value + cash_and_cash_equevalent - total_liabilities;
    
    return company_value / outstanding_shares;
}



void past_performance_five_years(std::string ticker){
        
    std::vector<Balancesheet> balance_sheet = parsing_json_from_api<Balancesheet>(get_company_balance_sheet(ticker,"annual"),ticker);
    
    std::vector<Income_statement> income_statement = parsing_json_from_api<Income_statement>(get_company_income_statement(ticker,"annual"),ticker);
    
    std::vector<Cashflowstatement> cashflow_statement = parsing_json_from_api<Cashflowstatement>(get_company_cash_flow(ticker,"annual"),ticker);
     
    double growth_avarage_last_five_years{0.0};
     
    
    
    
    for(size_t i{0}; i < income_statement.size(); ++i){
        
        
        
        if(i < (income_statement.size()-1)){
            growth_avarage_last_five_years += ((static_cast<double>(income_statement[i].get_revenue())/income_statement[i+1].get_revenue())-1)*100;
       std::cout << "Year: " << income_statement[i].get_calendar_year()<< ", "
        <<income_statement[i].get_revenue() << "percentage on previus year: " << 
        ((static_cast<double>(income_statement[i].get_revenue())/income_statement[i+1].get_revenue())-1)*100<<" %\n";
        } else {
            std::cout << "Year: " << income_statement[i].get_calendar_year()<< ", "
        <<income_statement[i].get_revenue() << "percentage on previus year: " << 0 << " %\n";
            }
        
            
        
        }
    
     std::cout<< "avarage grow rate past 5 years " << growth_avarage_last_five_years / (income_statement.size() -1) << "\n";
     //std::cout<< "grow_rate using gpt method:  " << grow_chat_gpt << "\n"; 
      
      
      
}




#endif