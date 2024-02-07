#include "Incomestatement.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include "Logger.h"

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

long long Income_statement::get_outstanding_share_from_sec()const{
    return outstanding_share_from_sec;
}
void Income_statement::set_outstanding_share_from_sec(long long shares_outstanding){
      outstanding_share_from_sec = shares_outstanding;
}


std::string trim_income(const std::string &str){
  size_t first = str.find_first_not_of(" \t\n\r");
  
   if(first == std::string::npos) return "";    
  
   size_t last = str.find_last_not_of(" \t\n\r");
   return str.substr(first, (last - first +1));
}

void Income_statement::deserialize(std::string &json_string){
    std::string token;
    
    std::string trimmed_json = trim_income(json_string);
    
    
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
         
         auto key = trim_income(token.substr(0, separator_pos));
         auto value = trim_income(token.substr(separator_pos + 1));
         
        
        
          
          if (!key.empty() && key.front() == '"' && key.back() == '"') {
            key = key.substr(1, key.size() - 2);
          }
         if(!value.empty() && value.front() == '"' && value.back() =='"'){
             value = value.substr(1, value.size() - 2);
             }

//this line is for debugging 
          //std::cout <<"Key is long : " << key.length() << "and it looks like "<<key<< "and the value is:" << value<<"no space in value"<< std::endl;
         
         if(key == "date"){date = value;}
         if(key == "symbol"){symbol = value;}
         if(key == "reportedCurrency"){reportedCurrency = value;}
         if(key == "cik"){cik = value;}
         if(key == "fillingDate"){fillingDate = value;}
         if(key == "acceptedDate"){acceptedDate = value;}
         if(key == "calendarYear"){calendarYear = value;}
         if(key == "period"){period = value;}
         if(key == "revenue" && value != "null"){ revenue= std::stoll(value);}
         if(key == "costOfRevenue" && value != "null"){ costOfRevenue= std::stoll(value);}
         if(key == "grossProfit" && value != "null"){grossProfit = std::stoll(value);}
         if(key == "grossProfitRatio" && value != "null"){ grossProfitRatio= std::stod(value);}
         if(key == "researchAndDevelopmentExpenses" && value != "null"){ researchAndDevelopmentExpenses= std::stoll(value);}
         if(key == "generalAndAdministrativeExpenses" && value != "null"){ generalAndAdministrativeExpenses= std::stoll(value);}
         if(key == "sellingAndMarketingExpenses" && value != "null"){ sellingAndMarketingExpenses = std::stoll(value);}
         if(key == "sellingGeneralAndAdministrativeExpenses" && value != "null"){ sellingGeneralAndAdministrativeExpenses= std::stoll(value);}
         if(key == "otherExpenses" && value != "null"){ otherExpenses= std::stoll(value);}
         if(key == "operatingExpenses"){ operatingExpenses= std::stoll(value);}
         if(key == "costAndExpenses" && value != "null"){ costAndExpenses = std::stoll(value);}
         if(key == "interestIncome" && value != "null"){ interestIncome= std::stoll(value);}
         if(key == "interestExpense" && value != "null"){interestExpense = std::stoll(value);}
         if(key == "depreciationAndAmortization" && value != "null"){ depreciationAndAmortization= std::stoll(value);}
         if(key == "ebitda" && value != "null"){ebitda = std::stoll(value);}
         if(key == "ebitdaratio" && value != "null"){ebitdaratio = std::stod(value);}
         if(key == "operatingIncome" && value != "null"){ operatingIncome= std::stoll(value);}
         if(key == "operatingIncomeRatio" && value != "null"){ operatingIncomeRatio= std::stod(value);}
         if(key == "totalOtherIncomeExpensesNet" && value != "null"){totalOtherIncomeExpensesNet = std::stoll(value);}
         if(key == "incomeBeforeTax" && value != "null"){ incomeBeforeTax= std::stoll(value);}
         if(key == "incomeBeforeTaxRatio" && value != "null"){ incomeBeforeTaxRatio= std::stod(value);}
         if(key == "incomeTaxExpense" && value != "null"){ incomeTaxExpense = std::stoll(value);}
         if(key == "netIncome" && value != "null"){ netIncome = std::stoll(value);}
         if(key == "netIncomeRatio" && value != "null"){ netIncomeRatio= std::stoll(value);}
         if(key == "eps" && value != "null"){ eps= std::stod(value);}
         if(key == "epsdiluted" && value != "null"){ epsdiluted= std::stod(value);}
         if(key == "weightedAverageShsOut" && value != "null"){weightedAverageShsOut = std::stoll(value);}
         if(key == "weightedAverageShsOutDil" && value != "null"){weightedAverageShsOutDil = std::stoll(value);}
         if(key == "link"){ link= value;}
         if(key == "finalLink"){ finalLink= value;}
         
    }
    
    outstanding_share_from_sec = 0ll;
    
}



