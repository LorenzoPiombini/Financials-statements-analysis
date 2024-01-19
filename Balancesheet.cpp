#include "Balancesheet.h"
#include "nlohmann/json.hpp"
#include <iostream>
#include <string>



std::string Balancesheet::get_date() const{
    return date;
}

std::string Balancesheet::get_symbol() const{
    return symbol;
}
std::string Balancesheet::get_reported_currency() const{
    return reportedCurrency;
}
std::string Balancesheet::get_cik() const{
    return cik;
}
std::string Balancesheet::get_filling_date() const{
    return fillingDate;
}
std::string Balancesheet::get_accepted_date() const{
    return acceptedDate;
}
std::string Balancesheet::get_calendar_year() const{
    return calendarYear;
}
std::string Balancesheet::get_period() const{
    return period;
}
long long Balancesheet::get_cash_and_cash_equivalents() const{
    return cashAndCashEquivalents;
}
long long Balancesheet::get_short_term_investments() const{
    return shortTermInvestments;
}
long long Balancesheet::get_cash_and_short_term_investments() const{
    return cashAndShortTermInvestments;
}
long long Balancesheet::get_net_receivables() const{
    return netReceivables;
}
long long Balancesheet::get_inventory() const{
    return inventory;
}
long long Balancesheet::get_other_current_assets() const{
    return otherCurrentAssets;
}
long long Balancesheet::get_total_current_assets() const{
    return totalCurrentAssets;
}
long long Balancesheet::get_property_plant_equipment_net() const{
    return propertyPlantEquipmentNet;
}
long long Balancesheet::get_goodwill() const{
    return goodwill;
}
long long Balancesheet::get_intangible_assets() const{
    return intangibleAssets;
}
long long Balancesheet::get_goodwill_and_intangible_assets() const{
    return goodwillAndIntangibleAssets;
}
long long Balancesheet::get_long_term_investments() const{
    return longTermInvestments;
}
long long Balancesheet::get_tax_assets() const{
    return taxAssets;
}
long long Balancesheet::get_other_non_current_assets() const{
    return otherNonCurrentAssets;
}
long long Balancesheet::get_total_non_current_assets() const{
    return totalNonCurrentAssets;
}
long long Balancesheet::get_other_assets() const{
    return otherAssets;
}
long long Balancesheet::get_total_assets() const{
    return totalAssets;
}
long long Balancesheet::get_account_payables() const{
    return accountPayables;
}
long long Balancesheet::get_short_term_debt() const{
    return shortTermDebt;
}
long long Balancesheet::get_tax_payables() const{
    return taxPayables;
}
long long Balancesheet::get_deferred_revenue() const{
    return deferredRevenue;
}
long long Balancesheet::get_other_current_liabilities() const{
    return otherCurrentLiabilities;
}
long long Balancesheet::get_total_current_liabilities() const{
    return totalCurrentLiabilities;
}
long long Balancesheet::get_long_term_Debt() const{
    return longTermDebt;
}
long long Balancesheet::get_deferred_revenue_non_current() const{
    return  deferredRevenueNonCurrent;
}
long long Balancesheet::get_deferred_tax_liabilities_non_current() const{
    return deferredTaxLiabilitiesNonCurrent;
}
long long Balancesheet::get_other_non_current_liabilities() const{
    return otherNonCurrentLiabilities;
}
long long Balancesheet::get_total_non_current_liabilities() const{
    return totalNonCurrentLiabilities;
}
long long Balancesheet::get_other_liabilities() const{
    return otherLiabilities;
}
long long Balancesheet::get_capital_lease_obligations() const{
    return capitalLeaseObligations;
}
long long Balancesheet::get_total_liabilities() const{
    return totalLiabilities;
}
long long Balancesheet::get_preferred_stock() const{
    return preferredStock;
}
long long Balancesheet::get_common_stock() const{
    return commonStock;   
}
long long Balancesheet::get_retained_earnings() const{
    return retainedEarnings;
}
long long Balancesheet::get_accumulated_other_comprehensive_income_loss() const{
    return accumulatedOtherComprehensiveIncomeLoss;
}
long long Balancesheet::get_other_total_stockholders_equity() const{
    return othertotalStockholdersEquity;
}
long long Balancesheet::get_total_stockholders_equity() const{
    return totalStockholdersEquity;
}
long long Balancesheet::get_total_equity() const{
    return totalEquity;
}
long long Balancesheet::get_total_liabilities_and_stockholders_equity() const{
    return totalLiabilitiesAndStockholdersEquity;
}
long long Balancesheet::get_minority_interest() const{
    return minorityInterest;
}
long long Balancesheet::get_total_liabilities_and_total_equity() const{
    return totalLiabilitiesAndTotalEquity;
}
long long Balancesheet::get_total_investments() const{
    return totalInvestments;
}
long long Balancesheet::get_total_debt() const{
    return totalDebt;
}
long long Balancesheet::get_net_debt() const{
    return netDebt;
}

