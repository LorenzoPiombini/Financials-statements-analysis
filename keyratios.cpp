#include "Keyratios.h"
#include <iostream>
#include <sstream>
#include <fstream>


// Implementations of getters for std::string members
std::string Key_ratios::get_symbol() const { return symbol; }
std::string Key_ratios::get_date() const { return date; }
std::string Key_ratios::get_calendar_year() const { return calendarYear; }
std::string Key_ratios::get_period() const { return period; }

// Implementations of getters for double members
double Key_ratios::get_revenue_per_share() const { return revenuePerShare; }
double Key_ratios::get_net_income_per_share() const { return netIncomePerShare; }
double Key_ratios::get_operating_cash_flow_per_share() const { return operatingCashFlowPerShare; }
double Key_ratios::get_free_cash_flow_per_share() const { return freeCashFlowPerShare; }
double Key_ratios::get_cash_per_share() const { return cashPerShare; }
double Key_ratios::get_book_value_per_share() const { return bookValuePerShare; }
double Key_ratios::get_tangible_book_value_per_share() const { return tangibleBookValuePerShare; }
double Key_ratios::get_shareholders_equity_per_share() const { return shareholdersEquityPerShare; }
double Key_ratios::get_interest_debt_per_share() const { return interestDebtPerShare; }
double Key_ratios::get_market_cap() const { return marketCap; }
double Key_ratios::get_enterprise_value() const { return enterpriseValue; }
double Key_ratios::get_pe_ratio() const { return peRatio; }
double Key_ratios::get_price_to_sales_ratio() const { return priceToSalesRatio; }
double Key_ratios::get_pocf_ratio() const { return pocfratio; }
double Key_ratios::get_pfcf_ratio() const { return pfcfRatio; }
double Key_ratios::get_pb_ratio() const { return pbRatio; }
double Key_ratios::get_ptb_ratio() const { return ptbRatio; }
double Key_ratios::get_ev_to_sales() const { return evToSales; }
double Key_ratios::get_enterprise_value_over_EBITDA() const { return enterpriseValueOverEBITDA; }
double Key_ratios::get_ev_to_operating_cash_flow() const { return evToOperatingCashFlow; }
double Key_ratios::get_ev_to_free_cash_flow() const { return evToFreeCashFlow; }
double Key_ratios::get_earnings_yield() const { return earningsYield; }
double Key_ratios::get_free_cash_flow_yield() const { return freeCashFlowYield; }
double Key_ratios::get_debt_to_equity() const { return debtToEquity; }
double Key_ratios::get_debt_to_assets() const { return debtToAssets; }
double Key_ratios::get_net_debt_to_EBITDA() const { return netDebtToEBITDA; }
double Key_ratios::get_current_ratio() const { return currentRatio; }
double Key_ratios::get_interest_coverage() const { return interestCoverage; }
double Key_ratios::get_income_quality() const { return incomeQuality; }
double Key_ratios::get_dividend_yield() const { return dividendYield; }
double Key_ratios::get_payout_ratio() const { return payoutRatio; }
double Key_ratios::get_sga_to_revenue() const { return salesGeneralAndAdministrativeToRevenue; }
double Key_ratios::get_rnd_to_revenue() const { return researchAndDdevelopementToRevenue; }
double Key_ratios::get_intangibles_to_total_assets() const { return intangiblesToTotalAssets; }
double Key_ratios::get_capex_to_operating_cash_flow() const { return capexToOperatingCashFlow; }
double Key_ratios::get_capex_to_revenue() const { return capexToRevenue; }
double Key_ratios::get_capex_to_depreciation() const { return capexToDepreciation; }
double Key_ratios::get_stock_based_compensation_to_revenue() const { return stockBasedCompensationToRevenue; }
double Key_ratios::get_graham_number() const { return grahamNumber; }
double Key_ratios::get_roic() const { return roic; }
double Key_ratios::get_return_on_tangible_assets() const { return returnOnTangibleAssets; }
double Key_ratios::get_graham_net_net() const { return grahamNetNet; }
long long Key_ratios::get_working_capital() const { return workingCapital; }
long long Key_ratios::get_tangible_asset_value() const { return tangibleAssetValue; }
long long Key_ratios::get_net_current_asset_value() const { return netCurrentAssetValue; }
double Key_ratios::get_invested_capital() const { return investedCapital; }
long long Key_ratios::get_average_receivables() const { return averageReceivables; }
long long Key_ratios::get_average_payables() const { return averagePayables; }
long long Key_ratios::get_average_inventory() const { return averageInventory; }
double Key_ratios::get_days_sales_outstanding() const { return daysSalesOutstanding; }
double Key_ratios::get_days_payables_outstanding() const { return daysPayablesOutstanding; }
double Key_ratios::get_days_of_inventory_on_hand() const { return daysOfInventoryOnHand; }
double Key_ratios::get_receivables_turnover() const { return receivablesTurnover; }
double Key_ratios::get_payables_turnover() const { return payablesTurnover; }
double Key_ratios::get_inventory_turnover() const { return inventoryTurnover; }
double Key_ratios::get_roe() const { return roe; }
double Key_ratios::get_capex_per_share() const { return capexPerShare; }


