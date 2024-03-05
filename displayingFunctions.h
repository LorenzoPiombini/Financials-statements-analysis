#ifndef _DISPLAYFUNCTIONS_H_
#define _DISPLAYFUNCTIONS_H_

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include "Incomestatement.h"
#include "Cashflowstatement.h"
#include "Balancesheet.h"
#include "Keyratios.h"


bool is_number(const std::string &str){
      char* end = nullptr;
      std::strtod(str.c_str(), &end);
      if(end == str.c_str() || *end !='\0' || end == nullptr){
          return false;
          }
      return true;         
    
}

bool is_q(const std::string &str){
    if(str.size() == 1){
    return str[0] == 'q' || str[0] == 'Q';
    } else {
        return false;
    }
}

void display_bs(std::vector<Balancesheet*> &data){
    
    std::cout << "we have " << data.size() << " "<< data[0]->get_class_name() <<", for the company, "<< data[0]->get_symbol() << std::endl;
    std::cout << "to select the document enter: 0 for the most recent and " << data.size()-1 << " for the oldest." << std::endl;
    
     while(true){
     std::cout << "enter q to exit/n";
     std::cout<< "Position nr: \n";
    
    std::string selector{};
    int position{};
    std::getline(std::cin,selector);
    
    if(is_q(selector)){
        break;
    }else if(is_number(selector)){
          position = std::stoi(selector);
          if(position < 0 || position > data.size()-1){
              std::cout<<"The number is invalid please try again./n";
              continue;
              }
    }else{
     std::cout<<"the input is not valid please try again.\n" ;  
    }
        
     std::cout<< "year: "<< data[position]->get_calendar_year() << " filing date: " << 
             data[position]->get_filling_date() << "." << std::endl; 
        std::cout <<"Cash and cash equivalent: "<< data[position]->get_cash_and_cash_equivalents()<< std::endl;
        std::cout <<"Short term investment: "<< data[position]->get_short_term_investments()<< std::endl;
        std::cout <<"Cash and short term investment: "<< data[position]->get_cash_and_short_term_investments()<< std::endl;
        std::cout <<"Net receivables: "<< data[position]->get_net_receivables()<< std::endl;
        std::cout <<"Inventory: "<< data[position]->get_inventory()<< std::endl;
        std::cout <<"Other current asset: "<< data[position]->get_other_current_assets()<< std::endl;  
        std::cout <<"Total current Asset: "<< data[position]->get_total_current_assets()<< std::endl;
        std::cout <<"Property plant equipment: "<< data[position]-> get_property_plant_equipment_net()<< std::endl;
        std::cout <<"Goodwill: "<< data[position]->get_goodwill()<< std::endl;
        std::cout <<"Intagible assets: "<< data[position]->get_intangible_assets()<< std::endl;
        std::cout <<"Good will and intangible asset: "<< data[position]->get_goodwill_and_intangible_assets()<< std::endl;   
        std::cout <<"Long term investment: "<< data[position]->get_long_term_investments()<< std::endl;
        std::cout <<"Tax assets: "<< data[position]->get_tax_assets()<< std::endl;
        std::cout <<"Other non current assets: "<< data[position]->get_other_non_current_assets()<< std::endl;
        std::cout <<"Total non current assets: "<< data[position]->get_total_non_current_assets()<< std::endl;
        std::cout <<"Other asstes"<< data[position]->get_other_assets() << std::endl;
        std::cout <<"Total assets: "<< data[position]->get_total_assets()<< std::endl; 
        std::cout <<"Account payable: "<< data[position]->get_account_payables()<< std::endl;   
        std::cout <<"Short Term debt: "<< data[position]->get_short_term_debt()<< std::endl;
        std::cout <<"Tax payable: "<< data[position]->get_tax_payables() << std::endl;
        std::cout <<"Deferred Revenue: "<< data[position]->get_deferred_revenue()<< std::endl;
        std::cout <<"Other current liabilities: "<< data[position]->get_other_current_liabilities()<< std::endl;
        std::cout <<"Total current liabilities: "<< data[position]->get_total_current_liabilities()<< std::endl;
        std::cout <<"Long term debt: "<< data[position]->get_long_term_Debt()<< std::endl; 
        std::cout <<"Deferred Revenue non current: "<< data[position]->get_deferred_revenue_non_current()<< std::endl;
        std::cout <<"Deferred tax liabilities non current: "<< data[position]->get_deferred_tax_liabilities_non_current()<< std::endl;
        std::cout <<"Other non current liabilities: "<< data[position]->get_other_non_current_liabilities()<< std::endl;
        std::cout <<"Total non current liabilities: "<< data[position]->get_total_non_current_liabilities() << std::endl;
        std::cout <<"Other liabilities: "<< data[position]->get_other_liabilities()<< std::endl; 
        std::cout <<"Capital lease obligations: "<< data[position]->get_capital_lease_obligations()<< std::endl;
        std::cout <<"Total Liabilities: "<< data[position]->get_total_liabilities()<< std::endl;
        std::cout <<"Preffered Stock: "<< data[position]->get_preferred_stock()<< std::endl;
        std::cout <<"Common Stock: "<< data[position]->get_common_stock()<< std::endl;
        std::cout <<"Retained earnings: "<< data[position]->get_retained_earnings()<< std::endl; 
        std::cout <<"Accumulated other Comprehensive income(-loss): "<< data[position]->get_accumulated_other_comprehensive_income_loss()<< std::endl;
        std::cout <<"Other total stockholders equity: "<< data[position]->get_other_total_stockholders_equity()<< std::endl;
        std::cout <<"Total Stockholder equity: "<< data[position]->get_total_stockholders_equity()<< std::endl;
        std::cout <<"Total equity: "<< data[position]->get_total_equity()<< std::endl;
        std::cout <<"Total liabilities: "<< data[position]->get_total_liabilities_and_stockholders_equity()<< std::endl;
        std::cout <<"Minority interest: "<< data[position]->get_minority_interest()<< std::endl; 
        std::cout <<"Total liabilities and total equity: "<< data[position]->get_total_liabilities_and_total_equity()<< std::endl;
        std::cout <<"Total investments: "<< data[position]->get_total_investments()<< std::endl;
        std::cout <<"Total debt: "<< data[position]->get_total_debt()<< std::endl;
        std::cout <<"Net debt: "<< data[position]->get_net_debt()<< std::endl;
     }
    
}


