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



void Balancesheet::save_to_file(std::ofstream &out){
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


    
    out.close();
}

void Balancesheet::read_from_file(std::ifstream &in){
    //std::ifstream in (create_file_name(ticker), std::ios::binary);
    
//    if(!in){
//        std::cout << "I could not open the file " + create_file_name(ticker);
//        return;
//    }
    
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

   
    in.read(reinterpret_cast<char*>(&cashAndCashEquivalents), sizeof(cashAndCashEquivalents));
    in.read(reinterpret_cast<char*>(&shortTermInvestments), sizeof(shortTermInvestments)); 
    in.read(reinterpret_cast<char*>(&cashAndShortTermInvestments), sizeof(cashAndShortTermInvestments));
    in.read(reinterpret_cast<char*>(&netReceivables), sizeof(netReceivables)); 
    in.read(reinterpret_cast<char*>(&inventory), sizeof(inventory));
    in.read(reinterpret_cast<char*>(&otherCurrentAssets), sizeof(otherCurrentAssets)); 
    in.read(reinterpret_cast<char*>(&totalCurrentAssets), sizeof(totalCurrentAssets)); 
    in.read(reinterpret_cast<char*>(&propertyPlantEquipmentNet), sizeof(propertyPlantEquipmentNet));
    in.read(reinterpret_cast<char*>(&goodwill), sizeof(goodwill));
    in.read(reinterpret_cast<char*>(&intangibleAssets), sizeof(intangibleAssets)); 
    in.read(reinterpret_cast<char*>(&goodwillAndIntangibleAssets), sizeof(goodwillAndIntangibleAssets));
    in.read(reinterpret_cast<char*>(&longTermInvestments), sizeof(longTermInvestments)); 
	in.read(reinterpret_cast<char*>(&taxAssets), sizeof(taxAssets));
    in.read(reinterpret_cast<char*>(&otherNonCurrentAssets), sizeof(otherNonCurrentAssets));
    in.read(reinterpret_cast<char*>(&totalNonCurrentAssets), sizeof(totalNonCurrentAssets));
    in.read(reinterpret_cast<char*>(&otherAssets), sizeof(otherAssets)); 
	in.read(reinterpret_cast<char*>(&totalAssets), sizeof(totalAssets)); 
    in.read(reinterpret_cast<char*>(&accountPayables), sizeof(accountPayables));
    in.read(reinterpret_cast<char*>(&shortTermDebt), sizeof(shortTermDebt)); 
    in.read(reinterpret_cast<char*>(&taxPayables), sizeof(taxPayables)); 
    in.read(reinterpret_cast<char*>(&deferredRevenue), sizeof(deferredRevenue)); 
	in.read(reinterpret_cast<char*>(&otherCurrentLiabilities), sizeof(otherCurrentLiabilities));
    in.read(reinterpret_cast<char*>(&totalCurrentLiabilities), sizeof(totalCurrentLiabilities));
    in.read(reinterpret_cast<char*>(&longTermDebt), sizeof(longTermDebt));
    in.read(reinterpret_cast<char*>(&deferredRevenueNonCurrent), sizeof(deferredRevenueNonCurrent)); 
    in.read(reinterpret_cast<char*>(&deferredTaxLiabilitiesNonCurrent), sizeof(deferredTaxLiabilitiesNonCurrent)); 
    in.read(reinterpret_cast<char*>(&otherNonCurrentLiabilities), sizeof(otherNonCurrentLiabilities));
    in.read(reinterpret_cast<char*>(&totalNonCurrentLiabilities), sizeof(totalNonCurrentLiabilities)); 
    in.read(reinterpret_cast<char*>(&otherLiabilities), sizeof(otherLiabilities)); 
    in.read(reinterpret_cast<char*>(&capitalLeaseObligations), sizeof(capitalLeaseObligations)); 
	in.read(reinterpret_cast<char*>(&totalLiabilities), sizeof(totalLiabilities)); 
	in.read(reinterpret_cast<char*>(&preferredStock), sizeof(preferredStock));
    in.read(reinterpret_cast<char*>(&commonStock), sizeof(commonStock));
    in.read(reinterpret_cast<char*>(&retainedEarnings), sizeof(retainedEarnings)); 
    in.read(reinterpret_cast<char*>(&accumulatedOtherComprehensiveIncomeLoss), sizeof(accumulatedOtherComprehensiveIncomeLoss)); 
    in.read(reinterpret_cast<char*>(&othertotalStockholdersEquity), sizeof(othertotalStockholdersEquity)); 
    in.read(reinterpret_cast<char*>(&totalStockholdersEquity), sizeof(totalStockholdersEquity)); 
	in.read(reinterpret_cast<char*>(&totalEquity), sizeof(totalEquity));
	in.read(reinterpret_cast<char*>(&totalLiabilitiesAndStockholdersEquity), sizeof(totalLiabilitiesAndStockholdersEquity)); 
	in.read(reinterpret_cast<char*>(&minorityInterest), sizeof(minorityInterest));
    in.read(reinterpret_cast<char*>(&totalLiabilitiesAndTotalEquity), sizeof(totalLiabilitiesAndTotalEquity));
    in.read(reinterpret_cast<char*>(&totalInvestments), sizeof(totalInvestments));
    in.read(reinterpret_cast<char*>(&totalDebt), sizeof(totalDebt)); 
    in.read(reinterpret_cast<char*>(&netDebt), sizeof(netDebt)); 
   
    size_t link_len;
    in.read(reinterpret_cast<char*>(&link_len), sizeof(link_len));
    std::string link(link_len,'\0');
    in.read(&link[0],link_len);
   
    size_t final_link_len;
    in.read(reinterpret_cast<char*>(&final_link_len), sizeof(final_link_len));
    std::string finalLink(final_link_len,'\0');
    in.read(&finalLink[0],final_link_len);


    
    
    
}