std::string Key_ratios::get_class_name() const {
   return  "key_ratios";   
}

std::string trim_kr(const std::string &str){
  size_t first = str.find_first_not_of(" \t\n\r");
  
   if(first == std::string::npos) return "";    
  
   size_t last = str.find_last_not_of(" \t\n\r");
   return str.substr(first, (last - first +1));
}

void Key_ratios::deserialize(std::string &json_string){
    std::string token;
    
    std::string trimmed_json = trim_kr(json_string);
    
    
    if(!trimmed_json.empty() && trimmed_json.back() =='}'){
        trimmed_json.pop_back();
        }
    
    std::istringstream json_stream(trimmed_json);
    
    if(json_stream.peek() == '{'){
            json_stream.get();
    }
    
    while(getline(json_stream, token, ',')){
         auto separator_pos = token.find(':');
         if (separator_pos == std::string::npos) continue; 
         
         auto key = trim_kr(token.substr(0, separator_pos));
         auto value = trim_kr(token.substr(separator_pos + 1));
         
        
        
          
          if (!key.empty() && key.front() == '"' && key.back() == '"') {
            key = key.substr(1, key.size() - 2);
          }
         if(!value.empty() && value.front() == '"' && value.back() =='"'){
             value = value.substr(1, value.size() - 2);
             }

//this line is for debugging 
          //std::cout <<"Key is long : " << key.length() << "and it looks like "+key<< " value is: "<< value <<std::endl;
         
         if(key == "symbol"){symbol = value;}
         if(key == "date"){date = value;}
         if(key == "calendarYear"){calendarYear = value;}
         if(key == "period"){period = value;}
         if(key == "revenuePerShare"&& value != "null"){revenuePerShare = std::stod(value);}
         if(key == "netIncomePerShare"&& value != "null"){ netIncomePerShare= std::stod(value);}
         if(key == "operatingCashFlowPerShare"&& value != "null"){ operatingCashFlowPerShare= std::stod(value);}
         if(key == "freeCashFlowPerShare"&& value != "null"){freeCashFlowPerShare = std::stod(value);}
         if(key == "cashPerShare" && value != "null"){ cashPerShare= std::stod(value);} else {cashPerShare = 0.0;}
         if(key == "bookValuePerShare"&& value != "null"){bookValuePerShare = std::stod(value);} else {bookValuePerShare =0.0;}
         if(key == "tangibleBookValuePerShare" && value != "null"){ tangibleBookValuePerShare = std::stod(value);}
         if(key == "shareholdersEquityPerShare"&& value != "null"){ shareholdersEquityPerShare= std::stod(value);}
         if(key == "interestDebtPerShare"&& value != "null"){ interestDebtPerShare= std::stod(value);}
         if(key == "marketCap"&& value != "null"){marketCap = std::stod(value);}
         if(key == "enterpriseValue"&& value != "null"){ enterpriseValue = std::stod(value);}
         if(key == "peRatio"&& value != "null"){ peRatio= std::stod(value);}
         if(key == "priceToSalesRatio"&& value != "null"){ priceToSalesRatio= std::stod(value);}
         if(key == "pocfratio"&& value != "null"){ pocfratio= std::stod(value);}
         if(key == "pfcfRatio"&& value != "null"){pfcfRatio = std::stod(value);}
         if(key == "pbRatio"&& value != "null"){ pbRatio= std::stod(value);}
         if(key == "ptbRatio"&& value != "null"){ptbRatio = std::stod(value);}
         if(key == "evToSales"&& value != "null"){ evToSales= std::stod(value);}
         if(key == "enterpriseValueOverEBITDA"&& value != "null"){enterpriseValueOverEBITDA = std::stod(value);}
         if(key == "evToOperatingCashFlow"&& value != "null"){evToOperatingCashFlow = std::stod(value);}
         if(key == "evToFreeCashFlow"&& value != "null"){evToFreeCashFlow = std::stod(value);}
         if(key == "earningsYield"&& value != "null"){ earningsYield = std::stod(value);}
         if(key == "freeCashFlowYield"&& value != "null"){freeCashFlowYield = std::stod(value);}
         if(key == "debtToEquity"&& value != "null"){debtToEquity = std::stod(value);}
         if(key == "debtToAssets"&& value != "null"){ debtToAssets= std::stod(value);}
         if(key == "netDebtToEBITDA"&& value != "null"){ netDebtToEBITDA = std::stod(value);}
         if(key == "currentRatio"&& value != "null"){ currentRatio= std::stod(value);}
         if(key == "interestCoverage"&& value != "null"){interestCoverage = std::stod(value);}
         if(key == "incomeQuality"&& value != "null"){incomeQuality = std::stod(value);}
         if(key == "dividendYield"&& value != "null"){dividendYield = std::stod(value);}
         if(key == "payoutRatio"&& value != "null"){ payoutRatio= std::stod(value);}
         if(key == "salesGeneralAndAdministrativeToRevenue"&& value != "null"){ salesGeneralAndAdministrativeToRevenue= std::stod(value);}
         if(key == "researchAndDdevelopementToRevenue"&& value != "null"){ researchAndDdevelopementToRevenue= std::stod(value);}
         if(key == "intangiblesToTotalAssets"&& value != "null"){intangiblesToTotalAssets = std::stod(value);}
         if(key == "capexToOperatingCashFlow"&& value != "null"){ capexToOperatingCashFlow= std::stod(value);}
         if(key == "capexToRevenue"&& value != "null"){capexToRevenue = std::stod(value);}
         if(key == "capexToDepreciation"&& value != "null"){ stockBasedCompensationToRevenue = std::stod(value);}
         if(key == "grahamNumber"&& value != "null"){ grahamNumber= std::stod(value);}
         if(key == "roic"&& value != "null"){ roic= std::stod(value);}
         if(key == "returnOnTangibleAssets"&& value != "null"){ returnOnTangibleAssets= std::stod(value);}
         if(key == "grahamNetNet"&& value != "null"){ grahamNetNet = std::stod(value);}
         //std::cout<< "I am here man\n";
         if(key == "workingCapital" && value!= "null"){ workingCapital= std::stoll(value);} else {workingCapital = 0;}
         if(key == "tangibleAssetValue"&& value != "null"){tangibleAssetValue = std::stoll(value);}
         if(key == "netCurrentAssetValue"&& value != "null"){ netCurrentAssetValue= std::stoll(value);}
         if(key == "investedCapital"&& value != "null"){ investedCapital= std::stod(value);}
         if(key == "averageReceivables" && value != "null"){averageReceivables = std::stoll(value);} else {averageReceivables = 0ll;}
         if(key == "averagePayables" && value != "null" ){ averagePayables= std::stoll(value);} else {averagePayables = 0;}
         if(key == "averageInventory" && value != "null" ){ averageInventory= std::stoll(value);} else {averageInventory = 0;}
         if(key == "daysSalesOutstanding"&& value != "null"){daysSalesOutstanding = std::stod(value);}
         if(key == "daysPayablesOutstanding"&& value != "null"){daysPayablesOutstanding = std::stod(value);}
         if(key == "daysOfInventoryOnHand"&& value != "null"){ daysOfInventoryOnHand= std::stod(value);}
         if(key == "receivablesTurnover"&& value != "null"){ receivablesTurnover = std::stod(value);}
         if(key == "payablesTurnover"&& value != "null"){ payablesTurnover= std::stod(value);}
         if(key == "inventoryTurnover"&& value != "null"){inventoryTurnover = std::stod(value);}
         if(key == "roe"&& value != "null"){ roe= std::stod(value);}
         if(key == "capexPerShare" && value != "null"){ capexPerShare = std::stod(value);} else {capexPerShare = 0.0;}
        
         
         
    }
    
}
// from_json implementation
//
//void from_json(const nlohmann::json &j, Key_ratios& k) {
    // Parsing std::string members with check
    //k.symbol = j.contains("symbol") && !j["symbol"].empty() ? j["symbol"].get<std::string>() : "none";
    //k.date = j.contains("date") && !j["date"].empty() ? j["date"].get<std::string>() : "none";
    //k.calendarYear = j.contains("calendarYear") && !j["calendarYear"].empty() ? j["calendarYear"].get<std::string>() : "none";
    //k.period = j.contains("period") && !j["period"].empty() ? j["period"].get<std::string>() : "none";

    // Parsing double members with check
    //k.revenuePerShare = j.contains("revenuePerShare") ? j["revenuePerShare"].get<double>() : 0.0;
    //k.netIncomePerShare = j.contains("netIncomePerShare") ? j["netIncomePerShare"].get<double>() : 0.0;
    //k.operatingCashFlowPerShare = j.contains("operatingCashFlowPerShare") ? j["operatingCashFlowPerShare"].get<double>() : 0.0;
    //k.freeCashFlowPerShare = j.contains("freeCashFlowPerShare") ? j["freeCashFlowPerShare"].get<double>() : 0.0;
    //k.cashPerShare = j.contains("cashPerShare") ? j["cashPerShare"].get<double>() : 0.0;
    //k.bookValuePerShare = j.contains("bookValuePerShare") ? j["bookValuePerShare"].get<double>() : 0.0;
    //k.tangibleBookValuePerShare = j.contains("tangibleBookValuePerShare") ? j["tangibleBookValuePerShare"].get<double>() : 0.0;
    //k.shareholdersEquityPerShare = j.contains("shareholdersEquityPerShare") ? j["shareholdersEquityPerShare"].get<double>() : 0.0;
    //k.interestDebtPerShare = j.contains("interestDebtPerShare") ? j["interestDebtPerShare"].get<double>() : 0.0;
    //k.marketCap = j.contains("marketCap") ? j["marketCap"].get<double>() : 0.0;
    //k.enterpriseValue = j.contains("enterpriseValue") ? j["enterpriseValue"].get<double>() : 0.0;
    //k.peRatio = j.contains("peRatio") ? j["peRatio"].get<double>() : 0.0;
    //k.priceToSalesRatio = j.contains("priceToSalesRatio") ? j["priceToSalesRatio"].get<double>() : 0.0;
    //k.pocfratio = j.contains("pocfratio") ? j["pocfratio"].get<double>() : 0.0;
    //k.pfcfRatio = j.contains("pfcfRatio") ? j["pfcfRatio"].get<double>() : 0.0;
    //k.pbRatio = j.contains("pbRatio") ? j["pbRatio"].get<double>() : 0.0;
    //k.ptbRatio = j.contains("ptbRatio") ? j["ptbRatio"].get<double>() : 0.0;
    //k.evToSales = j.contains("evToSales") ? j["evToSales"].get<double>() : 0.0;
    //k.enterpriseValueOverEBITDA = j.contains("enterpriseValueOverEBITDA") ? j["enterpriseValueOverEBITDA"].get<double>() : 0.0;
    //k.evToOperatingCashFlow = j.contains("evToOperatingCashFlow") ? j["evToOperatingCashFlow"].get<double>() : 0.0;
    //k.evToFreeCashFlow = j.contains("evToFreeCashFlow") ? j["evToFreeCashFlow"].get<double>() : 0.0;
    //k.earningsYield = j.contains("earningsYield") ? j["earningsYield"].get<double>() : 0.0;
    //k.freeCashFlowYield = j.contains("freeCashFlowYield") ? j["freeCashFlowYield"].get<double>() : 0.0;
    //k.debtToEquity = j.contains("debtToEquity") ? j["debtToEquity"].get<double>() : 0.0;
    //k.debtToAssets = j.contains("debtToAssets") ? j["debtToAssets"].get<double>() : 0.0;
    //k.netDebtToEBITDA = j.contains("netDebtToEBITDA") ? j["netDebtToEBITDA"].get<double>() : 0.0;
    //k.currentRatio = j.contains("currentRatio") ? j["currentRatio"].get<double>() : 0.0;
    //k.interestCoverage = j.contains("interestCoverage") ? j["interestCoverage"].get<double>() : 0.0;
    //k.incomeQuality = j.contains("incomeQuality") ? j["incomeQuality"].get<double>() : 0.0;
    //k.dividendYield = j.contains("dividendYield") ? j["dividendYield"].get<double>() : 0.0;
    //k.payoutRatio = j.contains("payoutRatio") ? j["payoutRatio"].get<double>() : 0.0;
    //k.salesGeneralAndAdministrativeToRevenue = j.contains("salesGeneralAndAdministrativeToRevenue") ? j["salesGeneralAndAdministrativeToRevenue"].get<double>() : 0.0;
    //k.researchAndDdevelopementToRevenue = j.contains("researchAndDdevelopementToRevenue") ? j["researchAndDdevelopementToRevenue"].get<double>() : 0.0;
    //k.intangiblesToTotalAssets = j.contains("intangiblesToTotalAssets") ? j["intangiblesToTotalAssets"].get<double>() : 0.0;
    //k.capexToOperatingCashFlow = j.contains("capexToOperatingCashFlow") ? j["capexToOperatingCashFlow"].get<double>() : 0.0;
    //k.capexToRevenue = j.contains("capexToRevenue") ? j["capexToRevenue"].get<double>() : 0.0;
    //k.capexToDepreciation = j.contains("capexToDepreciation") ? j["capexToDepreciation"].get<double>() : 0.0;
    //k.stockBasedCompensationToRevenue = j.contains("stockBasedCompensationToRevenue") ? j["stockBasedCompensationToRevenue"].get<double>() : 0.0;
    //k.grahamNumber = j.contains("grahamNumber") ? j["grahamNumber"].get<double>() : 0.0;
    //k.roic = j.contains("roic") ? j["roic"].get<double>() : 0.0;
    //k.returnOnTangibleAssets = j.contains("returnOnTangibleAssets") ? j["returnOnTangibleAssets"].get<double>() : 0.0;
    //k.grahamNetNet = j.contains("grahamNetNet") ? j["grahamNetNet"].get<double>() : 0.0;
  //  k.workingCapital = (j.contains("workingCapital") && !j["workingCapital"].empty()) ? j["workingCapital"].get<double>() : 0.0;
    //k.tangibleAssetValue = j.contains("tangibleAssetValue") ? j["tangibleAssetValue"].get<double>() : 0.0;
    //k.netCurrentAssetValue = j.contains("netCurrentAssetValue") ? j["netCurrentAssetValue"].get<double>() : 0.0;
    //k.investedCapital = j.contains("investedCapital") ? j["investedCapital"].get<double>() : 0.0;
    //k.averageReceivables = j.contains("averageReceivables") ? j["averageReceivables"].get<double>() : 0.0;
    //k.averagePayables = j.contains("averagePayables") ? j["averagePayables"].get<double>() : 0.0;
    //k.averageInventory = j.contains("averageInventory") ? j["averageInventory"].get<double>() : 0.0;
   // k.daysSalesOutstanding = j.contains("daysSalesOutstanding") ? j["daysSalesOutstanding"].get<double>() : 0.0;
    //k.daysPayablesOutstanding = j.contains("daysPayablesOutstanding") ? j["daysPayablesOutstanding"].get<double>() : 0.0;
    //k.daysOfInventoryOnHand = j.contains("daysOfInventoryOnHand") ? j["daysOfInventoryOnHand"].get<double>() : 0.0;
    //k.receivablesTurnover = j.contains("receivablesTurnover") ? j["receivablesTurnover"].get<double>() : 0.0;
    //k.payablesTurnover = j.contains("payablesTurnover") ? j["payablesTurnover"].get<double>() : 0.0;
    //k.inventoryTurnover = j.contains("inventoryTurnover") ? j["inventoryTurnover"].get<double>() : 0.0;
    //k.roe = j.contains("roe") ? j["roe"].get<double>() : 0.0;
    //k.capexPerShare = j.contains("capexPerShare") ? j["capexPerShare"].get<double>() : 0.0;