void display_cfs(std::vector<Cashflowstatement*> &data){
    
    
     std::cout << "we have " << data.size() << " "<< data[0]->get_class_name() <<", for the company, "<< data[0]->get_symbol() << std::endl;
    std::cout << "to select the document enter: 0 for the most recent and " << data.size()-1 << " for the oldest." << std::endl;
    
     while(true){
     std::cout << "enter q to exit\n";
     std::cout<< "Position nr: \n";
    
    std::string selector{};
    int position{};
    std::getline(std::cin,selector);
    
    if(is_q(selector)){
        break;
    }else if(is_number(selector)){
          position = std::stoi(selector);
          if(position < 0 || position > data.size()-1){
              std::cout<<"The number is invalid please try again.\n";
              continue;
              }
    }else{
     std::cout<<"the input is not valid please try again.\n"; 
     continue;
    }
     std::cout<< "year: "<< data[position]->get_calendar_year() << " filing date: " << 
             data[position]->get_filling_date() << "." << std::endl; 
        std::cout <<"Net income: "<< data[position]->get_net_income()<< std::endl;
        std::cout <<"Depriciation and amortization: "<< data[position]->get_depreciation_and_amortization()<< std::endl;
        std::cout <<"Deferred income tax: "<< data[position]->get_deferred_income_tax()<< std::endl; 
        std::cout <<"stock based compansation: "<< data[position]->get_stock_based_compensation()<< std::endl;
        std::cout <<"changein working caital: "<< data[position]->get_change_in_working_capital()<< std::endl;
        std::cout <<"Accounts receivable: "<< data[position]->get_accounts_receivables()<< std::endl; 
        std::cout <<"Inventory"<< data[position]->get_inventory()<< std::endl;
        std::cout <<"Accounts payable: "<< data[position]->get_accounts_payables()<< std::endl;
        std::cout <<"Other working capital: "<< data[position]->get_other_working_capital()<< std::endl; 
        std::cout <<"Other non cash items"<< data[position]->get_other_non_cash_items()<< std::endl;
        std::cout <<"Net cash provided by operationactivity: "<< data[position]->get_net_cash_provided_by_operating_activities()<< std::endl;
        std::cout <<"Investemnts in property plant and equipment: "<< data[position]->get_investments_in_property_plant_and_equipment()<< std::endl; 
        std::cout <<"Acquisition net: "<< data[position]->get_acquisitions_net()<< std::endl;
        std::cout <<"Purchases of investments: "<< data[position]->get_purchases_of_investments()<< std::endl;
        std::cout <<"Sales maturities of investments: "<< data[position]->get_sales_maturities_of_investments()<< std::endl; 
        std::cout <<"Other investing activities: "<< data[position]->get_other_investing_activites()<< std::endl;
        std::cout <<"Net cash used for investing activities: "<< data[position]->get_net_cash_used_for_investing_activites()<< std::endl;
        std::cout <<"Debt repayment"<< data[position]->get_debt_repayment()<< std::endl; 
        std::cout <<"Common stock issued: "<< data[position]->get_common_stock_issued()<< std::endl;
        std::cout <<"common stock repurchased"<< data[position]->get_common_stock_repurchased()<< std::endl; 
        std::cout <<"Dividends paid: "<< data[position]->get_dividends_paid()<< std::endl;
        std::cout <<"Other financing activities: "<< data[position]->get_other_financing_activites()<< std::endl; 
        std::cout <<"Net cash used/provided by financing activities: "<< data[position]->get_net_cash_used_provided_by_financing_activities()<< std::endl;
        std::cout <<"Effect of forex changes on cash: "<< data[position]->get_effect_of_forex_changes_on_cash()<< std::endl;
        std::cout <<"Net change in cash"<< data[position]->get_net_change_in_cash()<< std::endl;
        std::cout <<"Cash end of period: "<< data[position]->get_cash_at_end_of_period()<< std::endl; 
        std::cout <<"Cash at beginning of period: "<< data[position]->get_cash_at_beginning_of_period()<< std::endl;
        std::cout <<"Operating cash flow: "<< data[position]->get_operating_cash_flow()<< std::endl; 
        std::cout <<"Ccapex: "<< data[position]->get_capital_expenditure()<< std::endl;
        std::cout <<"Free cash flow: "<< data[position]->get_free_cash_flow()<< std::endl; 

     }
    
}


