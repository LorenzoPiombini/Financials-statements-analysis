#ifndef _INTRINSICVALUECALCULATION_H_
#define  _INTRINSICVALUECALCULATION_H_

#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <curl/curl.h>
#include <fstream>
#include <iostream>
#include "Cashflowstatement.h"
#include "Incomestatement.h"
#include "Balancesheet.h"
#include "Keyratios.h"

double get_growth_rate(std::vector<Income_statement*> is){
    
    std::reverse(is.begin(),is.end());
    std::vector<double> growth_rates;
    
    double beginning_value = static_cast<double>(is.front()->get_revenue());
    double last_value = static_cast<double>(is.back()->get_revenue());
    int number_years = is.size()-1;
     
    
     return std::pow((last_value / beginning_value),(1.0/number_years)) -1; 
}

double median_historical_pe(const std::string &ticker, std::vector<Key_ratios*> &ratios){
    
    std::vector<double> median_pes; 
    
//    std::string response = get_company_key_ratios(ticker);
//    ratios = parsing_json_from_api<Key_ratios>(response,ticker);
//    


    //median pe calculation
    for(auto item : ratios){
                median_pes.push_back(item->get_pe_ratio());
     }
     
     
     std::sort(median_pes.begin(),median_pes.end());
     
     if(median_pes.size() % 2 == 0){
         // even number of element
         return (median_pes[median_pes.size() / 2 -1 ] + median_pes[median_pes.size() /2])/2;
     } else {
         
         return median_pes[median_pes.size()/2];
        }
        
}

double get_pe_evaluetion(const std::string &ticker, std::vector<Income_statement*> &i, std::vector<Key_ratios*> &ratios){
    
    double eps = i[0]->get_eps();
    double growth_rate = get_growth_rate(i);
    double margin_of_safety = 0.25;
    double conservative_growth_rate = growth_rate*(1-margin_of_safety);
    double discout_rate = 0.09; 
    double m_h_pe = median_historical_pe(ticker,ratios);
    double value_in_five_years = eps;

    for(int i{1}; i < 5;++i){
        value_in_five_years *= (1+ conservative_growth_rate);
    }
    
    //5 are the numbers of years   
    return (value_in_five_years * m_h_pe)/(pow(1 + discout_rate,5));
}


void run_java_scraper(std::string link){
    std::string command = "java -jar javaScraper.jar " + link;
    system(command.c_str());
}

long long reading_java_scraper_output(){
        std::ifstream input_file("output.txt");
        std::string line;
        long long shares_oustanding{};
        
        if(input_file.is_open()){
             while(getline(input_file, line)){
                 shares_oustanding = std::stoll(line);
                 }
        } else {
          std::cout << "unable to open the file";    
        }
    return shares_oustanding;
}


double get_dcf_model(const std::string &ticker, std::vector<Cashflowstatement*> &cfs, std::vector<Balancesheet*> &bs,std::vector<Income_statement*> &is){
    
    double free_cash_flow = static_cast<double>(cfs[0]->get_free_cash_flow());
    
    double cash_and_cash_equevalent = static_cast<double>(bs[0]->get_cash_and_cash_equivalents());
   
    double total_liabilities = static_cast<double>(bs[0]->get_total_current_liabilities()) + bs[0]->get_total_non_current_liabilities();
    

    double growth_rate = get_growth_rate(is);
     
    
        
    double margin_of_safety = 0.25;
    double grow_of_decline = 0.05;
    double conservative_growth_rate = growth_rate*(1-margin_of_safety);
    if(conservative_growth_rate < 0.0)
        conservative_growth_rate= 0.0;
        
    double discout_rate = 0.09; 
    //std::cout << "Provide outstanding shares for " + ticker << ": ";
    run_java_scraper(cfs[0]->get_final_link());
    
    double outstanding_shares {};
     
    outstanding_shares = static_cast<double>(reading_java_scraper_output()); 
   // std::cout << outstanding_shares << std::endl;
    
    //this line is to avoid a carry over input from "Provide outstanding shares for " line
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    
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



void past_performance_five_years(std::string ticker,std::vector<Cashflowstatement*> cfs, std::vector<Balancesheet*> bs,std::vector<Income_statement*> is){
     
    double growth_avarage_last_five_years{0.0};
     
    
    
    
    for(size_t i{0}; i < is.size(); ++i){
        
        
        
        if(i < (is.size()-1)){
            growth_avarage_last_five_years += ((static_cast<double>(is[i]->get_net_income())/is[i+1]->get_net_income())-1)*100;
//       std::cout << "Year: " << is[i]->get_calendar_year()<< ", "
//        <<is[i]->get_net_income() << "percentage on previus year: " << 
//        ((static_cast<double>(is[i]->get_net_income())/is[i+1]->get_net_income())-1)*100<<" %\n";
        } else {
//            std::cout << "Year: " << is[i]->get_calendar_year()<< ", "
//        <<is[i]->get_revenue() << "percentage on previus year: " << 0 << " %\n";
        }
        
            
        
        }
    
     std::cout<< "avarage grow rate past 5 years " << growth_avarage_last_five_years / (is.size() -1) << "\n";
     
}

// this take in considerations only the most recent year
long long get_owner_earnings( 
                std::vector<Balancesheet*> &bs,
                std::vector<Income_statement*> &is,
                std::vector<Cashflowstatement*> &cfs){
                    
        long long operating_profit = is[0]->get_operating_income();
        long long  depreciation = is[0]->get_depreciation_and_amortization();
        long long income_tax = is[0]->get_income_tax_expense();
        long long cost_of_stock_option =cfs[0]->get_stock_based_compensation();
        long long capex = cfs[0]->get_capital_expenditure();
        long long income_from_pension_fund =is[0]->get_total_other_income_expensesNet();
        
        return operating_profit + depreciation - income_tax - cost_of_stock_option - capex -income_from_pension_fund;
    
}

// this take in considerations only the most recent year
long long get_invested_capital( 
                std::vector<Balancesheet*> &bs,
                std::vector<Income_statement*> &is,
                std::vector<Cashflowstatement*> &cfs){
                    
    long long total_assets = bs[0]->get_total_assets();
    long long cash = bs[0]-> get_cash_and_cash_equivalents() + bs[0]->get_cash_and_short_term_investments();
    long long non_interest_bearing_current_liabilities = bs[0]->get_account_payables() + bs[0]->get_tax_payables() + bs[0]->get_other_current_liabilities();
    
    return total_assets - (cash +non_interest_bearing_current_liabilities);
    
    
}

// this take in considerations only the most recent year
double get_ROIC(std::vector<Balancesheet*> &bs,
                std::vector<Income_statement*> &is,
                std::vector<Cashflowstatement*> &cfs){
    
        return (static_cast<double>(get_owner_earnings(bs,is,cfs))/get_invested_capital(bs,is,cfs)) *100;          
    
    
    }




#endif