//}


std::string Key_ratios::create_file_name(std::string ticker)const{
       if(ticker.size()==0){
            return symbol + "_" + get_class_name() + ".bin";
        }else {
            return ticker + "_" + get_class_name() + ".bin";    
        }
    
}

size_t Key_ratios::compute_object_size() const {
       size_t total_size {0};
       
       total_size +=  symbol.size() * sizeof(char);
       total_size += date.size()* sizeof(char);
       total_size += calendarYear.size()* sizeof(char);
       total_size += period.size()* sizeof(char);
       
       total_size += sizeof(double) * 51 ;// numbers of double members
       total_size += sizeof(long long) * 6; // numbers of long long memebrs
       total_size += sizeof(size_t) * 4; // number of string memebers
       
       return total_size;
}

void Key_ratios::save_to_file(std::ofstream &out){
    
     size_t obj_size = this-> compute_object_size();
//     std::cout<<obj_size<<std::endl;
     out.write(reinterpret_cast<const char*>(&obj_size), sizeof(obj_size));
    
    
    size_t symbol_len = symbol.size();
    out.write(reinterpret_cast<const char*>(&symbol_len), sizeof(symbol_len));
    out.write(symbol.c_str(), symbol_len);
    
     size_t date_len = date.size();
     out.write(reinterpret_cast<const char*>(&date_len), sizeof(date_len));
     out.write(date.c_str(), date_len);
     
     size_t calendar_year_len = calendarYear.size();
     out.write(reinterpret_cast<const char*>(&calendar_year_len), sizeof(calendar_year_len));
     out.write(calendarYear.c_str(), calendar_year_len);
     
     size_t period_len = period.size();
     out.write(reinterpret_cast<const char*>(&period_len), sizeof(period_len));
     out.write(period.c_str(), period_len);
 
    
     out.write(reinterpret_cast<const char*>(&revenuePerShare), sizeof(revenuePerShare));
     out.write(reinterpret_cast<const char*>(&netIncomePerShare), sizeof(netIncomePerShare));
     out.write(reinterpret_cast<const char*>(&operatingCashFlowPerShare), sizeof(operatingCashFlowPerShare));
     out.write(reinterpret_cast<const char*>(&freeCashFlowPerShare), sizeof(freeCashFlowPerShare));
     out.write(reinterpret_cast<const char*>(&cashPerShare), sizeof(cashPerShare));
     out.write(reinterpret_cast<const char*>(&bookValuePerShare), sizeof(bookValuePerShare));
     out.write(reinterpret_cast<const char*>(&tangibleBookValuePerShare), sizeof(tangibleBookValuePerShare));
     out.write(reinterpret_cast<const char*>(&shareholdersEquityPerShare), sizeof(shareholdersEquityPerShare));
     out.write(reinterpret_cast<const char*>(&interestDebtPerShare), sizeof(interestDebtPerShare));
     out.write(reinterpret_cast<const char*>(&marketCap), sizeof(marketCap));
     out.write(reinterpret_cast<const char*>(&enterpriseValue), sizeof(enterpriseValue));
     out.write(reinterpret_cast<const char*>(&peRatio), sizeof(peRatio));
     out.write(reinterpret_cast<const char*>(&priceToSalesRatio), sizeof(priceToSalesRatio));
     out.write(reinterpret_cast<const char*>(&pocfratio), sizeof(pocfratio));
     out.write(reinterpret_cast<const char*>(&pfcfRatio), sizeof(pfcfRatio));
     out.write(reinterpret_cast<const char*>(&pbRatio), sizeof(pbRatio));
     out.write(reinterpret_cast<const char*>(&ptbRatio), sizeof(ptbRatio));
     out.write(reinterpret_cast<const char*>(&evToSales), sizeof(evToSales));
     out.write(reinterpret_cast<const char*>(&enterpriseValueOverEBITDA), sizeof(enterpriseValueOverEBITDA));
     out.write(reinterpret_cast<const char*>(&evToOperatingCashFlow), sizeof(evToOperatingCashFlow));
     out.write(reinterpret_cast<const char*>(&evToFreeCashFlow), sizeof(evToFreeCashFlow));
     out.write(reinterpret_cast<const char*>(&earningsYield), sizeof(earningsYield));
     out.write(reinterpret_cast<const char*>(&freeCashFlowYield), sizeof(freeCashFlowYield));
     out.write(reinterpret_cast<const char*>(&debtToEquity), sizeof(debtToEquity));
     out.write(reinterpret_cast<const char*>(&debtToAssets), sizeof(debtToAssets));
     out.write(reinterpret_cast<const char*>(&netDebtToEBITDA), sizeof(netDebtToEBITDA));
     out.write(reinterpret_cast<const char*>(&currentRatio), sizeof(currentRatio));
     out.write(reinterpret_cast<const char*>(&interestCoverage), sizeof(interestCoverage));
     out.write(reinterpret_cast<const char*>(&incomeQuality), sizeof(incomeQuality));
     out.write(reinterpret_cast<const char*>(&dividendYield), sizeof(dividendYield));
     out.write(reinterpret_cast<const char*>(&payoutRatio), sizeof(payoutRatio));
     out.write(reinterpret_cast<const char*>(&salesGeneralAndAdministrativeToRevenue), sizeof(salesGeneralAndAdministrativeToRevenue));
     out.write(reinterpret_cast<const char*>(&researchAndDdevelopementToRevenue), sizeof(researchAndDdevelopementToRevenue));
     out.write(reinterpret_cast<const char*>(&intangiblesToTotalAssets), sizeof(intangiblesToTotalAssets));
     out.write(reinterpret_cast<const char*>(&capexToOperatingCashFlow), sizeof(capexToOperatingCashFlow));
     out.write(reinterpret_cast<const char*>(&capexToRevenue), sizeof(capexToRevenue));
     out.write(reinterpret_cast<const char*>(&capexToDepreciation), sizeof(capexToDepreciation));
     out.write(reinterpret_cast<const char*>(&stockBasedCompensationToRevenue), sizeof(stockBasedCompensationToRevenue));
     out.write(reinterpret_cast<const char*>(&grahamNumber), sizeof(grahamNumber));
     out.write(reinterpret_cast<const char*>(&roic), sizeof(roic));
     out.write(reinterpret_cast<const char*>(&returnOnTangibleAssets), sizeof(returnOnTangibleAssets));
     out.write(reinterpret_cast<const char*>(&grahamNetNet), sizeof(grahamNetNet));
      out.write(reinterpret_cast<const char*>(&workingCapital), sizeof(workingCapital));
     out.write(reinterpret_cast<const char*>(&tangibleAssetValue), sizeof(tangibleAssetValue));
      out.write(reinterpret_cast<const char*>(&netCurrentAssetValue), sizeof(netCurrentAssetValue));
     out.write(reinterpret_cast<const char*>(&investedCapital), sizeof(investedCapital));
      out.write(reinterpret_cast<const char*>(&averageReceivables), sizeof(averageReceivables));
     out.write(reinterpret_cast<const char*>(&averagePayables), sizeof(averagePayables));
     out.write(reinterpret_cast<const char*>(&averageInventory), sizeof(averageInventory));
     out.write(reinterpret_cast<const char*>(&daysSalesOutstanding), sizeof(daysSalesOutstanding));
     out.write(reinterpret_cast<const char*>(&daysPayablesOutstanding), sizeof(daysPayablesOutstanding));
     out.write(reinterpret_cast<const char*>(&daysOfInventoryOnHand), sizeof(daysOfInventoryOnHand));
     out.write(reinterpret_cast<const char*>(&receivablesTurnover), sizeof(receivablesTurnover));
     out.write(reinterpret_cast<const char*>(&payablesTurnover), sizeof(payablesTurnover));
     out.write(reinterpret_cast<const char*>(&inventoryTurnover), sizeof(inventoryTurnover));
     out.write(reinterpret_cast<const char*>(&roe), sizeof(roe));
     out.write(reinterpret_cast<const char*>(&capexPerShare), sizeof(capexPerShare));
     
}