void display_is(std::vector<Income_statement*> &data){
    
     std::cout << "we have " << data.size() << " "<< data[0]->get_class_name() <<", for the company, "<< data[0]->get_symbol() << std::endl;
    std::cout << "to select the document enter: 0 for the most recent and " << data.size()-1 << " for the oldest." << std::endl;
    
     while(true){
     std::cout << "enter q to exit\n";
     std::cout<< "Position nr: \n";
    
    std::string selector{};
    int position{};
    std::getline(std::cin,selector);
    
    if(is_q(selector)){
        break;
    }else if(is_number(selector)){
          position = std::stoi(selector);
          if(position < 0 || position > data.size()-1){
              std::cout<<"The number is invalid please try again.\n";
              continue;
              }
    }else{
     std::cout<<"the input is not valid please try again.\n" ;  
    }
    
    std::cout<< "year: "<< data[position]->get_calendar_year() << " filing date: " << 
             data[position]->get_filling_date() << "." << std::endl; 
    std::cout <<"Revenue: "<< data[position]->get_revenue() << std::endl;
    std::cout <<"Cost of revenue: "<< data[position]->get_cost_of_revenue() << std::endl;
    std::cout <<"Gross Profit: "<< data[position]->get_gross_profit()<< std::endl;
    std::cout <<"Gross Profit ratio: "<< data[position]->get_gross_profit_ratio()<< std::endl;
    std::cout <<"R&D: "<< data[position]->get_research_and_development_expenses()<< std::endl;
    std::cout <<"General and Admin expenses: "<< data[position]->get_general_and_administrative_expenses()<< std::endl;
    std::cout <<"Selling and Marketing expenses: "<< data[position]->get_selling_and_marketing_expenses()<< std::endl;
    std::cout <<"Selling general and admin expenses: "<< data[position]->get_selling_general_and_administrative_expenses()<< std::endl;
    std::cout <<"Other Expenses: "<< data[position]->get_other_expenses()<< std::endl;
    std::cout <<"Operating Expenses"<< data[position]->get_operating_expenses()<< std::endl;
    std::cout <<"Cost and Expenses"<< data[position]->get_cost_and_expenses()<< std::endl;
    std::cout <<"Interest income: "<< data[position]->get_interest_income()<< std::endl;  
    std::cout <<"Interest expenses: "<< data[position]->get_interest_expense()<< std::endl;
    std::cout <<"Depreciation and amortization: "<< data[position]->get_depreciation_and_amortization()<< std::endl;
    std::cout <<"EBITDA: "<< data[position]->get_ebitda()<< std::endl;
    std::cout <<"EBITDA ratio:"<< data[position]->get_ebitda_ratio()<< std::endl;
    std::cout <<"Operating Income: "<< data[position]->get_operating_income()<< std::endl;
    std::cout <<"Operating income ratio: "<< data[position]->get_operating_income_ratio()<< std::endl;
    std::cout <<"Total Other Income expenses net: "<< data[position]->get_total_other_income_expensesNet()<< std::endl;
    std::cout <<"Income before Taxes: "<< data[position]->get_income_before_tax()<< std::endl;
    std::cout <<"Income Before taxes ratio: "<< data[position]->get_income_before_tax_ratio()<< std::endl;
    std::cout <<"Net income"<< data[position]->get_net_income()<< std::endl;
    std::cout <<"Net income Ratio: "<< data[position]->get_net_income_ratio()<< std::endl;
    std::cout <<"Eps: "<< data[position]->get_eps()<< std::endl; 
    std::cout <<"Eps diluted: "<< data[position]->get_eps_diluted()<< std::endl;
    std::cout <<"Weighted average shares oustanding: "<< data[position]->get_weighted_average_shs_out()<< std::endl;
    std::cout <<"Weighted avarage shares oustanding ndiluted: "<< data[position]->get_weighted_average_dhs_out_dil()<< std::endl;
     }    
}


