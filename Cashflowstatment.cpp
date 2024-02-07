#include <iostream>
#include "Cashflowstatement.h"
#include "Logger.h"
#include <fstream>
#include <sstream>
#include <cstring>

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

std::string Cashflowstatement::get_accepted_date() const {
    return acceptedDate;
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


std::string trim_cashflow(const std::string &str){
  size_t first = str.find_first_not_of(" \t\n\r");
  
  if(first == std::string::npos) return "";    
  
   size_t last = str.find_last_not_of(" \t\n\r");
   return str.substr(first, (last - first +1));
}

void Cashflowstatement::deserialize(std::string &json_string){
    std::string token;
    
    std::string trimmed_json = trim_cashflow(json_string);
    
    
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
         
         auto key = trim_cashflow(token.substr(0, separator_pos));
         auto value = trim_cashflow(token.substr(separator_pos + 1));
         
        
        
          
          if (!key.empty() && key.front() == '"' && key.back() == '"') {
            key = key.substr(1, key.size() - 2);
          }
         if(!value.empty() && value.front() == '"' && value.back() =='"'){
             value = value.substr(1, value.size() - 2);
             }

//this line is for debugging 
 //         std::cout <<"Key is long : " << key.length() << "and it looks like"+key<< std::endl;
         
         if(key == "date"){date = value;}
         if(key == "symbol"){symbol = value;}
         if(key == "reportedCurrency"){reportedCurrency = value;}
         if(key == "cik"){cik = value;}
         if(key == "fillingDate"){fillingDate = value;}
         if(key == "acceptedDate"){acceptedDate = value;}
         if(key == "calendarYear"){calendarYear = value;}
         if(key == "period"){period = value;}
         if(key == "netIncome" && value != "null"){ netIncome= std::stoll(value);}
         if(key == "depreciationAndAmortization" && value != "null"){ depreciationAndAmortization= std::stoll(value);}
         if(key == "deferredIncomeTax" && value != "null"){deferredIncomeTax = std::stoll(value);}
         if(key == "stockBasedCompensation" && value != "null"){ stockBasedCompensation= std::stoll(value);}
         if(key == "changeInWorkingCapital" && value != "null"){ changeInWorkingCapital= std::stoll(value);}
         if(key == "accountsReceivables" && value != "null"){ accountsReceivables= std::stoll(value);}
         if(key == "inventory" && value != "null"){ inventory = std::stoll(value);}
         if(key == "accountsPayables" && value != "null"){ accountsPayables = std::stoll(value);}
         if(key == "otherWorkingCapital" && value != "null"){otherWorkingCapital = std::stoll(value);}
         if(key == "otherNonCashItems" && value != "null"){otherNonCashItems = std::stoll(value);}
         if(key == "netCashProvidedByOperatingActivities" && value != "null"){netCashProvidedByOperatingActivities = std::stoll(value);}
         if(key == "investmentsInPropertyPlantAndEquipment" && value != "null"){investmentsInPropertyPlantAndEquipment = std::stoll(value);}
         if(key == "acquisitionsNet" && value != "null"){ acquisitionsNet= std::stoll(value);}
         if(key == "purchasesOfInvestments" && value != "null"){ purchasesOfInvestments= std::stoll(value);}
         if(key == "salesMaturitiesOfInvestments" && value != "null"){ salesMaturitiesOfInvestments= std::stoll(value);}
         if(key == "otherInvestingActivites" && value != "null"){otherInvestingActivites = std::stoll(value);}
         if(key == "netCashUsedForInvestingActivites" && value != "null"){netCashUsedForInvestingActivites = std::stoll(value);}
         if(key == "debtRepayment" && value != "null"){debtRepayment = std::stoll(value);}
         if(key == "commonStockIssued" && value != "null"){ commonStockIssued= std::stoll(value);}
         if(key == "commonStockRepurchased" && value != "null"){ commonStockRepurchased= std::stoll(value);}
         if(key == "dividendsPaid"&& value != "null"){ dividendsPaid= std::stoll(value);}
         if(key == "otherFinancingActivites"&& value != "null"){ otherFinancingActivites= std::stoll(value);}
         if(key == "netCashUsedProvidedByFinancingActivities"&& value != "null"){ netCashUsedProvidedByFinancingActivities= std::stoll(value);}
         if(key == "effectOfForexChangesOnCash"&& value != "null"){ effectOfForexChangesOnCash= std::stoll(value);}
         if(key == "netChangeInCash"&& value != "null"){ netChangeInCash= std::stoll(value);}
         if(key == "cashAtEndOfPeriod"&& value != "null"){ cashAtEndOfPeriod= std::stoll(value);}
         if(key == "cashAtBeginningOfPeriod"&& value != "null"){ cashAtBeginningOfPeriod= std::stoll(value);}
         if(key == "operatingCashFlow"&& value != "null"){operatingCashFlow = std::stoll(value);}
         if(key == "capitalExpenditure"&& value != "null"){capitalExpenditure = std::stoll(value);}
         if(key == "freeCashFlow"&& value != "null"){ freeCashFlow= std::stoll(value);}
         if(key == "link"){ link= value;}
         if(key == "finalLink"){ finalLink= value;}
         
    }
    
}

