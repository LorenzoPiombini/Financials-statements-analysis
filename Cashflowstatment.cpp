#include <iostream>

#include "Cashflowstatement.h"
#include "nlohmann/json.hpp"

std::string Cashflowstatement::get_date() const {
    return date;
}

std::string Cashflowstatement::get_symbol() const {
    return symbol;
}

std::string Cashflowstatement::get_reported_currency() const {
    return reportedCurrency;
}

std::string Cashflowstatement::get_cik() const {
    return cik;
}

std::string Cashflowstatement::get_filling_date() const {
    return fillingDate;
}

std::string Cashflowstatement::get_accepted_dat() const {
    return acceptedDat;
}

std::string Cashflowstatement::get_calendar_year() const {
    return calendarYear;
}

std::string Cashflowstatement::get_period() const {
    return period;
}

long long Cashflowstatement::get_net_income() const {
    return netIncome;
}

long long Cashflowstatement::get_depreciation_and_amortization() const {
    return depreciationAndAmortization;
}

long long Cashflowstatement::get_deferred_income_tax() const {
    return deferredIncomeTax;
}

long long Cashflowstatement::get_stock_based_compensation() const {
    return stockBasedCompensation;
}

long long Cashflowstatement::get_change_in_working_capital() const {
    return changeInWorkingCapital;
}

long long Cashflowstatement::get_accounts_receivables() const {
    return accountsReceivables;
}

long long Cashflowstatement::get_inventory() const {
    return inventory;
}

long long Cashflowstatement::get_accounts_payables() const {
    return accountsPayables;
}

long long Cashflowstatement::get_other_working_capital() const {
    return otherWorkingCapital;
}

long long Cashflowstatement::get_other_non_cash_items() const {
    return otherNonCashItems;
}

long long Cashflowstatement::get_net_cash_provided_by_operating_activities() const {
    return netCashProvidedByOperatingActivities;
}

long long Cashflowstatement::get_investments_in_property_plant_and_equipment() const {
    return investmentsInPropertyPlantAndEquipment;
}

long long Cashflowstatement::get_acquisitions_net() const {
    return acquisitionsNet;
}

long long Cashflowstatement::get_purchases_of_investments() const {
    return purchasesOfInvestments;
}

long long Cashflowstatement::get_sales_maturities_of_investments() const {
    return salesMaturitiesOfInvestments;
}

long long Cashflowstatement::get_other_investing_activites() const {
    return otherInvestingActivites;
}

long long Cashflowstatement::get_net_cash_used_for_investing_activites() const {
    return netCashUsedForInvestingActivites;
}

long long Cashflowstatement::get_debt_repayment() const {
    return debtRepayment;
}

long long Cashflowstatement::get_common_stock_issued() const {
    return commonStockIssued;
}

long long Cashflowstatement::get_common_stock_repurchased() const {
    return commonStockRepurchased;
}

long long Cashflowstatement::get_dividends_paid() const {
    return dividendsPaid;
}

long long Cashflowstatement::get_other_financing_activites() const {
    return otherFinancingActivites;
}

long long Cashflowstatement::get_net_cash_used_provided_by_financing_activities() const {
    return netCashUsedProvidedByFinancingActivities;
}

long long Cashflowstatement::get_effect_of_forex_changes_on_cash() const {
    return effectOfForexChangesOnCash;
}

long long Cashflowstatement::get_net_change_in_cash() const {
    return netChangeInCash;
}

long long Cashflowstatement::get_cash_at_end_of_period() const {
    return cashAtEndOfPeriod;
}

long long Cashflowstatement::get_cash_at_beginning_of_period() const {
    return cashAtBeginningOfPeriod;
}

long long Cashflowstatement::get_operating_cash_flow() const {
    return operatingCashFlow;
}

long long Cashflowstatement::get_capital_expenditure() const {
    return capitalExpenditure;
}

long long Cashflowstatement::get_free_cash_flow() const {
    return freeCashFlow;
}

std::string Cashflowstatement::get_link() const {
    return link;
}

std::string Cashflowstatement::get_final_link() const {
    return finalLink;
}


