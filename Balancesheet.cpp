#include "Balancesheet.h"
#include "Trim.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include "Logger.h"


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

void Balancesheet::deserialize(std::string &json_string){
    std::string token;
    
    std::string trimmed_json = trim(json_string);
    
    
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
         
         auto key = trim(token.substr(0, separator_pos));
         auto value = trim(token.substr(separator_pos + 1));
         
        
        
          
          if (!key.empty() && key.front() == '"' && key.back() == '"') {
            key = key.substr(1, key.size() - 2);
          }
         if(!value.empty() && value.front() == '"' && value.back() =='"'){
             value = value.substr(1, value.size() - 2);
             }

//this line is for debugging 
//          std::cout <<"Key is long : " << key.length() << "and it looks like"+key<< std::endl;
          
          
         if(key == "date"){date = value;}
         if(key == "symbol"){symbol = value;}
         if(key == "reportedCurrency"){reportedCurrency = value;}
         if(key == "cik"){cik = value;}
         if(key == "fillingDate"){fillingDate = value;}
         if(key == "acceptedDate"){acceptedDate = value;}
         if(key == "calendarYear"){calendarYear = value;}
         if(key == "period"){period = value;}
         if(key == "cashAndCashEquivalents" && value != "null"){cashAndCashEquivalents = std::stoll(value);}
         if(key == "shortTermInvestments"&& value != "null"){shortTermInvestments = std::stoll(value);}
         if(key == "cashAndShortTermInvestments"&& value != "null"){cashAndShortTermInvestments = std::stoll(value);}
         if(key == "netReceivables"&& value != "null"){netReceivables = std::stoll(value);}
         if(key == "inventory"&& value != "null"){inventory = std::stoll(value);}
         if(key == "otherCurrentAssets"&& value != "null"){otherCurrentAssets = std::stoll(value);}
         if(key == "totalCurrentAssets"&& value != "null"){totalCurrentAssets = std::stoll(value);}
         if(key == "propertyPlantEquipmentNet"&& value != "null"){propertyPlantEquipmentNet = std::stoll(value);}
         if(key == "goodwill"&& value != "null"){goodwill = std::stoll(value);}
         if(key == "intangibleAssets"&& value != "null"){intangibleAssets = std::stoll(value);}
         if(key == "goodwillAndIntangibleAssets"&& value != "null"){goodwillAndIntangibleAssets = std::stoll(value);}
         if(key == "longTermInvestments"&& value != "null"){longTermInvestments = std::stoll(value);}
         if(key == "taxAssets"&& value != "null"){taxAssets = std::stoll(value);}
         if(key == "otherNonCurrentAssets"&& value != "null"){ otherNonCurrentAssets= std::stoll(value);}
         if(key == "totalNonCurrentAssets"&& value != "null"){ totalNonCurrentAssets= std::stoll(value);}
         if(key == "otherAssets"&& value != "null"){ otherAssets= std::stoll(value);}
         if(key == "totalAssets"&& value != "null"){ totalAssets= std::stoll(value);}
         if(key == "accountPayables"&& value != "null"){ accountPayables = std::stoll(value);}
         if(key == "shortTermDebt"&& value != "null"){ shortTermDebt= std::stoll(value);}
         if(key == "taxPayables"&& value != "null"){ taxPayables= std::stoll(value);}
         if(key == "deferredRevenue"&& value != "null"){ deferredRevenue= std::stoll(value);}
         if(key == "otherCurrentLiabilities"&& value != "null"){ otherCurrentLiabilities = std::stoll(value);}
         if(key == "totalCurrentLiabilities"&& value != "null"){ totalCurrentLiabilities = std::stoll(value);}
         if(key == "longTermDebt"&& value != "null"){ longTermDebt= std::stoll(value);}
         if(key == "deferredRevenueNonCurrent"&& value != "null"){deferredRevenueNonCurrent = std::stoll(value);}
         if(key == "deferredTaxLiabilitiesNonCurrent"&& value != "null"){deferredTaxLiabilitiesNonCurrent= std::stoll(value);}
         if(key == "otherNonCurrentLiabilities"&& value != "null"){otherNonCurrentLiabilities= std::stoll(value);}
         if(key == "totalNonCurrentLiabilities"&& value != "null"){totalNonCurrentLiabilities= std::stoll(value);}
         if(key == "otherLiabilities"&& value != "null"){otherLiabilities= std::stoll(value);}
         if(key == "capitalLeaseObligations"&& value != "null"){capitalLeaseObligations= std::stoll(value);}
         if(key == "totalLiabilities"&& value != "null"){totalLiabilities= std::stoll(value);}
         if(key == "preferredStock"&& value != "null"){preferredStock= std::stoll(value);}
         if(key == "commonStock"&& value != "null"){commonStock= std::stoll(value);}
         if(key == "retainedEarnings"&& value != "null"){retainedEarnings= std::stoll(value);}
         if(key == "accumulatedOtherComprehensiveIncomeLoss"&& value != "null"){accumulatedOtherComprehensiveIncomeLoss= std::stoll(value);}
         if(key == "othertotalStockholdersEquity"&& value != "null"){othertotalStockholdersEquity= std::stoll(value);}
         if(key == "totalStockholdersEquity"&& value != "null"){totalStockholdersEquity= std::stoll(value);}
         if(key == "totalEquity"&& value != "null"){ totalEquity= std::stoll(value);}
         if(key == "totalLiabilitiesAndStockholdersEquity"&& value != "null"){totalLiabilitiesAndStockholdersEquity= std::stoll(value);}
         if(key == "minorityInterest"&& value != "null"){minorityInterest= std::stoll(value);}
         if(key == "totalLiabilitiesAndTotalEquity"&& value != "null"){totalLiabilitiesAndTotalEquity = std::stoll(value);}
         if(key == "totalInvestments"&& value != "null"){totalInvestments = std::stoll(value);}
         if(key == "totalDebt"&& value != "null"){totalDebt = std::stoll(value);}
         if(key == "netDebt"&& value != "null"){netDebt = std::stoll(value);}
         if(key == "link"){link = value;}
         if(key == "finalLink"){finalLink = value;}
    
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

bool Balancesheet::read_size_from_buffer_balance(const std::vector<char> &buffer, size_t &pos, size_t &value){
        
        if(pos+sizeof(size_t)> buffer.size()) return false;
        std::memcpy(&value, buffer.data() + pos, sizeof(size_t));
        pos += sizeof(size_t);
        
        return true;
    
}

bool Balancesheet::reading_string_from_buffer_balance(const std::vector<char> &buffer, size_t &pos, std::string &value){
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
     Logger logger("read_bs_f.log");
 
    if (!in){
      logger.log("IO stream it is not open or some error with it. "+ get_class_name() +"\n", Logger::Level::Error);  
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
         
         logger.log("failed to read object data from file class " +get_class_name() +"\n",Logger::Level::Error );
         return false;
      }
      
      
      
            size_t bytes_read = in.gcount();
        if (bytes_read != obj_size) {
            delete statement; // Clean up on error
            return false;
        }
        size_t pos = 0;
        
       
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->date)){
            logger.log("Error reading 'date' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->symbol)){
             logger.log("Error reading 'symbol' in "+ get_class_name(), Logger::Level::Error);
             }
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->reportedCurrency)){
            logger.log("Error reading 'reportedCurrency' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->cik)){
             logger.log("Error reading 'cik' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->fillingDate)){
             logger.log("Error reading 'fillingDate' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->acceptedDate)){
             logger.log("Error reading 'acceptedDate' in " + get_class_name(), Logger::Level::Error);
            }
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->calendarYear)){
             logger.log("Error reading 'calendarYear' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->period)){
             logger.log("Error reading 'period' in "+ get_class_name(), Logger::Level::Error);
            }
        
        //numbers value

        if(!read_number_values_from_buffer(buffer, pos,statement -> cashAndCashEquivalents)){
             logger.log("Error reading 'cashAndCashEquivalents' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->shortTermInvestments)){
            logger.log("Error reading 'shortTermInvestments' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->cashAndShortTermInvestments)){
            logger.log("Error reading 'cashAndShortTermInvestments' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->netReceivables)){
            logger.log("Error reading 'netReceivables' in " + get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->inventory)){
            logger.log("Error reading 'inventory' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->otherCurrentAssets)){
            logger.log("Error reading 'otherCurrentAssets' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalCurrentAssets)){
            logger.log("Error reading 'totalCurrentAssets' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->propertyPlantEquipmentNet)){
            logger.log("Error reading 'propertyPlantEquipmentNet' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->goodwill)){
            logger.log("Error reading 'goodwill' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->intangibleAssets)){
            logger.log("Error reading 'intangibleAssets' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->goodwillAndIntangibleAssets)){
            logger.log("Error reading 'goodwillAndIntangibleAssets' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->longTermInvestments)){
            logger.log("Error reading 'longTermInvestments' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->taxAssets)){
            logger.log("Error reading 'taxAssets' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->otherNonCurrentAssets)){
            logger.log("Error reading 'otherNonCurrentAssets' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalNonCurrentAssets)){
            logger.log("Error reading 'totalNonCurrentAssets' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->otherAssets)){
            logger.log("Error reading 'otherAssets' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalAssets)){
            logger.log("Error reading 'totalAssets' in " + get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->accountPayables)){
            logger.log("Error reading 'accountPayables' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->shortTermDebt)){
            logger.log("Error reading 'shortTermDebt' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->taxPayables)){
            logger.log("Error reading 'taxPayables' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->deferredRevenue)){
            logger.log("Error reading 'deferredRevenue' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->otherCurrentLiabilities)){
            logger.log("Error reading 'otherCurrentLiabilities' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalCurrentLiabilities)){
            logger.log("Error reading 'totalCurrentLiabilities' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->longTermDebt)){
            logger.log("Error reading 'longTermDebt' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->deferredRevenueNonCurrent)){
            logger.log("Error reading 'deferredRevenueNonCurrent' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->deferredTaxLiabilitiesNonCurrent)){
            logger.log("Error reading 'deferredTaxLiabilitiesNonCurrent' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->otherNonCurrentLiabilities)){
            logger.log("Error reading 'otherNonCurrentLiabilities' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalNonCurrentLiabilities)){
            logger.log("Error reading 'totalNonCurrentLiabilities' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->otherLiabilities)){
            logger.log("Error reading 'otherLiabilities' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->capitalLeaseObligations)){
            logger.log("Error reading 'capitalLeaseObligations' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalLiabilities)){
            logger.log("Error reading 'totalLiabilities' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->preferredStock)){
            logger.log("Error reading 'preferredStock' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->commonStock)){
            logger.log("Error reading 'commonStock' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->retainedEarnings)){
            logger.log("Error reading 'retainedEarnings' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->accumulatedOtherComprehensiveIncomeLoss)){
            logger.log("Error reading 'accumulatedOtherComprehensiveIncomeLoss' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->othertotalStockholdersEquity)){
            logger.log("Error reading 'othertotalStockholdersEquity' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalStockholdersEquity)){
            logger.log("Error reading 'totalStockholdersEquity' in " + get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalEquity)){
            logger.log("Error reading 'totalEquity' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalLiabilitiesAndStockholdersEquity)){
           logger.log("Error reading 'totalLiabilitiesAndStockholdersEquity' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->minorityInterest)){
            logger.log("Error reading 'minorityInterest' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalLiabilitiesAndTotalEquity)){
            logger.log("Error reading 'totalLiabilitiesAndTotalEquity' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalInvestments)){
            logger.log("Error reading 'totalInvestments' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->totalDebt)){
            logger.log("Error reading 'totalDebt' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer(buffer, pos,statement ->netDebt)){
            logger.log("Error reading 'netDebt' in " + get_class_name(),Logger::Level::Error);
            }
        
        //std::string value
        
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->link)){
            
            logger.log("Erraor reading 'link' in "+ get_class_name(), Logger::Level::Error);
            
            }
        if(!reading_string_from_buffer_balance(buffer, pos,statement ->finalLink)){
            logger.log("Error reading 'finalLink' in "+ get_class_name(), Logger::Level::Error);
            statement -> finalLink ="nf";
            } 
        
          
         if(statement != nullptr){
             
             statements.push_back(statement);
         }else {
           logger.log("there is no value in this ptr " + get_class_name(), Logger::Level::Warning);   
             
         }
         
         
        if(bytes_read  < buffer.size()){
           
            logger.log("Reached EOF! no more data to read in for " + get_class_name(),Logger::Level::Error);
            return false;
            
            }
       
     }


    return true;
    
    
}