std::string Cashflowstatement::get_class_name() const {
   return  "cashflow_statement";   
}
        
std::string Cashflowstatement::create_file_name(std::string ticker)const{
  if(ticker.size()==0){
        return  symbol + "_" + get_class_name() +".bin";
    } else {
        return  ticker + "_" + get_class_name() +".bin";    
    }
}

size_t Cashflowstatement::compute_object_size() const {
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
      total_size += sizeof(size_t) * 10;
      
      total_size += sizeof(long long)  * 30;// 30 is the number of long long memebrs
      return total_size;
     
    }


void Cashflowstatement::save_to_file(std::ofstream &out){

    
    
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

        
        out.write(reinterpret_cast<const char*>(&netIncome), sizeof(netIncome));   
        out.write(reinterpret_cast<const char*>(&depreciationAndAmortization), sizeof(depreciationAndAmortization));   
		out.write(reinterpret_cast<const char*>(&deferredIncomeTax), sizeof(deferredIncomeTax));   
		out.write(reinterpret_cast<const char*>(&stockBasedCompensation), sizeof(stockBasedCompensation));   
		out.write(reinterpret_cast<const char*>(&changeInWorkingCapital), sizeof(changeInWorkingCapital));
		out.write(reinterpret_cast<const char*>(&accountsReceivables), sizeof(accountsReceivables));
		out.write(reinterpret_cast<const char*>(&inventory), sizeof(inventory));  
		out.write(reinterpret_cast<const char*>(&accountsPayables), sizeof(accountsPayables)); 
		out.write(reinterpret_cast<const char*>(&otherWorkingCapital), sizeof(otherWorkingCapital)); 
		out.write(reinterpret_cast<const char*>(&otherNonCashItems), sizeof(otherNonCashItems));
		out.write(reinterpret_cast<const char*>(&netCashProvidedByOperatingActivities), sizeof(netCashProvidedByOperatingActivities));
		out.write(reinterpret_cast<const char*>(&investmentsInPropertyPlantAndEquipment), sizeof(investmentsInPropertyPlantAndEquipment));
		out.write(reinterpret_cast<const char*>(&acquisitionsNet), sizeof(acquisitionsNet));   
		out.write(reinterpret_cast<const char*>(&purchasesOfInvestments), sizeof(purchasesOfInvestments));
		out.write(reinterpret_cast<const char*>(&salesMaturitiesOfInvestments), sizeof(salesMaturitiesOfInvestments));
		out.write(reinterpret_cast<const char*>(&otherInvestingActivites), sizeof(otherInvestingActivites));
		out.write(reinterpret_cast<const char*>(&netCashUsedForInvestingActivites), sizeof(netCashUsedForInvestingActivites));
		out.write(reinterpret_cast<const char*>(&debtRepayment), sizeof(debtRepayment));
		out.write(reinterpret_cast<const char*>(&commonStockIssued), sizeof(commonStockIssued)); 
		out.write(reinterpret_cast<const char*>(&commonStockRepurchased), sizeof(commonStockRepurchased));
		out.write(reinterpret_cast<const char*>(&dividendsPaid), sizeof(dividendsPaid));  
		out.write(reinterpret_cast<const char*>(&otherFinancingActivites), sizeof(otherFinancingActivites)); 
		out.write(reinterpret_cast<const char*>(&netCashUsedProvidedByFinancingActivities), sizeof(netCashUsedProvidedByFinancingActivities));
		out.write(reinterpret_cast<const char*>(&effectOfForexChangesOnCash), sizeof(effectOfForexChangesOnCash));
		out.write(reinterpret_cast<const char*>(&netChangeInCash), sizeof(netChangeInCash));
		out.write(reinterpret_cast<const char*>(&cashAtEndOfPeriod), sizeof(cashAtEndOfPeriod));
		out.write(reinterpret_cast<const char*>(&cashAtBeginningOfPeriod), sizeof(cashAtBeginningOfPeriod));
		out.write(reinterpret_cast<const char*>(&operatingCashFlow), sizeof(operatingCashFlow)); 
		out.write(reinterpret_cast<const char*>(&capitalExpenditure), sizeof(capitalExpenditure));
		out.write(reinterpret_cast<const char*>(&freeCashFlow), sizeof(freeCashFlow));
		 
        size_t link_size = link.size();
        out.write(reinterpret_cast<const char*>(&link_size), sizeof(link_size));
        out.write(link.c_str(), link_size);
        
         size_t final_link_size = finalLink.size();
        out.write(reinterpret_cast<const char*>(&final_link_size), sizeof(final_link_size));
        out.write(finalLink.c_str(), final_link_size);
          
       
 
}


