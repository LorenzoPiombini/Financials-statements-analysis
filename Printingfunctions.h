#ifndef _PRINTINGFUNCTIONS_H_
#define _PRINTINGFUNCTIONS_H_

#include <iostream>
#include <vector>
#include "Response.h"
#include "Ratios.h"

using std::cout;
using std::vector;

void print_income_statement(vector<Response> responses){
     
         
     for(size_t i{0}; i < responses.size(); ++i){
        cout << "\nFiscal period: "<< responses[i].get_fiscal_period()<< ", Year : "<< responses[i].get_fiscal_year() <<"\n";
        cout << "Net income loss: "<< responses[i].get_financials().get_income_statement().get_net_income_loss().value << "\n";
        cout << "Gross profit: " << responses[i].get_financials().get_income_statement().get_gross_profit().value << "\n";
        cout << "Income loss from continuing operations after tax: " << responses[i].get_financials().get_income_statement().get_income_loss_from_continuing_operations_after_tax().value << "\n";
        cout << "Income loss from continuing operations before tax: " << responses[i].get_financials().get_income_statement().get_income_loss_from_continuing_operations_before_tax().value << "\n";
        cout << "Net income loss attributable to noncontrolling interest: " << responses[i].get_financials().get_income_statement().get_net_income_loss_attributable_to_noncontrolling_interest().value << "\n";
        cout << "Net income loss attributable to parent: " << responses[i].get_financials().get_income_statement().get_net_income_loss_attributable_to_parent().value << "\n";
        cout << "Income loss from continuing operations after tax: " << responses[i].get_financials().get_income_statement().get_income_loss_from_continuing_operations_after_tax().value << "\n";
        cout << "Basic average shares: " << responses[i].get_financials().get_income_statement().get_basic_average_shares().value << "\n";
        cout << "Non operating income loss: " << responses[i].get_financials().get_income_statement().get_nonoperating_income_loss().value << "\n";
        cout << "Net income loss available to common stockholders basic:" << responses[i].get_financials().get_income_statement().get_net_income_loss_available_to_common_stockholders_basic().value << "\n";
        cout << "Benefits Costs Expenses: " << responses[i].get_financials().get_income_statement().get_benefits_costs_expenses().value << "\n";
        cout << "Income tax expense benefit: " << responses[i].get_financials().get_income_statement().get_income_tax_expense_benefit().value << "\n";
        cout << "Operating income loss: " << responses[i].get_financials().get_income_statement().get_operating_income_loss().value << "\n";
        cout << "Diluted earnings per share:" << responses[i].get_financials().get_income_statement().get_diluted_earnings_per_share().value << "\n";
        cout << "Cost of revenue: " << responses[i].get_financials().get_income_statement().get_cost_of_revenue().value << "\n";
        cout << "Diluted average shares: " << responses[i].get_financials().get_income_statement().get_diluted_average_shares().value << "\n";
        cout << "Revenues: " << responses[i].get_financials().get_income_statement().get_revenues().value << "\n";
        cout << "Preferred stock dividends and other adjustments:" << responses[i].get_financials().get_income_statement().get_preferred_stock_dividends_and_other_adjustments().value << "\n";
        cout << "Operating expenses: " << responses[i].get_financials().get_income_statement().get_operating_expenses().value << "\n";
        cout << "Costs and Expenses: " << responses[i].get_financials().get_income_statement().get_costs_and_expenses().value << "\n";
        cout << "Basic earnings per share:" << responses[i].get_financials().get_income_statement().get_basic_earnings_per_share().value << "\n";
        cout << "Interest expense operating:" << responses[i].get_financials().get_income_statement().get_interest_expense_operating().value << "\n";
        cout << "Research and development:" << responses[i].get_financials().get_income_statement().get_research_and_development().value << "\n";
        cout << "Participating securities distributed and undistributed earnings loss basic: " << responses[i].get_financials().get_income_statement().get_participating_securities_distributed_and_undistributed_earnings_loss_basic().value << "\n";
        cout << "Selling general and administrative expenses: " << responses[i].get_financials().get_income_statement().get_selling_general_and_administrative_expenses().value << "\n";
        
     }
     

     
    

    
}


void print_income_statement_ratios(vector<Response> responses){
      
    for(size_t i{0}; i< responses.size(); ++i){
        cout << "\nFiscal period: "<< responses[i].get_fiscal_period()<< ", Year : "<< responses[i].get_fiscal_year() <<"\n";
        cout << "Gross Margin: " << gross_margin(responses[i]) << "\n";
        cout << "Net Profit: " << net_profit_margin(responses[i]) << "\n";
        cout << "Operating profit margin: "<< operating_profit_margin(responses[i]) << "\n";
        cout << "Pre-tax profit margin: " << pre_tax_profit_margin(responses[i]) << "\n";
    }

}



#endif