std::string Income_statement::get_class_name()const{
    return "income_statement";  
}




size_t Income_statement::compute_object_size() const {
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
      
      total_size += sizeof(long long)  * 23;// 23 is the number of long long memebrs
      total_size += sizeof(double) * 6; // 6 is the number of double memebers;
      
      return total_size;
     
    }
std::string Income_statement::create_file_name(std::string ticker)const{
    if(ticker.size()==0){
        return  symbol + "_" + get_class_name() +".bin";
    } else {
        return  ticker + "_" + get_class_name() +".bin";    
    }
             
}

void Income_statement::save_to_file(std::ofstream &out){

    
     size_t obj_size = this-> compute_object_size();
     //std::cout<< "income statement obj size: "<< obj_size <<std::endl;
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
   
   out.write(reinterpret_cast<const char*>(&revenue), sizeof(revenue));
   out.write(reinterpret_cast<const char*>(&costOfRevenue), sizeof(costOfRevenue));
   out.write(reinterpret_cast<const char*>(&grossProfit), sizeof(grossProfit));
   out.write(reinterpret_cast<const char*>(&grossProfitRatio), sizeof(grossProfitRatio));
   out.write(reinterpret_cast<const char*>(&researchAndDevelopmentExpenses), sizeof(researchAndDevelopmentExpenses));
   out.write(reinterpret_cast<const char*>(&generalAndAdministrativeExpenses), sizeof(generalAndAdministrativeExpenses));
   out.write(reinterpret_cast<const char*>(&sellingAndMarketingExpenses), sizeof(sellingAndMarketingExpenses));
   out.write(reinterpret_cast<const char*>(&sellingGeneralAndAdministrativeExpenses), sizeof(sellingGeneralAndAdministrativeExpenses));
   out.write(reinterpret_cast<const char*>(&otherExpenses), sizeof(otherExpenses));
   out.write(reinterpret_cast<const char*>(&operatingExpenses), sizeof(otherExpenses));
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
   out.write(reinterpret_cast<const char*>(&outstanding_share_from_sec), sizeof(outstanding_share_from_sec));
   
   size_t link_size = link.size();
   out.write(reinterpret_cast<const char*>(&link_size), sizeof(link_size));
   out.write(link.c_str(), link_size);
        
   size_t final_link_size = finalLink.size();
   out.write(reinterpret_cast<const char*>(&final_link_size), sizeof(final_link_size));
   out.write(finalLink.c_str(), final_link_size);
          
  
 
}


bool read_size_from_buffer_income(const std::vector<char> &buffer, size_t &pos, size_t &value){
        
        if(pos+sizeof(size_t)> buffer.size()) return false;
        std::memcpy(&value, buffer.data() + pos, sizeof(size_t));
        pos += sizeof(size_t);
        
        return true;
    
}

bool reading_string_from_buffer_income(const std::vector<char> &buffer, size_t &pos, std::string &value){
    size_t lenght;
    
    if(!read_size_from_buffer_income(buffer,pos,lenght)) return false;
    
    if(pos + lenght > buffer.size())return false;
    
    value.assign(buffer.data() + pos, lenght);
    pos += lenght;
    
    return true;
    
}