bool read_size_from_buffer(const std::vector<char> &buffer, size_t &pos, size_t &value){
        
        if(pos+sizeof(size_t)> buffer.size()) return false;
        std::memcpy(&value, buffer.data() + pos, sizeof(size_t));
        pos += sizeof(size_t);
        
        return true;
    
}

bool reading_string_from_buffer(const std::vector<char> &buffer, size_t &pos, std::string &value){
    size_t lenght;
    
    if(!read_size_from_buffer(buffer,pos,lenght)) return false;
    
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

bool Cashflowstatement::read_from_file(std::ifstream &in, std::vector<Cashflowstatement*> &statements){
    Logger logger("read_cfs_f.log");
 
    if (!in){
      logger.log("IO stream it is not open or some error with it. "+ get_class_name() +"\n", Logger::Level::Error);  
    }
    
    
    while(in && !in.eof()){
 
    size_t obj_size;
    
    if(!in.read(reinterpret_cast<char*>(&obj_size), sizeof(obj_size))){
        if(in.eof()){
            break;
        }  
        logger.log("Couldn't read object size from the file regrading class " + get_class_name(), Logger::Level::Error);
        return false;
    }
    
    
    Cashflowstatement* statement = new Cashflowstatement();
     std::vector<char> buffer(obj_size);
     
     if(!in.read(buffer.data(),obj_size)){
         logger.log("failed to read object data from file class " + get_class_name(),Logger::Level::Error);
         return false;
      }
       
         size_t bytes_read = in.gcount();
        if (bytes_read != obj_size) {
            delete statement; // Clean up on error
            return false;
        }

        size_t pos = 0;
        
       
        if(!reading_string_from_buffer(buffer, pos,statement ->date)){
            logger.log("Error reading 'date' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!reading_string_from_buffer(buffer, pos,statement ->symbol)){
             logger.log("Error reading 'symbol' in "+ get_class_name(), Logger::Level::Error);
             }
        if(!reading_string_from_buffer(buffer, pos,statement ->reportedCurrency)){
             logger.log("Error reading 'reportedCurrency' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!reading_string_from_buffer(buffer, pos,statement ->cik)){
             logger.log("Error reading 'cik' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!reading_string_from_buffer(buffer, pos,statement ->fillingDate)){
             logger.log("Error reading 'fillingDate' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!reading_string_from_buffer(buffer, pos,statement ->acceptedDate)){
             logger.log("Error reading 'acceptedDate' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!reading_string_from_buffer(buffer, pos,statement ->calendarYear)){
             logger.log("Error reading 'calendarYear' in "+ get_class_name(), Logger::Level::Error);
            }
        if(!reading_string_from_buffer(buffer, pos,statement ->period)){
             logger.log("Error reading 'period' in "+ get_class_name(), Logger::Level::Error);
            }
            
            
            //numbers values
    
             if(!read_number_values_from_buffer(buffer, pos,statement -> netIncome)){
             logger.log("Error reading 'netIncome' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->depreciationAndAmortization )){
             logger.log("Error reading 'depreciationAndAmortization' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->deferredIncomeTax )){
             logger.log("Error reading 'deferredIncomeTax' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> stockBasedCompensation)){
             logger.log("Error reading 'stockBasedCompensation' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->changeInWorkingCapital )){
             logger.log("Error reading 'changeInWorkingCapital' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->accountsReceivables )){
             logger.log("Error reading 'accountsReceivables' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->inventory )){
             logger.log("Error reading 'inventory' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->accountsPayables )){
             logger.log("Error reading 'accountsPayables' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->otherWorkingCapital )){
             logger.log("Error reading 'otherWorkingCapital' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->otherNonCashItems )){
             logger.log("Error reading 'otherNonCashItems' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->netCashProvidedByOperatingActivities )){
             logger.log("Error reading 'netCashProvidedByOperatingActivities' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> investmentsInPropertyPlantAndEquipment)){
             logger.log("Error reading 'investmentsInPropertyPlantAndEquipment' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->acquisitionsNet )){
             logger.log("Error reading 'acquisitionsNet' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> purchasesOfInvestments)){
             logger.log("Error reading 'purchasesOfInvestments' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> salesMaturitiesOfInvestments)){
             logger.log("Error reading 'salesMaturitiesOfInvestments' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> otherInvestingActivites)){
             logger.log("Error reading 'otherInvestingActivites' in "+ get_class_name(), Logger::Level::Error);
            }
            
                  if(!read_number_values_from_buffer(buffer, pos,statement -> netCashUsedForInvestingActivites)){
             logger.log("Error reading 'netCashUsedForInvestingActivites' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> debtRepayment)){
             logger.log("Error reading 'debtRepayment' in "+ get_class_name(), Logger::Level::Error);
            }
            
             if(!read_number_values_from_buffer(buffer, pos,statement -> commonStockIssued)){
             logger.log("Error reading 'commonStockIssued' in "+ get_class_name(), Logger::Level::Error);
            }
     
             if(!read_number_values_from_buffer(buffer, pos,statement -> commonStockRepurchased)){
             logger.log("Error reading 'commonStockRepurchased' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> dividendsPaid)){
             logger.log("Error reading 'dividendsPaid' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->otherFinancingActivites )){
             logger.log("Error reading 'otherFinancingActivites' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> netCashUsedProvidedByFinancingActivities)){
             logger.log("Error reading 'netCashUsedProvidedByFinancingActivities' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> effectOfForexChangesOnCash )){
             logger.log("Error reading 'effectOfForexChangesOnCash' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->netChangeInCash )){
             logger.log("Error reading 'netChangeInCash' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> cashAtEndOfPeriod)){
             logger.log("Error reading 'cashAtEndOfPeriod' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> cashAtBeginningOfPeriod)){
             logger.log("Error reading 'cashAtBeginningOfPeriod' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> operatingCashFlow)){
             logger.log("Error reading 'operatingCashFlow' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> capitalExpenditure)){
             logger.log("Error reading 'capitalExpenditure' in "+ get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> freeCashFlow)){
             logger.log("Error reading 'freeCashFlow' in "+ get_class_name(), Logger::Level::Error);
            }
           
      
     
		if(!reading_string_from_buffer(buffer, pos,statement ->link)){
             logger.log("Error reading 'link' in "+ get_class_name(), Logger::Level::Error);
            }
            
            if(!reading_string_from_buffer(buffer, pos,statement ->finalLink)){
             logger.log("Error reading 'finalLink' in "+ get_class_name(), Logger::Level::Error);
             statement ->finalLink= "nf";
            }

           statements.push_back(statement);
           
          if(bytes_read  < buffer.size()){
           
            
            logger.log("Reached EOF! no more data to read in for " + get_class_name(), Logger::Level::Error);
            return false;
            
            }
       
     }


    return true;
    

}

    

