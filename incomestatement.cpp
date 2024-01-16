#include "Incomestatement.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <string>

std::string Income_statement::get_date() const {
    return date;
}
std::string Income_statement::get_symbol() const {
    return symbol;
    
}
std::string Income_statement::get_reported_currency() const {
    return reportedCurrency;
}
std::string Income_statement::get_cik()const{
    return cik;
}
std::string Income_statement::get_filling_date() const{
    return fillingDate;
}

std::string Income_statement::get_accepted_date()const {
    return acceptedDate;
}
std::string Income_statement::get_calendar_year()const{
    return calendarYear;
}
std::string Income_statement::get_period()const{
    return period;
}
long long Income_statement::get_revenue()const{
    return revenue;
}
long long Income_statement::get_cost_of_revenue()const{
    return costOfRevenue;
}
long long Income_statement::get_gross_profit()const{
    return grossProfit;
}
double Income_statement::get_gross_profit_ratio()const{
    return grossProfitRatio;
}
long long Income_statement::get_research_and_development_expenses()const{
    return researchAndDevelopmentExpenses;
}
long long Income_statement::get_general_and_administrative_expenses()const{
    return generalAndAdministrativeExpenses;
}
long long Income_statement::get_selling_and_marketing_expenses()const{
    return sellingAndMarketingExpenses;
}
long long Income_statement::get_selling_general_and_administrative_expenses()const{
    return sellingGeneralAndAdministrativeExpenses;
    
}
long long Income_statement::get_other_expenses()const{
    return otherExpenses;
}
long long Income_statement::get_operating_expenses()const{
    return operatingExpenses;
}
long long Income_statement::get_cost_and_expenses()const{
    return costAndExpenses;
}
long long Income_statement::get_interest_income()const{
    return interestIncome;
}
long long Income_statement::get_interest_expense()const{
    return interestExpense;
}
long long Income_statement::get_depreciation_and_amortization()const{
    return depreciationAndAmortization;
}
long long Income_statement::get_ebitda()const{
    return ebitda;
}
double Income_statement::get_ebitda_ratio()const{
    return ebitdaratio;
}
long long Income_statement::get_operating_income()const{
    return operatingIncome;
}
double Income_statement::get_operating_income_ratio()const{
    return operatingIncomeRatio;
}
long long Income_statement::get_total_other_income_expensesNet()const{
    return totalOtherIncomeExpensesNet;
}
long long Income_statement::get_income_before_tax()const{
    return  incomeBeforeTax;
}
double Income_statement::get_income_before_tax_ratio()const{
    return incomeBeforeTaxRatio;
}
long long Income_statement::get_income_tax_expense()const{
    return incomeTaxExpense;
}
long long Income_statement::get_net_income()const{
    return netIncome;
}
long long Income_statement::get_net_income_ratio()const{
    return netIncomeRatio;
}
double  Income_statement::get_eps()const{
    return eps;
}
double Income_statement::get_eps_diluted()const{
    return epsdiluted;
}
long long Income_statement::get_weighted_average_shs_out()const{
    return weightedAverageShsOut;
}

long long  Income_statement::get_weighted_average_dhs_out_dil()const{
    return weightedAverageShsOutDil;
}

std::string Income_statement::get_link()const{
    return link;
}

std::string Income_statement::get_finalLink()const{
    return finalLink;
}