bool Key_ratios::read_size_from_buffer_ratios(const std::vector<char> &buffer, size_t &pos, size_t &value){
     if(pos+sizeof(size_t)> buffer.size()) return false;
        std::memcpy(&value, buffer.data() + pos, sizeof(size_t));
        pos += sizeof(size_t);
        
        return true;
    
}
bool Key_ratios::reading_string_from_buffer_ratios(const std::vector<char> &buffer, size_t &pos, std::string &value){
     size_t lenght;
    
    if(!read_size_from_buffer_ratios(buffer,pos,lenght)) return false;
    
    if(pos + lenght > buffer.size())return false;
    
    value.assign(buffer.data() + pos, lenght);
    pos += lenght;
    
    return true;
  
}

template <typename T>
bool read_number_values_from_buffer_ratios(std::vector<char> &buffer, size_t &pos, T &value){
    if(pos + sizeof(T) > buffer.size()) return false;
    
    std::memcpy(&value, buffer.data() + pos, sizeof(T));
    
    pos += sizeof(T);
    return true;
    
}
       

bool Key_ratios::read_from_file(std::ifstream &in,std::vector<Key_ratios*> &ratios){
     
      if (!in){
      std::cerr<< "IO stream it is not open or some error with it inside " + get_class_name() + ".\n";
      return false;   
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
    
//    std::cout<< obj_size;
     Key_ratios* ratio = new Key_ratios();
     std::vector<char> buffer(obj_size);
     
     if(!in.read(buffer.data(),obj_size)){
         std::cerr<< "failed to read object data from file class "<< get_class_name()<<"\n";
         return false;
      }
       
         size_t bytes_read = in.gcount();
         
        if (bytes_read != obj_size) {
            delete ratio; // Clean up on error
            return false;
        }

        size_t pos = 0;
        
       
        if(!reading_string_from_buffer_ratios(buffer, pos,ratio ->symbol)){
            std::cerr << "Error reading 'symbol' in " << get_class_name() << std::endl;
            }
         if(!reading_string_from_buffer_ratios(buffer, pos,ratio ->date)){
            std::cerr << "Error reading 'date' in " << get_class_name() << std::endl;
            }
         if(!reading_string_from_buffer_ratios(buffer, pos,ratio ->calendarYear)){
            std::cerr << "Error reading 'calendarYear' in " << get_class_name() << std::endl;
            }
          if(!reading_string_from_buffer_ratios(buffer, pos,ratio ->period)){
            std::cerr << "Error reading 'period' in " << get_class_name() << std::endl;
            }
    

           if(!read_number_values_from_buffer_ratios(buffer, pos, ratio -> revenuePerShare)){
                std::cerr << "Error reading 'revenuePerShare' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->netIncomePerShare)){
                std::cerr << "Error reading 'netIncomePerShare' in " << get_class_name() << std::endl;
               }
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->operatingCashFlowPerShare)){
                std::cerr << "Error reading 'operatingCashFlowPerShare' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->freeCashFlowPerShare)){
                std::cerr << "Error reading 'freeCashFlowPerShare' in " << get_class_name() << std::endl;
               }
               
              if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->cashPerShare)){
                std::cerr << "Error reading 'cashPerShare' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->bookValuePerShare)){
                std::cerr << "Error reading 'bookValuePerShare' in " << get_class_name() << std::endl;
               }

             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->tangibleBookValuePerShare)){
                std::cerr << "Error reading 'tangibleBookValuePerShare' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->shareholdersEquityPerShare)){
                std::cerr << "Error reading 'shareholdersEquityPerShare' in " << get_class_name() << std::endl;
               }  
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio -> interestDebtPerShare)){
                std::cerr << "Error reading 'interestDebtPerShare' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->marketCap)){
                std::cerr << "Error reading 'marketCap' in " << get_class_name() << std::endl;
               }
               
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->enterpriseValue)){
                std::cerr << "Error reading 'enterpriseValue' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->peRatio)){
                std::cerr << "Error reading 'peRatio' in " << get_class_name() << std::endl;
               }
               
              if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->priceToSalesRatio)){
                std::cerr << "Error reading 'priceToSalesRatio' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->pocfratio)){
                std::cerr << "Error reading 'pocfratio' in " << get_class_name() << std::endl;
               }
               
               if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->pfcfRatio)){
                std::cerr << "Error reading 'pocfratio' in " << get_class_name() << std::endl;
               }

             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->pbRatio)){
                std::cerr << "Error reading 'pbRatio' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->ptbRatio)){
                std::cerr << "Error reading 'ptbRatio' in " << get_class_name() << std::endl;
               }  
               
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->evToSales)){
                std::cerr << "Error reading 'evToSales' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->enterpriseValueOverEBITDA)){
                std::cerr << "Error reading 'enterpriseValueOverEBITDA' in " << get_class_name() << std::endl;
               }
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->evToOperatingCashFlow)){
                std::cerr << "Error reading 'evToOperatingCashFlow' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->evToFreeCashFlow)){
                std::cerr << "Error reading 'evToFreeCashFlow' in " << get_class_name() << std::endl;
               }
               
              if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->earningsYield)){
                std::cerr << "Error reading 'earningsYield' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->freeCashFlowYield)){
                std::cerr << "Error reading 'freeCashFlowYield' in " << get_class_name() << std::endl;
               }
               
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->debtToEquity)){
                std::cerr << "Error reading 'debtToEquity' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->debtToAssets)){
                std::cerr << "Error reading 'debtToAssets' in " << get_class_name() << std::endl;
               }    
            
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->netDebtToEBITDA)){
                std::cerr << "Error reading 'netDebtToEBITDA' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->currentRatio)){
                std::cerr << "Error reading 'currentRatio' in " << get_class_name() << std::endl;
               }
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->interestCoverage)){
                std::cerr << "Error reading 'interestCoverage' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->incomeQuality)){
                std::cerr << "Error reading 'incomeQuality' in " << get_class_name() << std::endl;
               }    
            
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->dividendYield)){
                std::cerr << "Error reading 'dividendYield' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->payoutRatio)){
                std::cerr << "Error reading 'payoutRatio' in " << get_class_name() << std::endl;
               }    
               