void display_rt(std::vector<Key_ratios*> &data){
       
     std::cout << "we have " << data.size() << " "<< data[0]->get_class_name() <<", for the company, "<< data[0]->get_symbol() << std::endl;
    std::cout << "to select the document enter: 0 for the most recent and " << data.size()-1 << " for the oldest." << std::endl;
    
     while(true){
     std::cout << "enter q to exit/n";
     std::cout<< "Position nr: \n";
    
    std::string selector{};
    int position{};
    std::getline(std::cin,selector);
    
    if(is_q(selector)){
        break;
    }else if(is_number(selector)){
          position = std::stoi(selector);
          if(position < 0 || position > data.size()-1){
              std::cout<<"The number is invalid please try again./n";
              continue;
              }
    }else{
     std::cout<<"the input is not valid please try again.\n" ; 
     continue; 
    } 
   
    std::cout <<"Revenue per share: "<< data[position]->get_revenue_per_share()<< std::endl;
    std::cout <<"Net income per share: "<< data[position]->get_net_income_per_share()<< std::endl;
    std::cout <<"Operating cash flow per share: "<< data[position]->get_operating_cash_flow_per_share()<< std::endl;
    std::cout <<"Free cash flow per share: "<< data[position]->get_free_cash_flow_per_share()<< std::endl;
    std::cout <<"Cash per share: "<< data[position]->get_cash_per_share()<< std::endl;
    std::cout <<"Book value per share: "<< data[position]->get_book_value_per_share()<< std::endl; 
    std::cout <<"Tangible book value per share: "<< data[position]->get_tangible_book_value_per_share()<< std::endl;
    std::cout <<"Shareholders equity per share: "<< data[position]->get_shareholders_equity_per_share()<< std::endl;
    std::cout <<"Interset debt per share: "<< data[position]->get_interest_debt_per_share()<< std::endl;
    std::cout <<"Market cap: "<< data[position]->get_market_cap()<< std::endl;
    std::cout <<"Enterprise value: "<< data[position]->get_enterprise_value()<< std::endl;
    std::cout <<"P/E: "<< data[position]->get_pe_ratio()<< std::endl; 
    std::cout <<"Price to sales: "<< data[position]->get_price_to_sales_ratio()<< std::endl;
    std::cout <<"POCF ratio: "<< data[position]->get_pocf_ratio()<< std::endl;
    std::cout <<"PFCF ratio: "<< data[position]->get_pfcf_ratio()<< std::endl;
    std::cout <<"PB ratio: "<< data[position]->get_pb_ratio()<< std::endl;
    std::cout <<"PTB ratio:"<< data[position]->get_ptb_ratio()<< std::endl;
    std::cout <<"EV to sales: "<< data[position]->get_ev_to_sales()<< std::endl; 
    std::cout <<"enterprise value/ EBITDA: "<< data[position]->get_enterprise_value_over_EBITDA()<< std::endl;
    std::cout <<"Ev to operating cash flow: "<< data[position]->get_ev_to_operating_cash_flow()<< std::endl;
    std::cout <<"Ev to free cash: "<< data[position]->get_ev_to_free_cash_flow()<< std::endl;
    std::cout <<"Earnings yield"<< data[position]->get_earnings_yield()<< std::endl;
    std::cout <<"Free Cash flow yield: "<< data[position]->get_free_cash_flow_yield()<< std::endl;
    std::cout <<"Debt to equity: "<< data[position]->get_debt_to_equity()<< std::endl; 
    std::cout <<"Debt to asset: "<< data[position]->get_debt_to_assets()<< std::endl;
    std::cout <<"Debt to EBITDA: "<< data[position]->get_net_debt_to_EBITDA()<< std::endl;
    std::cout <<"Current Ratio: "<< data[position]->get_current_ratio()<< std::endl;
    std::cout <<"Interest Coverage: "<< data[position]->get_interest_coverage()<< std::endl;
    std::cout <<"Income quality: "<< data[position]->get_income_quality()<< std::endl;
    std::cout <<"dividend yield: "<< data[position]->get_dividend_yield()<< std::endl;
    std::cout <<"Payout ratio: "<< data[position]->get_payout_ratio()<< std::endl;
    std::cout <<"Sga to revenue: "<< data[position]->get_sga_to_revenue()<< std::endl;
    std::cout <<"RND to revenue: "<< data[position]->get_rnd_to_revenue()<< std::endl;
    std::cout <<"Intangibles to Total assets: "<< data[position]->get_intangibles_to_total_assets()<< std::endl;
    std::cout <<"Capex to operating cash flow: "<< data[position]->get_capex_to_operating_cash_flow()<< std::endl; 
    std::cout <<"Capex to revenue: "<< data[position]->get_capex_to_revenue()<< std::endl;
    std::cout <<"Capex to depriciation: "<< data[position]->get_capex_to_depreciation()<< std::endl;
    std::cout <<"Stock based compensation to revenue: "<< data[position]->get_stock_based_compensation_to_revenue()<< std::endl;
    std::cout <<"Graham number"<< data[position]->get_graham_number()<< std::endl;
    std::cout <<"ROIC : "<< data[position]->get_roic()<< std::endl;  
    std::cout <<"Return on tangible assets: "<< data[position]->get_return_on_tangible_assets()<< std::endl;  
    std::cout <<"Graham net net :"<< data[position]->get_graham_net_net()<< std::endl;  
    std::cout <<"Working Capital: "<< data[position]->get_working_capital()<< std::endl;  
    std::cout <<"Tangible asset value: "<< data[position]->get_tangible_asset_value()<< std::endl;  
    std::cout <<"net current asset value: "<< data[position]->get_net_current_asset_value()<< std::endl;  
    std::cout <<"Invested capital: "<< data[position]->get_invested_capital()<< std::endl;  
    std::cout <<"average receivables: "<< data[position]->get_average_receivables()<< std::endl;  
    std::cout <<"Average payables: "<< data[position]->get_average_payables()<< std::endl;  
    std::cout <<"Average inventory: "<< data[position]->get_average_inventory()<< std::endl;  
    std::cout <<"days sales outtstanding: "<< data[position]->get_days_sales_outstanding()<< std::endl;  
    std::cout <<"days payable outstanding: "<< data[position]->get_days_payables_outstanding()<< std::endl;  
    std::cout <<"days inventory on hand: "<< data[position]->get_days_of_inventory_on_hand()<< std::endl;  
    std::cout <<"Receivables turn over: "<< data[position]->get_receivables_turnover()<< std::endl;  
    std::cout <<"payables turnover: "<< data[position]->get_payables_turnover()<< std::endl;  
    std::cout <<"Inventory turnover: "<< data[position]->get_inventory_turnover()<< std::endl;
    std::cout <<"ROE: "<< data[position]->get_roe()<< std::endl;
    std::cout <<"CAPEX per share: "<< data[position]->get_capex_per_share()<< std::endl;   
       }
}








#endif