std::string Balancesheet::get_link() const{
    return link;
}
std::string Balancesheet::get_final_link() const{
    return finalLink;
}

std::string Balancesheet::get_class_name() const {
   return  "balance_sheet";   
}
        
std::string Balancesheet::create_file_name(std::string ticker)const{
   if(ticker.size()==0){
        return  symbol + "_" + get_class_name() +".bin";
    } else {
        return  ticker + "_" + get_class_name() +".bin";    
    }
}

void from_json(const nlohmann::json &j, Balancesheet &i){
        
     if(j.contains("date") && !j["date"].empty()){
         j.at("date").get_to(i.date);
     }else {
         i.date= "none";
     }
      
     if(j.contains("symbol") && !j["symbol"].empty()){
         j.at("symbol").get_to(i.symbol);
     }else {
         i.symbol = "none";
     }
     if(j.contains("reportedCurrency") && !j["reportedCurrency"].empty()){
         j.at("reportedCurrency").get_to(i.reportedCurrency);
     }else {
         i.reportedCurrency = "none";
     }
      
    
     if(j.contains("cik") && !j["cik"].empty()){
         j.at("cik").get_to(i.cik);
     }else {
         i.cik = "none" ;
     }
      
     if(j.contains("fillingDate") && !j["fillingDate"].empty()){
         j.at("fillingDate").get_to(i.fillingDate);
     }else {
         i.fillingDate = "none" ;
     }
      if(j.contains("acceptedDate") && !j["acceptedDate"].empty()){
         j.at("acceptedDate").get_to(i.acceptedDate);
     }else {
         i.acceptedDate = "none";
     }
      
     if(j.contains("calendarYear") && !j["calendarYear"].empty()){
         j.at("calendarYear").get_to(i.calendarYear);
     }else {
         i.calendarYear = "none";
     }
      if(j.contains("period") && !j["period"].empty()){
         j.at("period").get_to(i.period);
     }else {
         i.period = "none";
     }
      
     if(j.contains("cashAndCashEquivalents") && !j["cashAndCashEquivalents"].empty()){
         j.at("cashAndCashEquivalents").get_to(i.cashAndCashEquivalents);
     }else {
         i.cashAndCashEquivalents = 0;
     }
      if(j.contains("shortTermInvestments") && !j["shortTermInvestments"].empty()){
         j.at("shortTermInvestments").get_to(i.shortTermInvestments);
     }else {
         i.shortTermInvestments = 0;
     }
      
     if(j.contains("cashAndShortTermInvestments") && !j["cashAndShortTermInvestments"].empty()){
         j.at("cashAndShortTermInvestments").get_to(i.cashAndShortTermInvestments);
     }else {
         i.cashAndShortTermInvestments = 0 ;
     }
      if(j.contains("netReceivables") && !j["netReceivables"].empty()){
         j.at("netReceivables").get_to(i.netReceivables);
     }else {
         i.netReceivables = 0 ;
     }
      
     if(j.contains("inventory") && !j["inventory"].empty()){
         j.at("inventory").get_to(i.inventory);
     }else {
         i.inventory = 0;
     }
      if(j.contains("otherCurrentAssets") && !j["otherCurrentAssets"].empty()){
         j.at("otherCurrentAssets").get_to(i.otherCurrentAssets);
     }else {
         i.otherCurrentAssets = 0;
     }
      
    
      if(j.contains("totalCurrentAssets") && !j["totalCurrentAssets"].empty()){
         j.at("totalCurrentAssets").get_to(i.totalCurrentAssets);
     }else {
         i.totalCurrentAssets = 0 ;
     }
      
     if(j.contains("propertyPlantEquipmentNet") && !j["propertyPlantEquipmentNet"].empty()){
         j.at("propertyPlantEquipmentNet").get_to(i.propertyPlantEquipmentNet);
     }else {
         i.propertyPlantEquipmentNet = 0 ;
     }
      if(j.contains("goodwill") && !j["goodwill"].empty()){
         j.at("goodwill").get_to(i.goodwill);
     }else {
         i.goodwill = 0;
     }
      
     if(j.contains("intangibleAssets") && !j["intangibleAssets"].empty()){
         j.at("intangibleAssets").get_to(i.intangibleAssets);
     }else {
         i.intangibleAssets = 0;
     }
    
    if(j.contains("goodwillAndIntangibleAssets") && !j["goodwillAndIntangibleAssets"].empty()){
         j.at("goodwillAndIntangibleAssets").get_to(i.goodwillAndIntangibleAssets);
     }else {
         i.goodwillAndIntangibleAssets = 0 ;
     }
     
      
    if(j.contains("longTermInvestments") && !j["longTermInvestments"].empty()){
         j.at("longTermInvestments").get_to(i.longTermInvestments);
     }else {
         i.longTermInvestments = 0;
     }
     
      if(j.contains("taxAssets") && !j["taxAssets"].empty()){
         j.at("taxAssets").get_to(i.taxAssets);
     }else {
         i.taxAssets = 0 ;
     }
    
    if(j.contains("otherNonCurrentAssets") && !j["otherNonCurrentAssets"].empty()){
         j.at("otherNonCurrentAssets").get_to(i.otherNonCurrentAssets);
     }else {
         i.otherNonCurrentAssets = 0;
     }
     
    if(j.contains("totalNonCurrentAssets") && !j["totalNonCurrentAssets"].empty()){
         j.at("totalNonCurrentAssets").get_to(i.totalNonCurrentAssets);
     }else {
         i.totalNonCurrentAssets = 0;
     }
      if(j.contains("otherAssets") && !j["otherAssets"].empty()){
         j.at("otherAssets").get_to(i.otherAssets);
     }else {
         i.otherAssets = 0;
     }
    
    if(j.contains("totalAssets") && !j["totalAssets"].empty()){
         j.at("totalAssets").get_to(i.totalAssets);
     }else {
         i.totalAssets = 0;
     }
     
      
    if(j.contains("accountPayables") && !j["accountPayables"].empty()){
         j.at("accountPayables").get_to(i.accountPayables);
     }else {
         i.accountPayables = 0 ;
     }
      if(j.contains("shortTermDebt") && !j["shortTermDebt"].empty()){
         j.at("shortTermDebt").get_to(i.shortTermDebt);
     }else {
         i.shortTermDebt = 0;
     }
    
    if(j.contains("taxPayables") && !j["taxPayables"].empty()){
         j.at("taxPayables").get_to(i.taxPayables);
     }else {
         i.taxPayables = 0 ;
     }
     
      
    if(j.contains("deferredRevenue") && !j["deferredRevenue"].empty()){
         j.at("deferredRevenue").get_to(i.deferredRevenue);
     }else {
         i.deferredRevenue =0 ;
     }
     
      if(j.contains("otherCurrentLiabilities") && !j["otherCurrentLiabilities"].empty()){
         j.at("otherCurrentLiabilities").get_to(i.otherCurrentLiabilities);
     }else {
         i.otherCurrentLiabilities = 0;
     }
    
    if(j.contains("totalCurrentLiabilities") && !j["totalCurrentLiabilities"].empty()){
         j.at("totalCurrentLiabilities").get_to(i.totalCurrentLiabilities);
     }else {
         i.totalCurrentLiabilities = 0;
     }
     
      
    if(j.contains("longTermDebt") && !j["longTermDebt"].empty()){
         j.at("longTermDebt").get_to(i.longTermDebt);
     }else {
         i.longTermDebt = 0;
     }
     
      if(j.contains("deferredRevenueNonCurrent") && !j["deferredRevenueNonCurrent"].empty()){
         j.at("deferredRevenueNonCurrent").get_to(i.deferredRevenueNonCurrent);
     }else {
         i.deferredRevenueNonCurrent = 0 ;
     }
    
    if(j.contains("deferredTaxLiabilitiesNonCurrent") && !j["deferredTaxLiabilitiesNonCurrent"].empty()){
         j.at("deferredTaxLiabilitiesNonCurrent").get_to(i.deferredTaxLiabilitiesNonCurrent);
     }else {
         i.deferredTaxLiabilitiesNonCurrent = 0;
     }
     
      
    if(j.contains("otherNonCurrentLiabilities") && !j["otherNonCurrentLiabilities"].empty()){
         j.at("otherNonCurrentLiabilities").get_to(i.otherNonCurrentLiabilities);
     }else {
         i.otherNonCurrentLiabilities = 0;
     }
       
    if(j.contains("totalNonCurrentLiabilities") && !j["totalNonCurrentLiabilities"].empty()){
         j.at("totalNonCurrentLiabilities").get_to(i.totalNonCurrentLiabilities);
     }else {
         i.totalNonCurrentLiabilities = 0;
     }
     
      if(j.contains("otherLiabilities") && !j["otherLiabilities"].empty()){
         j.at("otherLiabilities").get_to(i.otherLiabilities);
     }else {
         i.otherLiabilities =0 ;
     }
    
    if(j.contains("capitalLeaseObligations") && !j["capitalLeaseObligations"].empty()){
         j.at("capitalLeaseObligations").get_to(i.capitalLeaseObligations);
     }else {
         i.capitalLeaseObligations = 0 ;
     }
     
      
    if(j.contains("totalLiabilities") && !j["totalLiabilities"].empty()){
         j.at("totalLiabilities").get_to(i.totalLiabilities);
     }else {
         i.totalLiabilities = 0;
     }
       
    if(j.contains("preferredStock") && !j["preferredStock"].empty()){
         j.at("preferredStock").get_to(i.preferredStock);
     }else {
         i.preferredStock = 0;
     }
     
      if(j.contains("commonStock") && !j["commonStock"].empty()){
         j.at("commonStock").get_to(i.commonStock);
     }else {
         i.commonStock = 0;
     }
    
    if(j.contains("retainedEarnings") && !j["retainedEarnings"].empty()){
         j.at("retainedEarnings").get_to(i.retainedEarnings);
     }else {
         i.retainedEarnings = 0;
     }
     
      
    if(j.contains("accumulatedOtherComprehensiveIncomeLoss") && !j["accumulatedOtherComprehensiveIncomeLoss"].empty()){
         j.at("accumulatedOtherComprehensiveIncomeLoss").get_to(i.accumulatedOtherComprehensiveIncomeLoss);
     }else {
         i.accumulatedOtherComprehensiveIncomeLoss = 0;
     }
       
    if(j.contains("othertotalStockholdersEquity") && !j["othertotalStockholdersEquity"].empty()){
         j.at("othertotalStockholdersEquity").get_to(i.othertotalStockholdersEquity);
     }else {
         i.othertotalStockholdersEquity = 0;
     }
     
      if(j.contains("totalStockholdersEquity") && !j["totalStockholdersEquity"].empty()){
         j.at("totalStockholdersEquity").get_to(i.totalStockholdersEquity);
     }else {
         i.totalStockholdersEquity = 0 ;
     }
    
    if(j.contains("totalEquity") && !j["totalEquity"].empty()){
         j.at("totalEquity").get_to(i.totalEquity);
     }else {
         i.totalEquity = 0;
     }
     
      
    if(j.contains("totalLiabilitiesAndStockholdersEquity") && !j["totalLiabilitiesAndStockholdersEquity"].empty()){
         j.at("totalLiabilitiesAndStockholdersEquity").get_to(i.totalLiabilitiesAndStockholdersEquity);
     }else {
         i.totalLiabilitiesAndStockholdersEquity = 0;
     }
       
    if(j.contains("minorityInterest") && !j["minorityInterest"].empty()){
         j.at("minorityInterest").get_to(i.minorityInterest);
     }else {
         i.minorityInterest = 0;
     }
     
      if(j.contains("totalLiabilitiesAndTotalEquity") && !j["totalLiabilitiesAndTotalEquity"].empty()){
         j.at("totalLiabilitiesAndTotalEquity").get_to(i.totalLiabilitiesAndTotalEquity);
     }else {
         i.totalLiabilitiesAndTotalEquity = 0;
     }
    
    if(j.contains("totalInvestments") && !j["totalInvestments"].empty()){
         j.at("totalInvestments").get_to(i.totalInvestments);
     }else {
         i.totalInvestments = 0;
     }
     
      
    if(j.contains("totalDebt") && !j["totalDebt"].empty()){
         j.at("totalDebt").get_to(i.totalDebt);
     }else {
         i.totalDebt = 0;
     }
     
     if(j.contains("netDebt") && !j["netDebt"].empty()){
         j.at("netDebt").get_to(i.netDebt);
     }else {
         i.netDebt = 0;
     }
     
     if(j.contains("link") && !j["link"].empty()){
         j.at("link").get_to(i.link);
     }else {
         i.link = "nf" ;
     }
     
     if(j.contains("finalLink") && !j["finalLink"].empty()){
         j.at("finalLink").get_to(i.finalLink);
     }else {
         i.finalLink = "nf";
     }
     
      
}