template <typename T>
bool read_number_values_from_buffer_income(std::vector<char> &buffer, size_t &pos, T &value){
    if(pos + sizeof(T) > buffer.size()) return false;
    
    std::memcpy(&value, buffer.data() + pos, sizeof(T));
    
    pos += sizeof(T);
    return true;
    
}


    
    
bool Income_statement::read_from_file(std::ifstream &in, std::vector<Income_statement*> &statements ){
    Logger logger("read_is_f.log");
 
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
    //std::cout << "Object size read (Income statement): " << obj_size << std::endl;
    
    Income_statement* statement = new Income_statement();
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
        
       
        if(!reading_string_from_buffer_income(buffer, pos,statement ->date)){
            logger.log("Error reading 'date' in " + get_class_name(), Logger::Level::Error);
            }
        if(!reading_string_from_buffer_income(buffer, pos,statement ->symbol)){
             logger.log("Error reading 'symbol' in " + get_class_name(), Logger::Level::Error);
             }
        if(!reading_string_from_buffer_income(buffer, pos,statement ->reportedCurrency)){
             logger.log("Error reading 'reportedCurrency' in " + get_class_name(), Logger::Level::Error);
            }
        if(!reading_string_from_buffer_income(buffer, pos,statement ->cik)){
             logger.log("Error reading 'cik' in " + get_class_name(), Logger::Level::Error);
            }
        if(!reading_string_from_buffer_income(buffer, pos,statement ->fillingDate)){
             logger.log("Error reading 'fillingDate' in " + get_class_name(), Logger::Level::Error);
            }
        if(!reading_string_from_buffer_income(buffer, pos,statement ->acceptedDate)){
             logger.log("Error reading 'acceptedDate' in " + get_class_name(), Logger::Level::Error);
            }
        if(!reading_string_from_buffer_income(buffer, pos,statement ->calendarYear)){
             logger.log("Error reading 'calendarYear' in " + get_class_name(), Logger::Level::Error);
            }
        if(!reading_string_from_buffer_income(buffer, pos,statement ->period)){
             logger.log("Error reading 'period' in " + get_class_name(), Logger::Level::Error);
            }
            
        //number values
       if(!read_number_values_from_buffer_income(buffer, pos,statement -> revenue )){
             logger.log("Error reading 'revenue' in " + get_class_name(), Logger::Level::Error);
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement ->costOfRevenue )){
            logger.log("Error reading 'costOfRevenue' in " + get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer_income(buffer, pos,statement ->grossProfit )){
             logger.log("Error reading 'grossProfit' in " + get_class_name(), Logger::Level::Error);
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement -> grossProfitRatio )){
             logger.log("Error reading 'grossProfitRatio' in " + get_class_name(), Logger::Level::Error);
            }
            if(!read_number_values_from_buffer_income(buffer, pos,statement -> researchAndDevelopmentExpenses)){
             logger.log("Error reading 'researchAndDevelopmentExpenses' in " + get_class_name(), Logger::Level::Error);
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement -> generalAndAdministrativeExpenses)){
             logger.log("Error reading 'generalAndAdministrativeExpenses' in " + get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer_income(buffer, pos,statement -> sellingAndMarketingExpenses)){
             logger.log("Error reading 'sellingAndMarketingExpenses' in " + get_class_name(), Logger::Level::Error);
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement -> sellingGeneralAndAdministrativeExpenses)){
             logger.log("Error reading 'sellingGeneralAndAdministrativeExpenses' in " + get_class_name(), Logger::Level::Error);
            }
            if(!read_number_values_from_buffer_income(buffer, pos,statement -> otherExpenses )){
             logger.log("Error reading 'otherExpenses' in " + get_class_name(), Logger::Level::Error);
            }
            if(!read_number_values_from_buffer_income(buffer, pos,statement -> operatingExpenses)){
             logger.log("Error reading 'operatingExpenses' in " + get_class_name(), Logger::Level::Error);
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement ->costAndExpenses )){
             logger.log("Error reading 'costAndExpenses' in " + get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer_income(buffer, pos,statement -> interestIncome)){
             logger.log("Error reading 'interestIncome' in " + get_class_name(), Logger::Level::Error);
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement ->interestExpense )){
             logger.log("Error reading 'interestExpense' in " + get_class_name(), Logger::Level::Error);
            }
            if(!read_number_values_from_buffer_income(buffer, pos,statement -> depreciationAndAmortization)){
             logger.log("Error reading 'depreciationAndAmortization' in " + get_class_name(), Logger::Level::Error);
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement ->ebitda )){
             logger.log("Error reading 'ebitda' in " + get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer_income(buffer, pos,statement ->ebitdaratio )){
             logger.log("Error reading 'ebitdaratio' in " + get_class_name(), Logger::Level::Error);
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement -> operatingIncome )){
             logger.log("Error reading 'operatingIncome' in " + get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer_income(buffer, pos,statement -> operatingIncomeRatio)){
             logger.log("Error reading 'operatingIncomeRatio' in " + get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer_income(buffer, pos,statement ->totalOtherIncomeExpensesNet )){
             logger.log("Error reading 'totalOtherIncomeExpensesNet' in " + get_class_name(), Logger::Level::Error);
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement ->incomeBeforeTax )){
             logger.log("Error reading 'incomeBeforeTax' in " + get_class_name(), Logger::Level::Error);
            }
            if(!read_number_values_from_buffer_income(buffer, pos,statement ->incomeBeforeTaxRatio )){
             logger.log("Error reading 'incomeBeforeTaxRatio' in " + get_class_name(), Logger::Level::Error);
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement ->incomeTaxExpense )){
             logger.log("Error reading 'incomeTaxExpense' in " + get_class_name(), Logger::Level::Error);
            }
        if(!read_number_values_from_buffer_income(buffer, pos,statement ->netIncome )){
             logger.log("Error reading 'netIncome' in " + get_class_name(), Logger::Level::Error);
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement -> netIncomeRatio)){
             logger.log("Error reading 'netIncomeRatio' in " + get_class_name(), Logger::Level::Error);
            }
            
             if(!read_number_values_from_buffer_income(buffer, pos,statement ->eps )){
             logger.log("Error reading 'eps' in " + get_class_name(), Logger::Level::Error);
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement ->epsdiluted )){
             logger.log("Error reading 'epsdiluted' in " + get_class_name(), Logger::Level::Error);
            }
             if(!read_number_values_from_buffer_income(buffer, pos,statement -> weightedAverageShsOut )){
             logger.log("Error reading 'weightedAverageShsOut' in " + get_class_name(), Logger::Level::Error);
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement ->weightedAverageShsOutDil)){
             logger.log("Error reading 'weightedAverageShsOutDil' in " + get_class_name(), Logger::Level::Error);
            }
                 
          if(!read_number_values_from_buffer_income(buffer, pos,statement ->outstanding_share_from_sec)){
             logger.log("Error reading 'outstanding_share_from_sec' in " + get_class_name(), Logger::Level::Error);
             statement->outstanding_share_from_sec = 0;
            }
         
         if(!reading_string_from_buffer_income(buffer, pos,statement ->link)){
             logger.log("Error reading 'link' in " + get_class_name(), Logger::Level::Error);
            }
            
            if(!reading_string_from_buffer_income(buffer, pos,statement ->finalLink)){
             logger.log("Error reading 'finalLink' in " + get_class_name(), Logger::Level::Error);
             statement -> finalLink ="nf";
            }
     
          //std::cout << "Reading completed for " << statement->symbol << " at position " << pos << std::endl;
    
    
       // Check if entire object was read
        if (pos != obj_size) {
            logger.log("Mismatch in object size and bytes read for " + get_class_name(), Logger::Level::Error);
            delete statement;
            return false;
        }
        
       statements.push_back(statement);
      
      
        
     
     
     
     }
    return true;
    
}