void from_json(const nlohmann::json &j, Cashflowstatement &c){

    c.date = j.contains("date") && !j["date"].empty() ? j["date"].get<std::string>() : "none";
    c.symbol = j.contains("symbol") && !j["symbol"].empty() ? j["symbol"].get<std::string>() : "none";
    c.reportedCurrency = j.contains("reportedCurrency") && !j["reportedCurrency"].empty() ? j["reportedCurrency"].get<std::string>() : "none";
    c.cik = j.contains("cik") && !j["cik"].empty() ? j["cik"].get<std::string>() : "none";
    c.fillingDate = j.contains("fillingDate") && !j["fillingDate"].empty() ? j["fillingDate"].get<std::string>() : "none";
    c.acceptedDat = j.contains("acceptedDat") && !j["acceptedDat"].empty() ? j["acceptedDat"].get<std::string>() : "none";
    c.calendarYear = j.contains("calendarYear") && !j["calendarYear"].empty() ? j["calendarYear"].get<std::string>() : "none";
    c.period = j.contains("period") && !j["period"].empty() ? j["period"].get<std::string>() : "none";

    // Numeric members
    c.netIncome = j.contains("netIncome") && !j["netIncome"].empty() ? j["netIncome"].get<long long>() : 0;
    c.depreciationAndAmortization = j.contains("depreciationAndAmortization") && !j["depreciationAndAmortization"].empty() ? j["depreciationAndAmortization"].get<long long>() : 0;
    c.deferredIncomeTax = j.contains("deferredIncomeTax") && !j["deferredIncomeTax"].empty() ? j["deferredIncomeTax"].get<long long>() : 0;
    c.stockBasedCompensation = j.contains("stockBasedCompensation") && !j["stockBasedCompensation"].empty() ? j["stockBasedCompensation"].get<long long>() : 0;
    c.changeInWorkingCapital = j.contains("changeInWorkingCapital") && !j["changeInWorkingCapital"].empty() ? j["changeInWorkingCapital"].get<long long>() : 0;
    c.accountsReceivables = j.contains("accountsReceivables") && !j["accountsReceivables"].empty() ? j["accountsReceivables"].get<long long>() : 0;
    c.inventory = j.contains("inventory") && !j["inventory"].empty() ? j["inventory"].get<long long>() : 0;
    c.accountsPayables = j.contains("accountsPayables") && !j["accountsPayables"].empty() ? j["accountsPayables"].get<long long>() : 0;
    c.otherWorkingCapital = j.contains("otherWorkingCapital") && !j["otherWorkingCapital"].empty() ? j["otherWorkingCapital"].get<long long>() : 0;
    c.otherNonCashItems = j.contains("otherNonCashItems") && !j["otherNonCashItems"].empty() ? j["otherNonCashItems"].get<long long>() : 0;
    c.netCashProvidedByOperatingActivities = j.contains("netCashProvidedByOperatingActivities") && !j["netCashProvidedByOperatingActivities"].empty() ? j["netCashProvidedByOperatingActivities"].get<long long>() : 0;
    c.investmentsInPropertyPlantAndEquipment = j.contains("investmentsInPropertyPlantAndEquipment") && !j["investmentsInPropertyPlantAndEquipment"].empty() ? j["investmentsInPropertyPlantAndEquipment"].get<long long>() : 0;
    c.acquisitionsNet = j.contains("acquisitionsNet") && !j["acquisitionsNet"].empty() ? j["acquisitionsNet"].get<long long>() : 0;
    c.purchasesOfInvestments = j.contains("purchasesOfInvestments") && !j["purchasesOfInvestments"].empty() ? j["purchasesOfInvestments"].get<long long>() : 0;
    c.salesMaturitiesOfInvestments = j.contains("salesMaturitiesOfInvestments") && !j["salesMaturitiesOfInvestments"].empty() ? j["salesMaturitiesOfInvestments"].get<long long>() : 0;
    c.otherInvestingActivites = j.contains("otherInvestingActivites") && !j["otherInvestingActivites"].empty() ? j["otherInvestingActivites"].get<long long>() : 0;
    c.netCashUsedForInvestingActivites = j.contains("netCashUsedForInvestingActivites") && !j["netCashUsedForInvestingActivites"].empty() ? j["netCashUsedForInvestingActivites"].get<long long>() : 0;
    c.debtRepayment = j.contains("debtRepayment") && !j["debtRepayment"].empty() ? j["debtRepayment"].get<long long>() : 0;
    c.commonStockIssued = j.contains("commonStockIssued") && !j["commonStockIssued"].empty() ? j["commonStockIssued"].get<long long>() : 0;
    c.commonStockRepurchased = j.contains("commonStockRepurchased") && !j["commonStockRepurchased"].empty() ? j["commonStockRepurchased"].get<long long>() : 0;
    c.dividendsPaid = j.contains("dividendsPaid") && !j["dividendsPaid"].empty() ? j["dividendsPaid"].get<long long>() : 0;
    c.otherFinancingActivites = j.contains("otherFinancingActivites") && !j["otherFinancingActivites"].empty() ? j["otherFinancingActivites"].get<long long>() : 0;
    c.netCashUsedProvidedByFinancingActivities = j.contains("netCashUsedProvidedByFinancingActivities") && !j["netCashUsedProvidedByFinancingActivities"].empty() ? j["netCashUsedProvidedByFinancingActivities"].get<long long>() : 0;
    c.effectOfForexChangesOnCash = j.contains("effectOfForexChangesOnCash") && !j["effectOfForexChangesOnCash"].empty() ? j["effectOfForexChangesOnCash"].get<long long>() : 0;
    c.netChangeInCash = j.contains("netChangeInCash") && !j["netChangeInCash"].empty() ? j["netChangeInCash"].get<long long>() : 0;
    c.cashAtEndOfPeriod = j.contains("cashAtEndOfPeriod") && !j["cashAtEndOfPeriod"].empty() ? j["cashAtEndOfPeriod"].get<long long>() : 0;
    c.cashAtBeginningOfPeriod = j.contains("cashAtBeginningOfPeriod") && !j["cashAtBeginningOfPeriod"].empty() ? j["cashAtBeginningOfPeriod"].get<long long>() : 0;
    c.operatingCashFlow = j.contains("operatingCashFlow") && !j["operatingCashFlow"].empty() ? j["operatingCashFlow"].get<long long>() : 0;
    c.capitalExpenditure = j.contains("capitalExpenditure") && !j["capitalExpenditure"].empty() ? j["capitalExpenditure"].get<long long>() : 0;
    c.freeCashFlow = j.contains("freeCashFlow") && !j["freeCashFlow"].empty() ? j["freeCashFlow"].get<long long>() : 0;
    
    // String members without a numeric counterpart
    c.link = j.contains("link") && !j["link"].empty() ? j["link"].get<std::string>() : "none";
    c.finalLink = j.contains("finalLink") && !j["finalLink"].empty() ? j["finalLink"].get<std::string>() : "none";
}

    