\
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->salesGeneralAndAdministrativeToRevenue)){
                std::cerr << "Error reading 'salesGeneralAndAdministrativeToRevenue' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->researchAndDdevelopementToRevenue)){
                std::cerr << "Error reading 'researchAndDdevelopementToRevenue' in " << get_class_name() << std::endl;
               }    
            
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->intangiblesToTotalAssets)){
                std::cerr << "Error reading 'intangiblesToTotalAssets' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->capexToOperatingCashFlow)){
                std::cerr << "Error reading 'capexToOperatingCashFlow' in " << get_class_name() << std::endl;
               }
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->capexToRevenue)){
                std::cerr << "Error reading 'capexToRevenue' in " << get_class_name() << std::endl;
               } 
                    if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->capexToDepreciation)){
                std::cerr << "Error reading 'capexToRevenue' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->stockBasedCompensationToRevenue)){
                std::cerr << "Error reading 'stockBasedCompensationToRevenue' in " << get_class_name() << std::endl;
               }    
            
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->grahamNumber)){
                std::cerr << "Error reading 'grahamNumber' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->roic)){
                std::cerr << "Error reading 'roic' in " << get_class_name() << std::endl;
               }    
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->returnOnTangibleAssets)){
                std::cerr << "Error reading 'returnOnTangibleAssets' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->grahamNetNet)){
                std::cerr << "Error reading 'grahamNetNet' in " << get_class_name() << std::endl;
               }    
            
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio -> workingCapital)){
                std::cerr << "Error reading 'workingCapital' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->tangibleAssetValue)){
                std::cerr << "Error reading 'tangibleAssetValue' in " << get_class_name() << std::endl;
               }
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->netCurrentAssetValue)){
                std::cerr << "Error reading 'netCurrentAssetValue' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->investedCapital)){
                std::cerr << "Error reading 'investedCapital' in " << get_class_name() << std::endl;
               }    
            
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->averageReceivables)){
                std::cerr << "Error reading 'averageReceivables' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio -> averagePayables)){
                std::cerr << "Error reading 'averagePayables' in " << get_class_name() << std::endl;
               }    
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->averageInventory)){
                std::cerr << "Error reading 'averageInventory' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->daysSalesOutstanding)){
                std::cerr << "Error reading 'daysSalesOutstanding' in " << get_class_name() << std::endl;
               }    
            
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->daysPayablesOutstanding)){
                std::cerr << "Error reading 'daysPayablesOutstanding' in " << get_class_name() << std::endl;
               } 

            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio -> daysOfInventoryOnHand)){
                std::cerr << "Error reading 'daysOfInventoryOnHand' in " << get_class_name() << std::endl;
               }
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->receivablesTurnover)){
                std::cerr << "Error reading 'receivablesTurnover' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->payablesTurnover)){
                std::cerr << "Error reading 'payablesTurnover' in " << get_class_name() << std::endl;
               }    
            
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->inventoryTurnover)){
                std::cerr << "Error reading '' in " << get_class_name() << std::endl;
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio -> roe)){
                std::cerr << "Error reading 'roe' in " << get_class_name() << std::endl;
               }  

              if(!read_number_values_from_buffer_ratios(buffer, pos, ratio -> capexPerShare)){
                std::cerr << "Error reading 'capexPerShare' in " << get_class_name() << std::endl;
               }    
               
//               std::cout<<"Hey till here seems everything fine\n ";
//               std::cout<<"this is right before putting the ratio inside the vector\n";
//              
               
           
           // Check if entire object was read
        if (pos != obj_size) {
            std::cerr << "Mismatch in object size and bytes read for " << get_class_name() << std::endl;
            delete ratio;
            return false;
        }
        
        ratios.push_back(ratio);
               
    }
    
    return true;
    
}
   