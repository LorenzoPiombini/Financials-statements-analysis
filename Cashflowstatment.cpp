#include <iostream>
#include "Cashflowstatement.h"
#include <fstream>
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


void from_json(const nlohmann::json &j, Cashflowstatement &c){

    c.date = j.contains("date") && !j["date"].empty() ? j["date"].get<std::string>() : "none";
   c.symbol = j.contains("symbol") && !j["symbol"].empty() ? j["symbol"].get<std::string>() : "none";
    c.reportedCurrency = j.contains("reportedCurrency") && !j["reportedCurrency"].empty() ? j["reportedCurrency"].get<std::string>() : "none";
    c.cik = j.contains("cik") && !j["cik"].empty() ? j["cik"].get<std::string>() : "none";
    c.fillingDate = j.contains("fillingDate") && !j["fillingDate"].empty() ? j["fillingDate"].get<std::string>() : "none";
   c.acceptedDate = j.contains("acceptedDate") && !j["acceptedDate"].empty() ? j["acceptedDate"].get<std::string>() : "none";
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
//     if (!out) {
//        std::cerr << "File stream is not open or has encountered an error." << std::endl;
//        return;
//        }
    
    
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
    
    
    Cashflowstatement* statement = new Cashflowstatement();
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
        
       
        if(!reading_string_from_buffer(buffer, pos,statement ->date)){
            std::cerr << "Error reading 'date' in " << get_class_name() << std::endl;
            }
        if(!reading_string_from_buffer(buffer, pos,statement ->symbol)){
             std::cerr << "Error reading 'symbol' in " << get_class_name() << std::endl;
             }
        if(!reading_string_from_buffer(buffer, pos,statement ->reportedCurrency)){
             std::cerr << "Error reading 'reportedCurrency' in " << get_class_name() << std::endl;
            }
        if(!reading_string_from_buffer(buffer, pos,statement ->cik)){
             std::cerr << "Error reading 'cik' in " << get_class_name() << std::endl;
            }
        if(!reading_string_from_buffer(buffer, pos,statement ->fillingDate)){
             std::cerr << "Error reading 'fillingDate' in " << get_class_name() << std::endl;
            }
        if(!reading_string_from_buffer(buffer, pos,statement ->acceptedDate)){
             std::cerr << "Error reading 'acceptedDate' in " << get_class_name() << std::endl;
            }
        if(!reading_string_from_buffer(buffer, pos,statement ->calendarYear)){
             std::cerr << "Error reading 'calendarYear' in " << get_class_name() << std::endl;
            }
        if(!reading_string_from_buffer(buffer, pos,statement ->period)){
             std::cerr << "Error reading 'period' in " << get_class_name() << std::endl;
            }
            
            
            //numbers values
    
             if(!read_number_values_from_buffer(buffer, pos,statement -> netIncome)){
             std::cerr << "Error reading 'netIncome' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->depreciationAndAmortization )){
             std::cerr << "Error reading 'depreciationAndAmortization' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->deferredIncomeTax )){
             std::cerr << "Error reading 'deferredIncomeTax' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> stockBasedCompensation)){
             std::cerr << "Error reading 'stockBasedCompensation' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->changeInWorkingCapital )){
             std::cerr << "Error reading 'changeInWorkingCapital' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->accountsReceivables )){
             std::cerr << "Error reading 'accountsReceivables' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->inventory )){
             std::cerr << "Error reading 'inventory' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->accountsPayables )){
             std::cerr << "Error reading 'accountsPayables' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->otherWorkingCapital )){
             std::cerr << "Error reading 'otherWorkingCapital' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->otherNonCashItems )){
             std::cerr << "Error reading 'otherNonCashItems' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->netCashProvidedByOperatingActivities )){
             std::cerr << "Error reading 'netCashProvidedByOperatingActivities' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> investmentsInPropertyPlantAndEquipment)){
             std::cerr << "Error reading 'investmentsInPropertyPlantAndEquipment' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->acquisitionsNet )){
             std::cerr << "Error reading 'acquisitionsNet' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> purchasesOfInvestments)){
             std::cerr << "Error reading 'purchasesOfInvestments' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> salesMaturitiesOfInvestments)){
             std::cerr << "Error reading 'salesMaturitiesOfInvestments' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> otherInvestingActivites)){
             std::cerr << "Error reading 'otherInvestingActivites' in " << get_class_name() << std::endl;
            }
            
                  if(!read_number_values_from_buffer(buffer, pos,statement -> netCashUsedForInvestingActivites)){
             std::cerr << "Error reading 'netCashUsedForInvestingActivites' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> debtRepayment)){
             std::cerr << "Error reading 'debtRepayment' in " << get_class_name() << std::endl;
            }
            
             if(!read_number_values_from_buffer(buffer, pos,statement -> commonStockIssued)){
             std::cerr << "Error reading 'commonStockIssued' in " << get_class_name() << std::endl;
            }
     
             if(!read_number_values_from_buffer(buffer, pos,statement -> commonStockRepurchased)){
             std::cerr << "Error reading 'commonStockRepurchased' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> dividendsPaid)){
             std::cerr << "Error reading 'dividendsPaid' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->otherFinancingActivites )){
             std::cerr << "Error reading 'otherFinancingActivites' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> netCashUsedProvidedByFinancingActivities)){
             std::cerr << "Error reading 'netCashUsedProvidedByFinancingActivities' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> effectOfForexChangesOnCash )){
             std::cerr << "Error reading 'effectOfForexChangesOnCash' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement ->netChangeInCash )){
             std::cerr << "Error reading 'netChangeInCash' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> cashAtEndOfPeriod)){
             std::cerr << "Error reading 'cashAtEndOfPeriod' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> cashAtBeginningOfPeriod)){
             std::cerr << "Error reading 'cashAtBeginningOfPeriod' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> operatingCashFlow)){
             std::cerr << "Error reading 'operatingCashFlow' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> capitalExpenditure)){
             std::cerr << "Error reading 'capitalExpenditure' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer(buffer, pos,statement -> freeCashFlow)){
             std::cerr << "Error reading 'freeCashFlow' in " << get_class_name() << std::endl;
            }
           
      
     
		if(!reading_string_from_buffer(buffer, pos,statement ->link)){
             std::cerr << "Error reading 'link' in " << get_class_name() << std::endl;
            }
            
            if(!reading_string_from_buffer(buffer, pos,statement ->finalLink)){
             std::cerr << "Error reading 'finalLink' in " << get_class_name() << std::endl;
             statement ->finalLink= "nf";
            }

           statements.push_back(statement);
           
          if(bytes_read  < buffer.size()){
           
            
            std::cerr<<"Reached EOF! no more data to read in for "<<get_class_name()<<".\n";
            return false;
            
            }
       
     }


    return true;
    

}

    

