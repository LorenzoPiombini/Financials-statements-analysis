#include "Financials.h"
#include <iostream>
#include <memory>
#include "nlohmann/json.hpp"


Balancesheet Financials::get_balance_sheet(){
    return balance_sheet;
}
Incomestatement Financials::get_income_statement(){
    return income_statement;
}
Cashflowstatement Financials::get_cash_flows_statement(){
    return cash_flows_statement;
}
Comprehensiveincome Financials::get_comprehensive_income(){
    return comprehensive_income;
}

void from_json(const nlohmann::json &j, Financials &f){
    j.at("balance_sheet").get_to(f.balance_sheet);
    
    if(j.contains("income_statement") && !j["income_statement"].is_null()){
        f.income_statement = Incomestatement();
        j.at("income_statement").get_to(f.income_statement);
    } 
    
    if(j.contains("cash_flows_tatement") && !j["cash_flows_tatement"].is_null()){
        f.cash_flows_statement = Cashflowstatement();   
        j.at("cash_flows_tatement").get_to(f.cash_flows_statement);
    } 
    
    if(j.contains("comprehensive_income") && !j["comprehensive_income"].is_null()){
            f.comprehensive_income = Comprehensiveincome();
            j.at("comprehensive_income").get_to(f.comprehensive_income);
    } 
    
    
    

    
}