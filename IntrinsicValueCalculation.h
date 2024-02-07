#ifndef _INTRINSICVALUECALCULATION_H_
#define  _INTRINSICVALUECALCULATION_H_

#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <curl/curl.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include <map>
#include <stdexcept>
#include  "Logger.h"
#include "Cashflowstatement.h"
#include "Incomestatement.h"
#include "Balancesheet.h"
#include "Keyratios.h"


double calculateCAGR(const std::vector<Income_statement*> &i, int years) {
    if (i.size() < years || years < 1) {
     throw std::invalid_argument("Not enough data points to calculate CAGR for the specified number of years.");
    }
    
    // the vector is backwards !!! the first item is the most recent years
    double beginningValue = static_cast<double>(i[years -1]->get_revenue()); 
    double endingValue = static_cast<double>(i[0]->get_revenue()); 
    
    // Calculating CAGR using the formula
    double CAGR = pow((endingValue / beginningValue), (1.0 / years)) - 1;
    
    return CAGR;
}


double get_growth_rate(std::vector<Income_statement*> &is, char &flag, int period){
    if(is.empty() || (period > is.size())){
        throw std::invalid_argument("Invalid data, the vector is empty or Period bigger than our records. can't compute growth rate\n");
    } else if(is.size() == 1){
        throw std::invalid_argument("Invalid data, the vector has just one element. can`t compute growth rate");    
    } 
    
    std::reverse(is.begin(),is.end());  
    double total_percentage_rate {0.0};
    
    switch(flag){
        
        case 'r': 
                     for(size_t i{0}; i < period; ++i){
                        // cout<< "revenue: " << is[i+1]->get_revenue() <<std::endl;
                     double percentage_change = ((static_cast<double>(is[i+1]->get_revenue()) - static_cast<double>(is[i]->get_revenue())) / static_cast<double>(is[i]->get_revenue()))*100;
                      total_percentage_rate += percentage_change;
                      //std::cout << total_percentage_rate<<std::endl;
                      } 
                    break;
                    
        case 'n': 
                     for(size_t i{0}; i < period; ++i){
                     double percentage_change = ((static_cast<double>(is[i+1]->get_net_income()) - static_cast<double>(is[i]->get_net_income())) / static_cast<double>(is[i]->get_net_income()))*100;
                      total_percentage_rate += percentage_change;
                     }
                    break;
     }
     
     //std::cout << "Grow rate: " <<total_percentage_rate / static_cast<double>((is.size() -1)) << std::endl;
     //
     
     //reversing back the vector
     std::reverse(is.begin(),is.end());
     
     return total_percentage_rate / static_cast<double>((period-1));
}

double median_historical_pe(std::vector<Key_ratios*> &ratios, int year){
     
     if(year>ratios.size() || ratios.size() <=1){
          throw std::invalid_argument("Not enough data points for the specified number of years");
     }
     
    std::vector<double> median_pes;    


    //median pe calculation
    for(int i{0}; i < year; i++){
                median_pes.push_back(ratios[i]->get_pe_ratio());
     }
     
     
     std::sort(median_pes.begin(),median_pes.end());
     
     if(median_pes.size() % 2 == 0){
         // even number of element
         return (median_pes[median_pes.size() / 2 -1 ] + median_pes[median_pes.size() /2])/2;
     } else {
         return median_pes[median_pes.size()/2];
     } 
        
}

/*
 * This function compute the avarage eps on the last 'period' years. 
 * period is an int.
 * 
 */

double eps_average(std::vector<Income_statement*> &i, int period){
     double total_eps{0.0};
      
       if(i.empty() ||(period > i.size())){
             throw std::invalid_argument("period of years bigger than our records or empty Vector\n");
           }
       
    
       for(int j{0}; j < period; j++){
               total_eps += i[j]->get_eps();
           }
    return total_eps / period;
}

double get_pe_evaluetion(const std::string &ticker, std::vector<Income_statement*> &i, std::vector<Key_ratios*> &ratios){
    Logger logger("pe_evaluation.log");
    int years = 5;
    
    //using the most recent value becuase i belive is more accurate
    
    int index_for_accurate_eps{0};
    for(int j{0}; j< i.size(); ++j){
          if(i[j]->get_period() == "FY"){
                index_for_accurate_eps = j;
                break;
              }
     }
     
    double eps = i[index_for_accurate_eps]->get_eps();
    //std::cout<< "eps is: " << eps << std::endl;
    double growth_rate{0.0};
    try {
     //char flag = 'n';   
     growth_rate=  calculateCAGR(i,years);
    
    } catch (const std::invalid_argument& e) {
    // Handle exception, e.g., log it or inform the user
    logger.log("Error computing PE/valuation"+ticker+" (growth_rate): " +e.what(),Logger::Level::Error);
    } 
    double m_h_pe {0.0};
    double margin_of_safety = 0.25;
    double conservative_growth_rate = growth_rate*(1-margin_of_safety);
    double discout_rate = 0.09;
    
    try{
       m_h_pe = median_historical_pe(ratios,years);
        } catch (const std::invalid_argument &e){
            logger.log("Error computing PE/valuation"+ticker+" (m_h_pe): " +e.what(),Logger::Level::Error);
        }
    
    double value_in_five_years = eps;

    for(int i{0}; i < years;++i){
        value_in_five_years *= (1+ conservative_growth_rate);
    }
    
      
    return (value_in_five_years * m_h_pe)/(pow(1 + discout_rate,years));
}