void from_json(const nlohmann::json &j, Income_statement &i){
  
    if(j.contains("date") && !j["date"].empty()){
          j.at("date").get_to(i.date);
    } else {
          i.date = "none";
    }
  
   if(j.contains("symbol") && !j["symbol"].empty()){
          j.at("symbol").get_to(i.symbol);
    } else {
          i.symbol = "none";
    }
  
  
  if(j.contains("reportedCurrency") && !j["reportedCurrency"].empty()){
          j.at("reportedCurrency").get_to(i.reportedCurrency);
   }else{
          i.reportedCurrency = "none";
   }
  
  
  if(j.contains("cik") && !j["cik"].empty()){
     j.at("cik").get_to(i.cik);
   } else {
     i.cik = "none";
  }
  
  
  if(j.contains("fillingDate") && !j["fillingDate"].empty()){
        j.at("fillingDate").get_to(i.fillingDate);
   } else {
        i.fillingDate = "none";
   }
  
  if(j.contains("acceptedDate") && !j["acceptedDate"].empty()){
       j.at("acceptedDate").get_to(i.acceptedDate);
   } else {
       i.acceptedDate = "none";
   }
 
  
   if(j.contains("calendarYear") && !j["calendarYear"].empty()){
          j.at("calendarYear").get_to(i.calendarYear);
    } else {
          i.calendarYear = "none";
    }
  
   if(j.contains("period") && !j["period"].empty()){
          j.at("period").get_to(i.period);
    } else {
          i.period = "none";
    }
  
  
  if(j.contains("revenue") && !j["revenue"].empty()){
          j.at("revenue").get_to(i.revenue);
   }else{
          i.revenue = 0;
   }
  
  
  if(j.contains("costOfRevenue") && !j["costOfRevenue"].empty()){
     j.at("costOfRevenue").get_to(i.costOfRevenue);
   } else {
     i.costOfRevenue = 0;
  }
  
  
  if(j.contains("grossProfit") && !j["grossProfit"].empty()){
        j.at("grossProfit").get_to(i.grossProfit);
   } else {
        i.grossProfit = 0;
   }
  
  if(j.contains("grossProfitRatio") && !j["grossProfitRatio"].empty()){
       j.at("grossProfitRatio").get_to(i.grossProfitRatio);
   } else {
       i.grossProfitRatio = 0.0;
   }
 
  
  if(j.contains("researchAndDevelopmentExpenses") && !j["researchAndDevelopmentExpenses"].empty()){
        j.at("researchAndDevelopmentExpenses").get_to(i.researchAndDevelopmentExpenses);
  }else {
        i.researchAndDevelopmentExpenses = 0;
  }
  
   if(j.contains("generalAndAdministrativeExpenses") && !j["generalAndAdministrativeExpenses"].empty()){
          j.at("generalAndAdministrativeExpenses").get_to(i.generalAndAdministrativeExpenses);
    } else {
          i.generalAndAdministrativeExpenses = 0;
    }
  
   if(j.contains("sellingAndMarketingExpenses") && !j["sellingAndMarketingExpenses"].empty()){
          j.at("sellingAndMarketingExpenses").get_to(i.sellingAndMarketingExpenses);
    } else {
          i.sellingAndMarketingExpenses = 0;
    }
  
  
  if(j.contains("sellingGeneralAndAdministrativeExpenses") && !j["sellingGeneralAndAdministrativeExpenses"].empty()){
          j.at("sellingGeneralAndAdministrativeExpenses").get_to(i.sellingGeneralAndAdministrativeExpenses);
   }else{
          i.sellingGeneralAndAdministrativeExpenses = 0;
   }
  
  
  if(j.contains("operatingExpenses") && !j["operatingExpenses"].empty()){
     j.at("operatingExpenses").get_to(i.operatingExpenses);
   } else {
     i.operatingExpenses = 0;
  }
  
  
  if(j.contains("otherExpenses") && !j["otherExpenses"].empty()){
        j.at("otherExpenses").get_to(i.otherExpenses);
   } else {
        i.otherExpenses = 0;
   }
  
  if(j.contains("costAndExpenses") && !j["costAndExpenses"].empty()){
       j.at("costAndExpenses").get_to(i.costAndExpenses);
   } else {
       i.costAndExpenses = 0;
   }
 
  
  if(j.contains("interestIncome") && !j["interestIncome"].empty()){
        j.at("interestIncome").get_to(i.interestIncome);
  }else {
        i.interestIncome = 0;
  }
  
    if(j.contains("interestExpense") && !j["interestExpense"].empty()){
        j.at("interestExpense").get_to(i.interestExpense);
  }else {
        i.interestExpense = 0;
  }
    if(j.contains("depreciationAndAmortization") && !j["depreciationAndAmortization"].empty()){
        j.at("depreciationAndAmortization").get_to(i.depreciationAndAmortization);
  }else {
        i.depreciationAndAmortization = 0;
  }
    if(j.contains("ebitda") && !j["ebitda"].empty()){
        j.at("ebitda").get_to(i.ebitda);
  }else {
        i.ebitda = 0;
  }
    if(j.contains("ebitdaratio") && !j["ebitdaratio"].empty()){
        j.at("ebitdaratio").get_to(i.ebitdaratio);
  }else {
        i.ebitdaratio = 0.0;
  }
    if(j.contains("operatingIncome") && !j["operatingIncome"].empty()){
        j.at("operatingIncome").get_to(i.operatingIncome);
  }else {
       i.operatingIncome = 0; 
  }
    if(j.contains("operatingIncomeRatio") && !j["operatingIncomeRatio"].empty()){
        j.at("operatingIncomeRatio").get_to(i.operatingIncomeRatio);
  }else {
        i.operatingIncomeRatio = 0.0;
  } 

 if(j.contains("totalOtherIncomeExpensesNet") && !j["totalOtherIncomeExpensesNet"].empty()){
        j.at("totalOtherIncomeExpensesNet").get_to(i.totalOtherIncomeExpensesNet);
  }else {
        i.totalOtherIncomeExpensesNet = 0;
  }  
  if(j.contains("incomeBeforeTax") && !j["incomeBeforeTax"].empty()){
        j.at("incomeBeforeTax").get_to(i.incomeBeforeTax);
  }else {
        i.incomeBeforeTax = 0;
  }  
  
  if(j.contains("incomeBeforeTaxRatio") && !j["incomeBeforeTaxRatio"].empty()){
        j.at("incomeBeforeTaxRatio").get_to(i.incomeBeforeTaxRatio);
  }else {
        i.incomeBeforeTaxRatio = 0;
  }  
  if(j.contains("incomeTaxExpense") && !j["incomeTaxExpense"].empty()){
        j.at("incomeTaxExpense").get_to(i.incomeTaxExpense);
  }else {
        i.incomeTaxExpense = 0;
  } 
  
  if(j.contains("netIncome") && !j["netIncome"].empty()){
        j.at("netIncome").get_to(i.netIncome);
  }else {
        i.netIncome = 0;
  }  
  if(j.contains("netIncomeRatio") && !j["netIncomeRatio"].empty()){
        j.at("netIncomeRatio").get_to(i.netIncomeRatio);
  }else {
        i.netIncomeRatio = 0.0;
  }  
  if(j.contains("eps") && !j["eps"].empty()){
        j.at("eps").get_to(i.eps);
  }else {
        i.eps = 0.0;
  }  
  if(j.contains("epsdiluted") && !j["epsdiluted"].empty()){
        j.at("epsdiluted").get_to(i.epsdiluted);
  }else {
        i.epsdiluted = 0.0;
  }
    if(j.contains("weightedAverageShsOut") && !j["weightedAverageShsOut"].empty()){
        j.at("weightedAverageShsOut").get_to(i.weightedAverageShsOut);
  }else {
        i.weightedAverageShsOut = 0;
  }
  
  if(j.contains("weightedAverageShsOutDil") && !j["weightedAverageShsOutDil"].empty()){
        j.at("weightedAverageShsOutDil").get_to(i.weightedAverageShsOutDil);
  }else {
        i.weightedAverageShsOutDil = 0;
  }
  if(j.contains("link") && !j["link"].empty()){
        j.at("link").get_to(i.link);
  }else {
        i.link = "none";
  }
  if(j.contains("finalLink") && !j["finalLink"].empty()){
        j.at("finalLink").get_to(i.finalLink);
  }else {
        i.finalLink = "none";
  }
  
  
}