size_t Balancesheet::compute_object_size() const {
      size_t total_size {0};

      total_size += date.size() * sizeof(char);
      total_size += symbol.size() * sizeof(char);
      total_size += reportedCurrency.size() * sizeof(char);
      total_size += cik.size() * sizeof(char);
      total_size += fillingDate.size() * sizeof(char);
      total_size += acceptedDate.size() * sizeof(char);
      total_size += calendarYear.size() * sizeof(char);
      total_size += period.size() * sizeof(char);
      total_size += link.size() * sizeof(char);
      total_size += finalLink.size() * sizeof(char);
      // Include the size of each string length (assuming size_t for length)
      total_size += sizeof(size_t) * 10; //10 is the number of the string members
      
      total_size += sizeof(long long)  * 44;// 44 is the number of long long memebrs
      return total_size;
    
    }

void Balancesheet::save_to_file(std::ofstream &out){
    
        if (!out) {
        std::cerr << "File stream is not open or has encountered an error." << std::endl;
        return;
        }
    
    
     size_t obj_size = this-> compute_object_size();
     out.write(reinterpret_cast<const char*>(&obj_size), sizeof(obj_size));
     

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

   
    out.write(reinterpret_cast<const char*>(&cashAndCashEquivalents), sizeof(cashAndCashEquivalents));
    out.write(reinterpret_cast<const char*>(&shortTermInvestments), sizeof(shortTermInvestments)); 
    out.write(reinterpret_cast<const char*>(&cashAndShortTermInvestments), sizeof(cashAndShortTermInvestments));
    out.write(reinterpret_cast<const char*>(&netReceivables), sizeof(netReceivables)); 
    out.write(reinterpret_cast<const char*>(&inventory), sizeof(inventory));
    out.write(reinterpret_cast<const char*>(&otherCurrentAssets), sizeof(otherCurrentAssets)); 
   out.write(reinterpret_cast<const char*>(&totalCurrentAssets), sizeof(totalCurrentAssets)); 
    out.write(reinterpret_cast<const char*>(&propertyPlantEquipmentNet), sizeof(propertyPlantEquipmentNet));
    out.write(reinterpret_cast<const char*>(&goodwill), sizeof(goodwill));
    out.write(reinterpret_cast<const char*>(&intangibleAssets), sizeof(intangibleAssets)); 
    out.write(reinterpret_cast<const char*>(&goodwillAndIntangibleAssets), sizeof(goodwillAndIntangibleAssets));
    out.write(reinterpret_cast<const char*>(&longTermInvestments), sizeof(longTermInvestments)); 
	out.write(reinterpret_cast<const char*>(&taxAssets), sizeof(taxAssets));
    out.write(reinterpret_cast<const char*>(&otherNonCurrentAssets), sizeof(otherNonCurrentAssets));
    out.write(reinterpret_cast<const char*>(&totalNonCurrentAssets), sizeof(totalNonCurrentAssets));
   out.write(reinterpret_cast<const char*>(&otherAssets), sizeof(otherAssets)); 
	out.write(reinterpret_cast<const char*>(&totalAssets), sizeof(totalAssets)); 
    out.write(reinterpret_cast<const char*>(&accountPayables), sizeof(accountPayables));
   out.write(reinterpret_cast<const char*>(&shortTermDebt), sizeof(shortTermDebt)); 
   out.write(reinterpret_cast<const char*>(&taxPayables), sizeof(taxPayables)); 
    out.write(reinterpret_cast<const char*>(&deferredRevenue), sizeof(deferredRevenue)); 
	out.write(reinterpret_cast<const char*>(&otherCurrentLiabilities), sizeof(otherCurrentLiabilities));
   out.write(reinterpret_cast<const char*>(&totalCurrentLiabilities), sizeof(totalCurrentLiabilities));
    out.write(reinterpret_cast<const char*>(&longTermDebt), sizeof(longTermDebt));
    out.write(reinterpret_cast<const char*>(&deferredRevenueNonCurrent), sizeof(deferredRevenueNonCurrent)); 
    out.write(reinterpret_cast<const char*>(&deferredTaxLiabilitiesNonCurrent), sizeof(deferredTaxLiabilitiesNonCurrent)); 
    out.write(reinterpret_cast<const char*>(&otherNonCurrentLiabilities), sizeof(otherNonCurrentLiabilities));
    out.write(reinterpret_cast<const char*>(&totalNonCurrentLiabilities), sizeof(totalNonCurrentLiabilities)); 
   out.write(reinterpret_cast<const char*>(&otherLiabilities), sizeof(otherLiabilities)); 
   out.write(reinterpret_cast<const char*>(&capitalLeaseObligations), sizeof(capitalLeaseObligations)); 
	out.write(reinterpret_cast<const char*>(&totalLiabilities), sizeof(totalLiabilities)); 
	out.write(reinterpret_cast<const char*>(&preferredStock), sizeof(preferredStock));
    out.write(reinterpret_cast<const char*>(&commonStock), sizeof(commonStock));
    out.write(reinterpret_cast<const char*>(&retainedEarnings), sizeof(retainedEarnings)); 
    out.write(reinterpret_cast<const char*>(&accumulatedOtherComprehensiveIncomeLoss), sizeof(accumulatedOtherComprehensiveIncomeLoss)); 
    out.write(reinterpret_cast<const char*>(&othertotalStockholdersEquity), sizeof(othertotalStockholdersEquity)); 
    out.write(reinterpret_cast<const char*>(&totalStockholdersEquity), sizeof(totalStockholdersEquity)); 
	out.write(reinterpret_cast<const char*>(&totalEquity), sizeof(totalEquity));
	out.write(reinterpret_cast<const char*>(&totalLiabilitiesAndStockholdersEquity), sizeof(totalLiabilitiesAndStockholdersEquity)); 
	out.write(reinterpret_cast<const char*>(&minorityInterest), sizeof(minorityInterest));
    out.write(reinterpret_cast<const char*>(&totalLiabilitiesAndTotalEquity), sizeof(totalLiabilitiesAndTotalEquity));
    out.write(reinterpret_cast<const char*>(&totalInvestments), sizeof(totalInvestments));
    out.write(reinterpret_cast<const char*>(&totalDebt), sizeof(totalDebt)); 
    out.write(reinterpret_cast<const char*>(&netDebt), sizeof(netDebt)); 
   
    size_t link_len = link.size();
    out.write(reinterpret_cast<const char*>(&link_len), sizeof(link_len));
    out.write(link.c_str(), link_len);
   
    size_t final_link_len = finalLink.size();
    out.write(reinterpret_cast<const char*>(&final_link_len), sizeof(final_link_len));
    out.write(finalLink.c_str(), final_link_len);


    
    
}