void run_java_scraper(std::string link){
    std::string command = "java -jar javaScraper.jar " + link;
    system(command.c_str());
}

long long reading_java_scraper_output(std::string ticker){
        Logger logger("reading_java_out_file.log");
        std::ifstream input_file("output.txt");
        std::string line;
        long long shares_oustanding{0ll};
        
        if(input_file.is_open()){
             while(getline(input_file, line)){
                 shares_oustanding = std::stoll(line);
                 }
        } else {
          logger.log("unable to open the file for :"+ticker+".",Logger::Level::Error);    
        }
    return shares_oustanding;
}


double get_dcf_model(const std::string &ticker, std::vector<Cashflowstatement*> &cfs, std::vector<Balancesheet*> &bs,std::vector<Income_statement*> &is){
    Logger logger("dcf_computing.log");
    double free_cash_flow = static_cast<double>(cfs[0]->get_free_cash_flow());
    
    double cash_and_cash_equevalent = static_cast<double>(bs[0]->get_cash_and_cash_equivalents());
   
    double total_liabilities = static_cast<double>(bs[0]->get_total_current_liabilities()) + bs[0]->get_total_non_current_liabilities();
    
    double growth_rate{};
    try {
     int years = 5;   
     //char flag {'n'};
     growth_rate= calculateCAGR(is,years);
    
    } catch (const std::invalid_argument& e) {
    // Handle exception, e.g., log it or inform the user
      logger.log("Error computing growth rate for dfc model for " +ticker+": "+ e.what(), Logger::Level::Error);
    // Handle error situation, like returning a default value or continuing with alternative logic
     growth_rate = 0;
    } 
   
     
    double outstanding_shares {};
    
    if(is[0]->get_outstanding_share_from_sec() == 0) {
          //std::cout << cfs[0]->get_final_link() + "\n";
             
           run_java_scraper(cfs[0]->get_final_link());
           is[0]->set_outstanding_share_from_sec(reading_java_scraper_output(ticker));
           outstanding_shares = static_cast<double>(is[0]->get_outstanding_share_from_sec()); 
        
        } else {
            outstanding_shares = is[0]->get_outstanding_share_from_sec();
        }
        
     if(outstanding_shares == 0){
          throw std::invalid_argument("not possible to compute DFC. outstanding shares is 0\n");
        }
   
    double margin_of_safety = 0.28;
    double grow_of_decline = 0.05;
    double conservative_growth_rate = growth_rate*(1-margin_of_safety);
    if(conservative_growth_rate < 0.0)
        conservative_growth_rate= 0.0;
        
    double discout_rate = 0.16; 
   
    
   
  
    
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


std::string formattig_result_into_json(std::string ticker, double pe_value_company,
                                        double dfc,
                                        double roic,
                                        double pb_ratio,
                                        long long oe,
                                        double growth_rate_revenue,
                                        double growth_rate_net_income){
              std::string json_string {"{\n"};
              json_string += "  \"ticker\": \"" + ticker + "\",\n";
              json_string += "  \"valuation\": {\n";
              json_string += "    \"PE_valuation\": " + (std::isnan(pe_value_company) ? "0.0" : std::to_string(pe_value_company)) +", \n";
              json_string += "    \"DFC_valuation\": " + (std::isnan(dfc) ? "0.0" : std::to_string(dfc)) + "\n";
              json_string += "  },\n";
              json_string += "  \"ratios\": {\n";
              json_string += "    \"ROIC\": " + std::to_string(roic) + ",\n";
              json_string += "    \"PB\": " + std::to_string(pb_ratio) + "\n";
              json_string += "  },\n";
              json_string += "  \"ownerEarnings\": " + std::to_string(oe)+",\n";
              json_string += "  \"growth_rate_revenue\": " + (std::isnan(growth_rate_revenue) ? "0.0" : std::to_string(growth_rate_revenue)) + ",\n";
              json_string += "  \"growth_rate_net_income\": " + (std::isnan(growth_rate_net_income) ? "0.0" : std::to_string(growth_rate_net_income)) + "\n";
              json_string += "}\n";
              
              return json_string;
                                                          
                                        
}


void create_json_result(
                std::string &ticker,
                std::vector<Balancesheet*> &bs,
                std::vector<Income_statement*> &is,
                std::vector<Cashflowstatement*> &cfs,
                std::vector<Key_ratios*> &ratios) {
     
     Logger logger("create_json_result.log");               
     double pe_value_company = get_pe_evaluetion(ticker, is, ratios);  
     double dfc {0.0};
      
     try{
         dfc = get_dcf_model(ticker,cfs,bs,is);
     } catch (const std::invalid_argument &e){
         logger.log(e.what(),Logger::Level::Error);
     } 
     
     double roic = ratios[0]->get_roic() * 100;
     double pb_ratio = ratios[0]->get_pb_ratio(); 
     long long oe = get_owner_earnings(bs,is,cfs);

     
    double growth_rate_revenue{0.0};
    double growth_rate_net_income{0.0};
    
    //std::cout<< "entering the growth try catch block;
     try {
        int years = 5;
      char flag = 'r';
      growth_rate_revenue = get_growth_rate(is,flag,years);
      flag ='n';
      growth_rate_net_income = get_growth_rate(is,flag,years);
      
     } catch (const std::invalid_argument& e) {
     // Handle exception, e.g., log it or inform the user
      logger.log(e.what(),Logger::Level::Error);
    } 
      
      
    
    std::string jsonStr = formattig_result_into_json(ticker,pe_value_company,dfc,roic,pb_ratio,oe,growth_rate_revenue,growth_rate_net_income);
    
    std::string fileName = ticker + ".json"; 
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << jsonStr;
        outFile.close();
        logger.log("Data saved to " + fileName,Logger::Level::Info);
    } else {
        logger.log("Unable to open "+fileName+" for writing",Logger::Level::Error);
    }
}