std::string Income_statement::get_class_name()const{
    return "income_statement";  
}

std::string Income_statement::create_file_name(std::string ticker)const{
    if(ticker.size()==0){
        return  symbol + "_" + get_class_name() +".bin";
    } else {
        return  ticker + "_" + get_class_name() +".bin";    
    }
             
}

void Income_statement::save_to_file(std::ofstream &out){
     //(create_file_name(""), std::ios::binary | std::ios::app);
    
     size_t date_len = date.size();
     out.write(reinterpret_cast<const char*>(&date_len), sizeof(date_len));
     out.write(date.c_str(), date_len);
     
      size_t symbol_len = symbol.size();
   out.write(reinterpret_cast<const char*>(&symbol_len), sizeof(symbol_len));
   out.write(symbol.c_str(), symbol_len);
    
     size_t reported_currency_len = reportedCurrency.size();
   out.write(reinterpret_cast<const char*>(&reported_currency_len), sizeof(reported_currency_len));
   out.write(reportedCurrency.c_str(), reported_currency_len);
    
     size_t cik_len = cik.size();
   out.write(reinterpret_cast<const char*>(&cik_len), sizeof(cik_len));
   out.write(cik.c_str(), cik_len);
    
     size_t filling_date_len = fillingDate.size();
   out.write(reinterpret_cast<const char*>(&filling_date_len), sizeof(filling_date_len));
   out.write(fillingDate.c_str(), filling_date_len);
    
     size_t accepted_date_len = acceptedDate.size();
   out.write(reinterpret_cast<const char*>(&accepted_date_len), sizeof(accepted_date_len));
   out.write(acceptedDate.c_str(), accepted_date_len);
   
   
     size_t calendar_year_len = calendarYear.size();
   out.write(reinterpret_cast<const char*>(&calendar_year_len), sizeof(calendar_year_len));
   out.write(calendarYear.c_str(), calendar_year_len);
    
     size_t period_len = period.size();
   out.write(reinterpret_cast<const char*>(&period_len), sizeof(period_len));
   out.write(period.c_str(), period_len);
   
   out.write(reinterpret_cast<const char*>(&revenue), sizeof(revenue));
   out.write(reinterpret_cast<const char*>(&costOfRevenue), sizeof(costOfRevenue));
   out.write(reinterpret_cast<const char*>(&grossProfit), sizeof(grossProfit));
   out.write(reinterpret_cast<const char*>(&grossProfitRatio), sizeof(grossProfitRatio));
   out.write(reinterpret_cast<const char*>(&researchAndDevelopmentExpenses), sizeof(researchAndDevelopmentExpenses));
   out.write(reinterpret_cast<const char*>(&generalAndAdministrativeExpenses), sizeof(generalAndAdministrativeExpenses));
   out.write(reinterpret_cast<const char*>(&sellingAndMarketingExpenses), sizeof(sellingAndMarketingExpenses));
   out.write(reinterpret_cast<const char*>(&sellingGeneralAndAdministrativeExpenses), sizeof(sellingGeneralAndAdministrativeExpenses));
   out.write(reinterpret_cast<const char*>(&otherExpenses), sizeof(otherExpenses));
   out.write(reinterpret_cast<const char*>(&costAndExpenses), sizeof(costAndExpenses));
   out.write(reinterpret_cast<const char*>(&interestIncome), sizeof(interestIncome));
   out.write(reinterpret_cast<const char*>(&interestExpense), sizeof(interestExpense));
   out.write(reinterpret_cast<const char*>(&depreciationAndAmortization), sizeof(depreciationAndAmortization));
   out.write(reinterpret_cast<const char*>(&ebitda), sizeof(ebitda));
   out.write(reinterpret_cast<const char*>(&ebitdaratio), sizeof(ebitdaratio));
   out.write(reinterpret_cast<const char*>(&operatingIncome), sizeof(operatingIncome));
   out.write(reinterpret_cast<const char*>(&operatingIncomeRatio), sizeof(operatingIncomeRatio));
   out.write(reinterpret_cast<const char*>(&totalOtherIncomeExpensesNet), sizeof(totalOtherIncomeExpensesNet));
   out.write(reinterpret_cast<const char*>(&incomeBeforeTax), sizeof(incomeBeforeTax));
   out.write(reinterpret_cast<const char*>(&incomeBeforeTaxRatio), sizeof(incomeBeforeTaxRatio));
   out.write(reinterpret_cast<const char*>(&incomeTaxExpense), sizeof(incomeTaxExpense));
   out.write(reinterpret_cast<const char*>(&netIncome), sizeof(netIncome));
   out.write(reinterpret_cast<const char*>(&netIncomeRatio), sizeof(netIncomeRatio));
   out.write(reinterpret_cast<const char*>(&eps), sizeof(eps));
   out.write(reinterpret_cast<const char*>(&epsdiluted), sizeof(epsdiluted));
   out.write(reinterpret_cast<const char*>(&weightedAverageShsOut), sizeof(weightedAverageShsOut));
   out.write(reinterpret_cast<const char*>(&weightedAverageShsOutDil), sizeof(weightedAverageShsOutDil));
   
   size_t link_size = link.size();
   out.write(reinterpret_cast<const char*>(&link_size), sizeof(link_size));
   out.write(link.c_str(), sizeof(link_size));
        
   size_t final_link_size = finalLink.size();
   out.write(reinterpret_cast<const char*>(&final_link_size), sizeof(final_link_size));
   out.write(finalLink.c_str(), sizeof(final_link_size));
          
   //out.close();
 
}