bool read_size_from_buffer_balance(const std::vector<char> &buffer, size_t &pos, size_t &value){
        
        if(pos+sizeof(size_t)> buffer.size()) return false;
        std::memcpy(&value, buffer.data() + pos, sizeof(size_t));
        pos += sizeof(size_t);
        
        return true;
    
}

bool reading_string_from_buffer_balance(const std::vector<char> &buffer, size_t &pos, std::string &value){
    size_t lenght;
    
    if(!read_size_from_buffer_balance(buffer,pos,lenght)) return false;
    
    if(pos + lenght > buffer.size())return false;
    
    value.assign(buffer.data() + pos, lenght);
    pos += lenght;
    
    return true;
    
}

template <typename T>
bool read_number_values_from_buffer(std::vector<char> &buffer, size_t &pos, T &value){
    if(pos + sizeof(T) > buffer.size()) return false;
    
    std::memcpy(&value, buffer.data() + pos, sizeof(T));
    
    pos += sizeof(T);
    return true;
    
}


bool Balancesheet::read_from_file(std::ifstream &in, std::vector<Balancesheet*> &statements){
     if (!in){
      std::cerr<< "IO stream it is not open or some error with it.\n";   
    }
    
    
    while(in && !in.eof()){
    
    size_t obj_size;
    
    if(!in.read(reinterpret_cast<char*>(&obj_size), sizeof(obj_size))){
        if(in.eof()){
            break;
        }  
        std::cerr<< "Couldn't read object size from the file regrading class "<< get_class_name()<<"\n";
        return false;
    }
    
    
    
    Balancesheet* statement = new Balancesheet();
     std::vector<char> buffer(obj_size);
     
     if(!in.read(buffer.data(),obj_size)){
         std::cerr<< "failed to read object data from file class "<< get_class_name()<<"\n";
         return false;
      }
      
      
      
            size_t bytes_read = in.gcount();
        if (bytes_read != obj_size) {
            delete statement; // Clean up on error
            return false;
        }
        size_t pos = 0;
        
       
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->date)){
            std::cerr << "Error reading 'date' in " << get_class_name() << std::endl;
            }
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->symbol)){
             std::cerr << "Error reading 'symbol' in " << get_class_name() << std::endl;
             }
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->reportedCurrency)){
             std::cerr << "Error reading 'reportedCurrency' in " << get_class_name() << std::endl;
            }
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->cik)){
             std::cerr << "Error reading 'cik' in " << get_class_name() << std::endl;
            }
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->fillingDate)){
             std::cerr << "Error reading 'fillingDate' in " << get_class_name() << std::endl;
            }
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->acceptedDate)){
             std::cerr << "Error reading 'acceptedDate' in " << get_class_name() << std::endl;
            }
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->calendarYear)){
             std::cerr << "Error reading 'calendarYear' in " << get_class_name() << std::endl;
            }
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->period)){
             std::cerr << "Error reading 'period' in " << get_class_name() << std::endl;
            }
        
        //numbers value

        if(!read_number_values_from_buffer(buffer, pos,statement -> cashAndCashEquivalents)){
             std::cerr << "Error reading 'cashAndCashEquivalents' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->shortTermInvestments)){
            std::cerr << "Error reading 'shortTermInvestments' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->cashAndShortTermInvestments)){
            std::cerr << "Error reading 'cashAndShortTermInvestments' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->netReceivables)){
            std::cerr << "Error reading 'netReceivables' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->inventory)){
            std::cerr << "Error reading 'inventory' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->otherCurrentAssets)){
            std::cerr << "Error reading 'otherCurrentAssets' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalCurrentAssets)){
            std::cerr << "Error reading 'totalCurrentAssets' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->propertyPlantEquipmentNet)){
            std::cerr << "Error reading 'propertyPlantEquipmentNet' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->goodwill)){
            std::cerr << "Error reading 'goodwill' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->intangibleAssets)){
            std::cerr << "Error reading 'intangibleAssets' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->goodwillAndIntangibleAssets)){
            std::cerr << "Error reading 'goodwillAndIntangibleAssets' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->longTermInvestments)){
            std::cerr << "Error reading 'longTermInvestments' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->taxAssets)){
            std::cerr << "Error reading 'taxAssets' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->otherNonCurrentAssets)){
            std::cerr << "Error reading 'otherNonCurrentAssets' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalNonCurrentAssets)){
            std::cerr << "Error reading 'totalNonCurrentAssets' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->otherAssets)){
            std::cerr << "Error reading 'otherAssets' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalAssets)){
            std::cerr << "Error reading 'totalAssets' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->accountPayables)){
            std::cerr << "Error reading 'accountPayables' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->shortTermDebt)){
            std::cerr << "Error reading 'shortTermDebt' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->taxPayables)){
            std::cerr << "Error reading 'taxPayables' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->deferredRevenue)){
            std::cerr << "Error reading 'deferredRevenue' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->otherCurrentLiabilities)){
            std::cerr << "Error reading 'otherCurrentLiabilities' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalCurrentLiabilities)){
            std::cerr << "Error reading 'totalCurrentLiabilities' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->longTermDebt)){
            std::cerr << "Error reading 'longTermDebt' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->deferredRevenueNonCurrent)){
            std::cerr << "Error reading 'deferredRevenueNonCurrent' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->deferredTaxLiabilitiesNonCurrent)){
            std::cerr << "Error reading 'deferredTaxLiabilitiesNonCurrent' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->otherNonCurrentLiabilities)){
            std::cerr << "Error reading 'otherNonCurrentLiabilities' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalNonCurrentLiabilities)){
            std::cerr << "Error reading 'totalNonCurrentLiabilities' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->otherLiabilities)){
            std::cerr << "Error reading 'otherLiabilities' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->capitalLeaseObligations)){
            std::cerr << "Error reading 'capitalLeaseObligations' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalLiabilities)){
            std::cerr << "Error reading 'totalLiabilities' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->preferredStock)){
            std::cerr << "Error reading 'preferredStock' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->commonStock)){
            std::cerr << "Error reading 'commonStock' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->retainedEarnings)){
            std::cerr << "Error reading 'retainedEarnings' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->accumulatedOtherComprehensiveIncomeLoss)){
            std::cerr << "Error reading 'accumulatedOtherComprehensiveIncomeLoss' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->othertotalStockholdersEquity)){
            std::cerr << "Error reading 'othertotalStockholdersEquity' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalStockholdersEquity)){
            std::cerr << "Error reading 'totalStockholdersEquity' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalEquity)){
            std::cerr << "Error reading 'totalEquity' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalLiabilitiesAndStockholdersEquity)){
            std::cerr << "Error reading 'totalLiabilitiesAndStockholdersEquity' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->minorityInterest)){
            std::cerr << "Error reading 'minorityInterest' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalLiabilitiesAndTotalEquity)){
            std::cerr << "Error reading 'totalLiabilitiesAndTotalEquity' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalInvestments)){
            std::cerr << "Error reading 'totalInvestments' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalDebt)){
            std::cerr << "Error reading 'totalDebt' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->netDebt)){
            std::cerr << "Error reading 'netDebt' in " << get_class_name() << std::endl;
            }
        
        //std::string value
        
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->link)){
            
            std::cerr << "Erraor reading 'link' in " << get_class_name() << std::endl;
            
            }
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->finalLink)){
            std::cerr << "Error reading 'finalLink' in " << get_class_name() << std::endl;
            statement -> finalLink ="nf";
            } 
        
          
         if(statement != nullptr){
             
             statements.push_back(statement);
         }else {
           std::cout<< "there is no value in this ptr\n";   
             
         }
         
         
        if(bytes_read  < buffer.size()){
           
            std::cerr<<"Reached EOF! no more data to read in for "<<get_class_name()<<".\n";
            return false;
            
            }
       
     }


    return true;
    
    
}