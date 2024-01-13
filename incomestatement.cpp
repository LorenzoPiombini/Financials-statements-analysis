#include "Incomestatement.h"
#include "nlohmann/json.hpp"
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