void Income_statement::read_from_file(std::ifstream &in){
//      std::ifstream in (create_file_name(ticker), std::ios::binary);
//    
//    if(!in){
//        std::cout << "I could not open the file " + create_file_name(ticker);
//        return;
//    }
//    
     size_t date_len;
     in.read(reinterpret_cast<char*>(&date_len), sizeof(date_len));
     std::string date(date_len, '\0');
     in.read(&date[0],date_len);
     
     size_t symbol_len;
     in.read(reinterpret_cast<char*>(&symbol_len), sizeof(symbol_len));
     std::string symbol(symbol_len, '\0');
     in.read(&symbol[0],symbol_len);
    
     size_t reported_currency_len;
     in.read(reinterpret_cast<char*>(&reported_currency_len), sizeof(reported_currency_len));
     std::string reportedCurrency(reported_currency_len,'\0');
     in.read(&reportedCurrency[0], reported_currency_len);
    
     size_t cik_len;
     in.read(reinterpret_cast<char*>(&cik_len), sizeof(cik_len));
     std::string cik (cik_len,'\0');
     in.read(&cik[0],cik_len);
    
     size_t filling_date_len;
     in.read(reinterpret_cast<char*>(&filling_date_len), sizeof(filling_date_len));
     std::string fillingDate (filling_date_len,'\0');
     in.read(&fillingDate[0],filling_date_len);
    
     size_t accepted_date_len;
     in.read(reinterpret_cast<char*>(&accepted_date_len), sizeof(accepted_date_len));
     std::string acceptedDate(accepted_date_len,'\0');
     in.read(&acceptedDate[0],accepted_date_len);
   
   
     size_t calendar_year_len;
     in.read(reinterpret_cast<char*>(&calendar_year_len), sizeof(calendar_year_len));
     std::string calendarYear(calendar_year_len,'\0');
     in.read(&calendarYear[0], calendar_year_len);
    
     size_t period_len;
     in.read(reinterpret_cast<char*>(&period_len), sizeof(period_len));
     std::string period(period_len,'\0');
     in.read(&period[0],period_len);
      
     in.read(reinterpret_cast<char*>(&revenue), sizeof(revenue));
     in.read(reinterpret_cast<char*>(&costOfRevenue), sizeof(costOfRevenue));
     in.read(reinterpret_cast<char*>(&grossProfit), sizeof(grossProfit));
     in.read(reinterpret_cast<char*>(&grossProfitRatio), sizeof(grossProfitRatio));
     in.read(reinterpret_cast<char*>(&researchAndDevelopmentExpenses), sizeof(researchAndDevelopmentExpenses));
     in.read(reinterpret_cast<char*>(&generalAndAdministrativeExpenses), sizeof(generalAndAdministrativeExpenses));
     in.read(reinterpret_cast<char*>(&sellingAndMarketingExpenses), sizeof(sellingAndMarketingExpenses));
     in.read(reinterpret_cast<char*>(&sellingGeneralAndAdministrativeExpenses), sizeof(sellingGeneralAndAdministrativeExpenses));
     in.read(reinterpret_cast<char*>(&otherExpenses), sizeof(otherExpenses));
     in.read(reinterpret_cast<char*>(&costAndExpenses), sizeof(costAndExpenses));
     in.read(reinterpret_cast<char*>(&interestIncome), sizeof(interestIncome));
     in.read(reinterpret_cast<char*>(&interestExpense), sizeof(interestExpense));
     in.read(reinterpret_cast<char*>(&depreciationAndAmortization), sizeof(depreciationAndAmortization));
     in.read(reinterpret_cast<char*>(&ebitda), sizeof(ebitda));
     in.read(reinterpret_cast<char*>(&ebitdaratio), sizeof(ebitdaratio));
     in.read(reinterpret_cast<char*>(&operatingIncome), sizeof(operatingIncome));
     in.read(reinterpret_cast<char*>(&operatingIncomeRatio), sizeof(operatingIncomeRatio));
     in.read(reinterpret_cast<char*>(&totalOtherIncomeExpensesNet), sizeof(totalOtherIncomeExpensesNet));
     in.read(reinterpret_cast<char*>(&incomeBeforeTax), sizeof(incomeBeforeTax));
     in.read(reinterpret_cast<char*>(&incomeBeforeTaxRatio), sizeof(incomeBeforeTaxRatio));
     in.read(reinterpret_cast<char*>(&incomeTaxExpense), sizeof(incomeTaxExpense));
     in.read(reinterpret_cast<char*>(&netIncome), sizeof(netIncome));
     in.read(reinterpret_cast<char*>(&netIncomeRatio), sizeof(netIncomeRatio));
     in.read(reinterpret_cast<char*>(&eps), sizeof(eps));
     in.read(reinterpret_cast<char*>(&epsdiluted), sizeof(epsdiluted));
     in.read(reinterpret_cast<char*>(&weightedAverageShsOut), sizeof(weightedAverageShsOut));
     in.read(reinterpret_cast<char*>(&weightedAverageShsOutDil), sizeof(weightedAverageShsOutDil));
      
         
         
         
     size_t link_len;
     in.read(reinterpret_cast<char*>(&link_len), sizeof(link_len));
     std::string link(link_len,'\0');
     in.read(&link[0],link_len);
   
     size_t final_link_len;
     in.read(reinterpret_cast<char*>(&final_link_len), sizeof(final_link_len));
     std::string finalLink(final_link_len,'\0');
     in.read(&finalLink[0],final_link_len);


    
     //in.close();
    
    
}