// Helper function to convert a string to uppercase
std::string to_uppercase(const std::string &input) {
    std::string output = input;
    std::transform(output.begin(), output.end(), output.begin(),
                   [](unsigned char c) -> unsigned char { return std::toupper(c); });
    return output;
}

std::map<std::string, std::string> load_current_mappings(const std::string& file_path) {
    std::map<std::string, std::string> mappings;
    std::ifstream in(file_path);
    std::string line;
    Logger logger("file_map_json.log");
    if (in.is_open()) {
        while (getline(in, line)) {
            std::string company_name, ticker;
            std::size_t start_pos, end_pos;

            start_pos = line.find("\"");
            end_pos = line.find("\":", start_pos + 1);
            if (start_pos != std::string::npos && end_pos != std::string::npos) {
                company_name = to_uppercase(line.substr(start_pos + 1, end_pos - start_pos - 1));

                start_pos = line.find("\"", end_pos + 3);
                end_pos = line.find("\"", start_pos + 1);
                if (start_pos != std::string::npos && end_pos != std::string::npos) {
                    ticker = to_uppercase(line.substr(start_pos + 1, end_pos - start_pos - 1));
                    mappings[company_name] = ticker;
                }
            }
        }
        in.close();
    } else {
        logger.log("No existing mapping file found. A new one will be created.", Logger::Level::Info);
    }

    return mappings;
}

// Helper function to remove extra quotes from a string
std::string remove_extra_quotes(const std::string& input) {
    std::string result = input;
    if (!result.empty() && result.front() == '\"') {
        result.erase(0, 1); // Remove the first character if it's a quote
    }
    if (!result.empty() && result.back() == '\"') {
        result.pop_back(); // Remove the last character if it's a quote
    }
    return result;
}


void saving_maps_to_file(const std::map<std::string, std::string>& mappings, const std::string& file_path) {
    std::ofstream out(file_path);
    
    Logger logger("saving_map_file.log");
    if (out.is_open()) {
        out << "{\n";
        for (auto it = mappings.begin(); it != mappings.end(); ) {
            std::string key = remove_extra_quotes(it->first);
            std::string value = remove_extra_quotes(it->second);

            out << "  \"" << key << "\": \"" << value << "\"";
            if (++it != mappings.end()) {
                out << ",";
            }
            out << "\n";
        }
        out << "}\n";
        out.close();
        logger.log("Data saved to " + file_path,Logger::Level::Info);
    } else {
        logger.log("Unable to open " + file_path + " for writing.",Logger::Level::Error);
    }
}

void add_or_update_map(const std::string& name, const std::string& ticker, const std::string& file_path) {
    auto mappings = load_current_mappings(file_path);
    mappings[to_uppercase(name)] = to_uppercase(ticker);
    saving_maps_to_file(mappings, file_path);
}



#endif