#include "Keyratios.h"
#include "Logger.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstring>


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
         if(key == "cashPerShare" && value != "null"){ cashPerShare= std::stod(value);} //else {cashPerShare = 0.0;}
         if(key == "bookValuePerShare"&& value != "null"){bookValuePerShare = std::stod(value);} //else {bookValuePerShare =0.0;}
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
         if(key == "workingCapital" && value!= "null"){ workingCapital= std::stoll(value);} //else {workingCapital = 0;}
         if(key == "tangibleAssetValue"&& value != "null"){tangibleAssetValue = std::stoll(value);}
         if(key == "netCurrentAssetValue"&& value != "null"){ netCurrentAssetValue= std::stoll(value);}
         if(key == "investedCapital"&& value != "null"){ investedCapital= std::stod(value);}
         if(key == "averageReceivables" && value != "null"){averageReceivables = std::stoll(value);} //else {averageReceivables = 0ll;}
         if(key == "averagePayables" && value != "null" ){ averagePayables= std::stoll(value);} //else {averagePayables = 0;}
         if(key == "averageInventory" && value != "null" ){ averageInventory= std::stoll(value);}// else {averageInventory = 0;}
         if(key == "daysSalesOutstanding"&& value != "null"){daysSalesOutstanding = std::stod(value);}
         if(key == "daysPayablesOutstanding"&& value != "null"){daysPayablesOutstanding = std::stod(value);}
         if(key == "daysOfInventoryOnHand"&& value != "null"){ daysOfInventoryOnHand= std::stod(value);}
         if(key == "receivablesTurnover"&& value != "null"){ receivablesTurnover = std::stod(value);}
         if(key == "payablesTurnover"&& value != "null"){ payablesTurnover= std::stod(value);}
         if(key == "inventoryTurnover"&& value != "null"){inventoryTurnover = std::stod(value);}
         if(key == "roe"&& value != "null"){ roe= std::stod(value);}
         if(key == "capexPerShare" && value != "null"){ capexPerShare = std::stod(value);}// else {capexPerShare = 0.0;}
        
         
         
    }
    
}

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
      Logger logger("read_kr_f.log");
      
      if (!in){
      logger.log("IO stream it is not open or some error with it inside " + get_class_name(), Logger::Level::Error);
      return false;   
    }
    
    
    while(in && !in.eof()){
 
    size_t obj_size;
    
    if(!in.read(reinterpret_cast<char*>(&obj_size), sizeof(obj_size))){
        if(in.eof()){
            break;
        }  
        logger.log("Couldn't read object size from the file regrading class "+ get_class_name(),Logger::Level::Error);
        return false;
    }
    
//    std::cout<< obj_size;
     Key_ratios* ratio = new Key_ratios();
     std::vector<char> buffer(obj_size);
     
     if(!in.read(buffer.data(),obj_size)){
         logger.log("failed to read object data from file class " + get_class_name(),Logger::Level::Error);
         return false;
      }
       
         size_t bytes_read = in.gcount();
         
        if (bytes_read != obj_size) {
            delete ratio; // Clean up on error
            return false;
        }

        size_t pos = 0;
        
       
        if(!reading_string_from_buffer_ratios(buffer, pos,ratio ->symbol)){
            logger.log("Error reading 'symbol' in "  + get_class_name(), Logger::Level::Error);
            }
         if(!reading_string_from_buffer_ratios(buffer, pos,ratio ->date)){
            logger.log("Error reading 'date' in " + get_class_name(), Logger::Level::Error);
            }
         if(!reading_string_from_buffer_ratios(buffer, pos,ratio ->calendarYear)){
            logger.log("Error reading 'calendarYear' in " + get_class_name(), Logger::Level::Error);
            }
          if(!reading_string_from_buffer_ratios(buffer, pos,ratio ->period)){
            logger.log("Error reading 'period' in " + get_class_name(), Logger::Level::Error);
            }
    

           if(!read_number_values_from_buffer_ratios(buffer, pos, ratio -> revenuePerShare)){
                logger.log("Error reading 'revenuePerShare' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->netIncomePerShare)){
                logger.log("Error reading 'netIncomePerShare' in " + get_class_name(), Logger::Level::Error);
               }
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->operatingCashFlowPerShare)){
                logger.log("Error reading 'operatingCashFlowPerShare' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->freeCashFlowPerShare)){
                logger.log("Error reading 'freeCashFlowPerShare' in " + get_class_name(), Logger::Level::Error);
               }
               
              if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->cashPerShare)){
                logger.log("Error reading 'cashPerShare' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->bookValuePerShare)){
                logger.log("Error reading 'bookValuePerShare' in " + get_class_name(), Logger::Level::Error);
               }

             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->tangibleBookValuePerShare)){
                logger.log("Error reading 'tangibleBookValuePerShare' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->shareholdersEquityPerShare)){
                logger.log("Error reading 'shareholdersEquityPerShare' in " + get_class_name(), Logger::Level::Error);
               }  
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio -> interestDebtPerShare)){
                logger.log("Error reading 'interestDebtPerShare' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->marketCap)){
                logger.log("Error reading 'marketCap' in " + get_class_name(), Logger::Level::Error);
               }
               
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->enterpriseValue)){
                logger.log("Error reading 'enterpriseValue' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->peRatio)){
                logger.log("Error reading 'peRatio' in " + get_class_name(), Logger::Level::Error);
               }
               
              if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->priceToSalesRatio)){
                logger.log("Error reading 'priceToSalesRatio' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->pocfratio)){
                logger.log("Error reading 'pocfratio' in " + get_class_name(), Logger::Level::Error);
               }
               
               if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->pfcfRatio)){
                logger.log("Error reading 'pocfratio' in " + get_class_name(), Logger::Level::Error);
               }

             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->pbRatio)){
                logger.log("Error reading 'pbRatio' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->ptbRatio)){
               logger.log("Error reading 'ptbRatio' in " + get_class_name(), Logger::Level::Error);
               }  
               
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->evToSales)){
                logger.log("Error reading 'evToSales' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->enterpriseValueOverEBITDA)){
                logger.log("Error reading 'enterpriseValueOverEBITDA' in " + get_class_name(), Logger::Level::Error);
               }
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->evToOperatingCashFlow)){
                logger.log("Error reading 'evToOperatingCashFlow' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->evToFreeCashFlow)){
                logger.log("Error reading 'evToFreeCashFlow' in " + get_class_name(), Logger::Level::Error);
               }
               
              if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->earningsYield)){
                logger.log("Error reading 'earningsYield' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->freeCashFlowYield)){
                logger.log("Error reading 'freeCashFlowYield' in " + get_class_name(), Logger::Level::Error);
               }
               
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->debtToEquity)){
                logger.log("Error reading 'debtToEquity' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->debtToAssets)){
                logger.log("Error reading 'debtToAssets' in " + get_class_name(), Logger::Level::Error);
               }    
            
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->netDebtToEBITDA)){
                logger.log("Error reading 'netDebtToEBITDA' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->currentRatio)){
                logger.log("Error reading 'currentRatio' in " + get_class_name(), Logger::Level::Error);
               }
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->interestCoverage)){
                logger.log("Error reading 'interestCoverage' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->incomeQuality)){
                logger.log("Error reading 'incomeQuality' in " + get_class_name(), Logger::Level::Error);
               }    
            
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->dividendYield)){
                logger.log("Error reading 'dividendYield' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->payoutRatio)){
                logger.log("Error reading 'payoutRatio' in "  + get_class_name(), Logger::Level::Error);
               }    
               
\
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->salesGeneralAndAdministrativeToRevenue)){
                logger.log("Error reading 'salesGeneralAndAdministrativeToRevenue' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->researchAndDdevelopementToRevenue)){
                logger.log("Error reading 'researchAndDdevelopementToRevenue' in " + get_class_name(), Logger::Level::Error);
               }    
            
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->intangiblesToTotalAssets)){
                logger.log("Error reading 'intangiblesToTotalAssets' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->capexToOperatingCashFlow)){
                logger.log("Error reading 'capexToOperatingCashFlow' in " + get_class_name(), Logger::Level::Error);
               }
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->capexToRevenue)){
                logger.log("Error reading 'capexToRevenue' in " + get_class_name(), Logger::Level::Error);
               } 
                    if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->capexToDepreciation)){
                logger.log("Error reading 'capexToRevenue' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->stockBasedCompensationToRevenue)){
                logger.log("Error reading 'stockBasedCompensationToRevenue' in " + get_class_name(), Logger::Level::Error);
               }    
            
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->grahamNumber)){
                logger.log("Error reading 'grahamNumber' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->roic)){
                logger.log("Error reading 'roic' in " + get_class_name(), Logger::Level::Error);
               }    
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->returnOnTangibleAssets)){
                logger.log("Error reading 'returnOnTangibleAssets' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->grahamNetNet)){
                logger.log("Error reading 'grahamNetNet' in " + get_class_name(), Logger::Level::Error);
               }    
            
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio -> workingCapital)){
                logger.log("Error reading 'workingCapital' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->tangibleAssetValue)){
                logger.log("Error reading 'tangibleAssetValue' in " + get_class_name(), Logger::Level::Error);
               }
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->netCurrentAssetValue)){
                logger.log("Error reading 'netCurrentAssetValue' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->investedCapital)){
                logger.log("Error reading 'investedCapital' in " + get_class_name(), Logger::Level::Error);
               }    
            
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->averageReceivables)){
                logger.log("Error reading 'averageReceivables' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio -> averagePayables)){
                logger.log("Error reading 'averagePayables' in " + get_class_name(), Logger::Level::Error);
               }    
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->averageInventory)){
                logger.log("Error reading 'averageInventory' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->daysSalesOutstanding)){
                logger.log("Error reading 'daysSalesOutstanding' in " + get_class_name(), Logger::Level::Error);
               }    
            
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->daysPayablesOutstanding)){
                logger.log("Error reading 'daysPayablesOutstanding' in " + get_class_name(), Logger::Level::Error);
               } 

            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio -> daysOfInventoryOnHand)){
               logger.log("Error reading 'daysOfInventoryOnHand' in " + get_class_name(), Logger::Level::Error);
               }
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->receivablesTurnover)){
                logger.log("Error reading 'receivablesTurnover' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->payablesTurnover)){
                logger.log("Error reading 'payablesTurnover' in " + get_class_name(), Logger::Level::Error);
               }    
            
             if(!read_number_values_from_buffer_ratios(buffer, pos, ratio ->inventoryTurnover)){
                logger.log("Error reading '' in " + get_class_name(), Logger::Level::Error);
               } 
            if(!read_number_values_from_buffer_ratios(buffer, pos, ratio -> roe)){
                logger.log("Error reading 'roe' in " + get_class_name(), Logger::Level::Error);
               }  

              if(!read_number_values_from_buffer_ratios(buffer, pos, ratio -> capexPerShare)){
                logger.log("Error reading 'capexPerShare' in " + get_class_name(), Logger::Level::Error);
               }    
               
//               std::cout<<"Hey till here seems everything fine\n ";
//               std::cout<<"this is right before putting the ratio inside the vector\n";
//              
               
           
           // Check if entire object was read
        if (pos != obj_size) {
            logger.log("Mismatch in object size and bytes read for " + get_class_name(), Logger::Level::Error);
            delete ratio;
            return false;
        }
        
        ratios.push_back(ratio);
               
    }
    
    return true;
    
}
   
