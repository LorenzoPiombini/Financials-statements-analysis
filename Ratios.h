#ifndef _RATIOS_H_
#define _RATIOS_H_


#include <iostream>
#include "Response.h"

long long helper_revenue_val(Response resp){
   return   resp.get_financials().get_income_statement().get_revenues().value;
}

double gross_margin(Response resp){   
    long long grossProfit = resp.get_financials().get_income_statement().get_gross_profit().value;
    long long  revenue = helper_revenue_val(resp);
    
    if(revenue ==0){return 0;}
    
    double gross_margin_val = static_cast<double>(grossProfit)/revenue;
    return gross_margin_val*100;
}

double net_profit_margin(Response resp){
    
     long long  revenue = helper_revenue_val(resp); 
     
     long long expenses = resp.get_financials().get_income_statement().get_selling_general_and_administrative_expenses().value + 
                          resp.get_financials().get_income_statement().get_operating_expenses().value + 
                          resp.get_financials().get_income_statement().get_cost_of_revenue().value+ 
                          resp.get_financials().get_income_statement().get_income_tax_expense_benefit().value+
                          resp.get_financials().get_income_statement().get_interest_expense_operating().value+ 
                          resp.get_financials().get_income_statement().get_research_and_development().value; 

        if(revenue == 0) {
            return 0;
            
        }
        
        long long net_income= revenue -  expenses;
        double net_profit_margin = static_cast<double>(net_income)/revenue;
        
        return net_profit_margin*100;
    
    
    }

        
       

double operating_profit_margin(Response resp){
     long long revenue = helper_revenue_val(resp);
     //earnings before interest and taxes
     long long ebit = resp.get_financials().get_income_statement().get_operating_income_loss().value;
     
     return (static_cast<double>(ebit)/revenue)*100;
    
    }

double pre_tax_profit_margin(Response resp){
    
    long long revenue = helper_revenue_val(resp);
    long long ebt = resp.get_financials().get_income_statement().get_income_loss_from_continuing_operations_before_tax().value;
    
    return (static_cast<double>(ebt)/revenue)*100;
    }

#endif