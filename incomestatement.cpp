#include "Incomestatement.h"
#include <fstream>
#include <iostream>
#include <sstream>
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
 //         std::cout <<"Key is long : " << key.length() << "and it looks like"+key<< std::endl;
         
         if(key == "date"){date = value;}
         if(key == "symbol"){symbol = value;}
         if(key == "reportedCurrency"){reportedCurrency = value;}
         if(key == "cik"){cik = value;}
         if(key == "fillingDate"){fillingDate = value;}
         if(key == "acceptedDate"){acceptedDate = value;}
         if(key == "calendarYear"){calendarYear = value;}
         if(key == "period"){period = value;}
         if(key == "revenue"){ revenue= std::stoll(value);}
         if(key == "costOfRevenue"){ costOfRevenue= std::stoll(value);}
         if(key == "grossProfit"){grossProfit = std::stoll(value);}
         if(key == "grossProfitRatio"){ grossProfitRatio= std::stod(value);}
         if(key == "researchAndDevelopmentExpenses"){ researchAndDevelopmentExpenses= std::stoll(value);}
         if(key == "generalAndAdministrativeExpenses"){ generalAndAdministrativeExpenses= std::stoll(value);}
         if(key == "sellingAndMarketingExpenses"){ sellingAndMarketingExpenses = std::stoll(value);}
         if(key == "sellingGeneralAndAdministrativeExpenses"){ sellingGeneralAndAdministrativeExpenses= std::stoll(value);}
         if(key == "otherExpenses"){ otherExpenses= std::stoll(value);}
         if(key == "operatingExpenses"){ operatingExpenses= std::stoll(value);}
         if(key == "costAndExpenses"){ costAndExpenses = std::stoll(value);}
         if(key == "interestIncome"){ interestIncome= std::stoll(value);}
         if(key == "interestExpense"){interestExpense = std::stoll(value);}
         if(key == "depreciationAndAmortization"){ depreciationAndAmortization= std::stoll(value);}
         if(key == "ebitda"){ebitda = std::stoll(value);}
         if(key == "ebitdaratio"){ebitdaratio = std::stod(value);}
         if(key == "operatingIncome"){ operatingIncome= std::stoll(value);}
         if(key == "operatingIncomeRatio"){ operatingIncomeRatio= std::stod(value);}
         if(key == "totalOtherIncomeExpensesNet"){totalOtherIncomeExpensesNet = std::stoll(value);}
         if(key == "incomeBeforeTax"){ incomeBeforeTax= std::stoll(value);}
         if(key == "incomeBeforeTaxRatio"){ incomeBeforeTaxRatio= std::stod(value);}
         if(key == "incomeTaxExpense"){ incomeTaxExpense = std::stoll(value);}
         if(key == "netIncome"){ netIncome = std::stoll(value);}
         if(key == "netIncomeRatio"){ netIncomeRatio= std::stoll(value);}
         if(key == "eps"){ eps= std::stod(value);}
         if(key == "epsdiluted"){ epsdiluted= std::stod(value);}
         if(key == "weightedAverageShsOut"){weightedAverageShsOut = std::stoll(value);}
         if(key == "weightedAverageShsOutDil"){weightedAverageShsOutDil = std::stoll(value);}
         if(key == "link"){ link= value;}
         if(key == "finalLink"){ finalLink= value;}
         
    }
    
}


//void from_json(const nlohmann::json &j, Income_statement &i){
//  
//    if(j.contains("date") && !j["date"].empty()){
//          j.at("date").get_to(i.date);
//    } else {
//          i.date = "none";
//    }
//  
//   if(j.contains("symbol") && !j["symbol"].empty()){
//          j.at("symbol").get_to(i.symbol);
//    } else {
//          i.symbol = "none";
//    }
//  
//  
//  if(j.contains("reportedCurrency") && !j["reportedCurrency"].empty()){
//          j.at("reportedCurrency").get_to(i.reportedCurrency);
//   }else{
//          i.reportedCurrency = "none";
//   }
//  
//  
//  if(j.contains("cik") && !j["cik"].empty()){
//     j.at("cik").get_to(i.cik);
//   } else {
//     i.cik = "none";
//  }
//  
//  
//  if(j.contains("fillingDate") && !j["fillingDate"].empty()){
//        j.at("fillingDate").get_to(i.fillingDate);
//   } else {
//        i.fillingDate = "none";
//   }
//  
//  if(j.contains("acceptedDate") && !j["acceptedDate"].empty()){
//       j.at("acceptedDate").get_to(i.acceptedDate);
//   } else {
//       i.acceptedDate = "none";
//   }
// 
//  
//   if(j.contains("calendarYear") && !j["calendarYear"].empty()){
//          j.at("calendarYear").get_to(i.calendarYear);
//    } else {
//          i.calendarYear = "none";
//    }
//  
//   if(j.contains("period") && !j["period"].empty()){
//          j.at("period").get_to(i.period);
//    } else {
//          i.period = "none";
//    }
//  
//  
//  if(j.contains("revenue") && !j["revenue"].empty()){
//          j.at("revenue").get_to(i.revenue);
//   }else{
//          i.revenue = 0;
//   }
//  
//  
//  if(j.contains("costOfRevenue") && !j["costOfRevenue"].empty()){
//     j.at("costOfRevenue").get_to(i.costOfRevenue);
//   } else {
//     i.costOfRevenue = 0;
//  }
//  
//  
//  if(j.contains("grossProfit") && !j["grossProfit"].empty()){
//        j.at("grossProfit").get_to(i.grossProfit);
//   } else {
//        i.grossProfit = 0;
//   }
//  
//  if(j.contains("grossProfitRatio") && !j["grossProfitRatio"].empty()){
//       j.at("grossProfitRatio").get_to(i.grossProfitRatio);
//   } else {
//       i.grossProfitRatio = 0.0;
//   }
// 
//  
//  if(j.contains("researchAndDevelopmentExpenses") && !j["researchAndDevelopmentExpenses"].empty()){
//        j.at("researchAndDevelopmentExpenses").get_to(i.researchAndDevelopmentExpenses);
//  }else {
//        i.researchAndDevelopmentExpenses = 0;
//  }
//  
//   if(j.contains("generalAndAdministrativeExpenses") && !j["generalAndAdministrativeExpenses"].empty()){
//          j.at("generalAndAdministrativeExpenses").get_to(i.generalAndAdministrativeExpenses);
//    } else {
//          i.generalAndAdministrativeExpenses = 0;
//    }
//  
//   if(j.contains("sellingAndMarketingExpenses") && !j["sellingAndMarketingExpenses"].empty()){
//          j.at("sellingAndMarketingExpenses").get_to(i.sellingAndMarketingExpenses);
//    } else {
//          i.sellingAndMarketingExpenses = 0;
//    }
//  
//  
//  if(j.contains("sellingGeneralAndAdministrativeExpenses") && !j["sellingGeneralAndAdministrativeExpenses"].empty()){
//          j.at("sellingGeneralAndAdministrativeExpenses").get_to(i.sellingGeneralAndAdministrativeExpenses);
//   }else{
//          i.sellingGeneralAndAdministrativeExpenses = 0;
//   }
//  
//  
//  if(j.contains("operatingExpenses") && !j["operatingExpenses"].empty()){
//     j.at("operatingExpenses").get_to(i.operatingExpenses);
//   } else {
//     i.operatingExpenses = 0;
//  }
//  
//  
//  if(j.contains("otherExpenses") && !j["otherExpenses"].empty()){
//        j.at("otherExpenses").get_to(i.otherExpenses);
//   } else {
//        i.otherExpenses = 0;
//   }
//  
//  if(j.contains("costAndExpenses") && !j["costAndExpenses"].empty()){
//       j.at("costAndExpenses").get_to(i.costAndExpenses);
//   } else {
//       i.costAndExpenses = 0;
//   }
// 
//  
//  if(j.contains("interestIncome") && !j["interestIncome"].empty()){
//        j.at("interestIncome").get_to(i.interestIncome);
//  }else {
//        i.interestIncome = 0;
//  }
//  
//    if(j.contains("interestExpense") && !j["interestExpense"].empty()){
//        j.at("interestExpense").get_to(i.interestExpense);
//  }else {
//        i.interestExpense = 0;
//  }
//    if(j.contains("depreciationAndAmortization") && !j["depreciationAndAmortization"].empty()){
//        j.at("depreciationAndAmortization").get_to(i.depreciationAndAmortization);
//  }else {
//        i.depreciationAndAmortization = 0;
//  }
//    if(j.contains("ebitda") && !j["ebitda"].empty()){
//        j.at("ebitda").get_to(i.ebitda);
//  }else {
//        i.ebitda = 0;
//  }
//    if(j.contains("ebitdaratio") && !j["ebitdaratio"].empty()){
//        j.at("ebitdaratio").get_to(i.ebitdaratio);
//  }else {
//        i.ebitdaratio = 0.0;
//  }
//    if(j.contains("operatingIncome") && !j["operatingIncome"].empty()){
//        j.at("operatingIncome").get_to(i.operatingIncome);
//  }else {
//       i.operatingIncome = 0; 
//  }
//    if(j.contains("operatingIncomeRatio") && !j["operatingIncomeRatio"].empty()){
//        j.at("operatingIncomeRatio").get_to(i.operatingIncomeRatio);
//  }else {
//        i.operatingIncomeRatio = 0.0;
//  } 
//
// if(j.contains("totalOtherIncomeExpensesNet") && !j["totalOtherIncomeExpensesNet"].empty()){
//        j.at("totalOtherIncomeExpensesNet").get_to(i.totalOtherIncomeExpensesNet);
//  }else {
//        i.totalOtherIncomeExpensesNet = 0;
//  }  
//  if(j.contains("incomeBeforeTax") && !j["incomeBeforeTax"].empty()){
//        j.at("incomeBeforeTax").get_to(i.incomeBeforeTax);
//  }else {
//        i.incomeBeforeTax = 0;
//  }  
//  
//  if(j.contains("incomeBeforeTaxRatio") && !j["incomeBeforeTaxRatio"].empty()){
//        j.at("incomeBeforeTaxRatio").get_to(i.incomeBeforeTaxRatio);
//  }else {
//        i.incomeBeforeTaxRatio = 0;
//  }  
//  if(j.contains("incomeTaxExpense") && !j["incomeTaxExpense"].empty()){
//        j.at("incomeTaxExpense").get_to(i.incomeTaxExpense);
//  }else {
//        i.incomeTaxExpense = 0;
//  } 
//  
//  if(j.contains("netIncome") && !j["netIncome"].empty()){
//        j.at("netIncome").get_to(i.netIncome);
//  }else {
//        i.netIncome = 0;
//  }  
//  if(j.contains("netIncomeRatio") && !j["netIncomeRatio"].empty()){
//        j.at("netIncomeRatio").get_to(i.netIncomeRatio);
//  }else {
//        i.netIncomeRatio = 0.0;
//  }  
//  if(j.contains("eps") && !j["eps"].empty()){
//        j.at("eps").get_to(i.eps);
//  }else {
//        i.eps = 0.0;
//  }  
//  if(j.contains("epsdiluted") && !j["epsdiluted"].empty()){
//        j.at("epsdiluted").get_to(i.epsdiluted);
//  }else {
//        i.epsdiluted = 0.0;
//  }
//    if(j.contains("weightedAverageShsOut") && !j["weightedAverageShsOut"].empty()){
//        j.at("weightedAverageShsOut").get_to(i.weightedAverageShsOut);
//  }else {
//        i.weightedAverageShsOut = 0;
//  }
//  
//  if(j.contains("weightedAverageShsOutDil") && !j["weightedAverageShsOutDil"].empty()){
//        j.at("weightedAverageShsOutDil").get_to(i.weightedAverageShsOutDil);
//  }else {
//        i.weightedAverageShsOutDil = 0;
//  }
//  if(j.contains("link") && !j["link"].empty()){
//        j.at("link").get_to(i.link);
//  }else {
//        i.link = "none";
//  }
//  if(j.contains("finalLink") && !j["finalLink"].empty()){
//        j.at("finalLink").get_to(i.finalLink);
//  }else {
//        i.finalLink = "none";
//  }
//  
//  
//}


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
      
      total_size += sizeof(long long)  * 22;// 22 is the number of long long memebrs
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
    
//    if (!out) {
//        std::cerr << "File stream is not open or has encountered an error." << std::endl;
//        return;
//        }
    
    
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
    //std::cout << "Object size read (Income statement): " << obj_size << std::endl;
    
    Income_statement* statement = new Income_statement();
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
        
       
        if(!reading_string_from_buffer_income(buffer, pos,statement ->date)){
            std::cerr << "Error reading 'date' in " << get_class_name() << std::endl;
            }
        if(!reading_string_from_buffer_income(buffer, pos,statement ->symbol)){
             std::cerr << "Error reading 'symbol' in " << get_class_name() << std::endl;
             }
        if(!reading_string_from_buffer_income(buffer, pos,statement ->reportedCurrency)){
             std::cerr << "Error reading 'reportedCurrency' in " << get_class_name() << std::endl;
            }
        if(!reading_string_from_buffer_income(buffer, pos,statement ->cik)){
             std::cerr << "Error reading 'cik' in " << get_class_name() << std::endl;
            }
        if(!reading_string_from_buffer_income(buffer, pos,statement ->fillingDate)){
             std::cerr << "Error reading 'fillingDate' in " << get_class_name() << std::endl;
            }
        if(!reading_string_from_buffer_income(buffer, pos,statement ->acceptedDate)){
             std::cerr << "Error reading 'acceptedDate' in " << get_class_name() << std::endl;
            }
        if(!reading_string_from_buffer_income(buffer, pos,statement ->calendarYear)){
             std::cerr << "Error reading 'calendarYear' in " << get_class_name() << std::endl;
            }
        if(!reading_string_from_buffer_income(buffer, pos,statement ->period)){
             std::cerr << "Error reading 'period' in " << get_class_name() << std::endl;
            }
            
        //number values
       if(!read_number_values_from_buffer_income(buffer, pos,statement -> revenue )){
             std::cerr << "Error reading 'revenue' in " << get_class_name() << std::endl;
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement ->costOfRevenue )){
             std::cerr << "Error reading 'costOfRevenue' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer_income(buffer, pos,statement ->grossProfit )){
             std::cerr << "Error reading 'grossProfit' in " << get_class_name() << std::endl;
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement -> grossProfitRatio )){
             std::cerr << "Error reading 'grossProfitRatio' in " << get_class_name() << std::endl;
            }
            if(!read_number_values_from_buffer_income(buffer, pos,statement -> researchAndDevelopmentExpenses)){
             std::cerr << "Error reading 'researchAndDevelopmentExpenses' in " << get_class_name() << std::endl;
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement -> generalAndAdministrativeExpenses)){
             std::cerr << "Error reading 'generalAndAdministrativeExpenses' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer_income(buffer, pos,statement -> sellingAndMarketingExpenses)){
             std::cerr << "Error reading 'sellingAndMarketingExpenses' in " << get_class_name() << std::endl;
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement -> sellingGeneralAndAdministrativeExpenses)){
             std::cerr << "Error reading 'sellingGeneralAndAdministrativeExpenses' in " << get_class_name() << std::endl;
            }
            if(!read_number_values_from_buffer_income(buffer, pos,statement -> otherExpenses )){
             std::cerr << "Error reading 'otherExpenses' in " << get_class_name() << std::endl;
            }
            if(!read_number_values_from_buffer_income(buffer, pos,statement -> operatingExpenses)){
             std::cerr << "Error reading 'operatingExpenses' in " << get_class_name() << std::endl;
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement ->costAndExpenses )){
             std::cerr << "Error reading 'costAndExpenses' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer_income(buffer, pos,statement -> interestIncome)){
             std::cerr << "Error reading 'interestIncome' in " << get_class_name() << std::endl;
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement ->interestExpense )){
             std::cerr << "Error reading 'interestExpense' in " << get_class_name() << std::endl;
            }
            if(!read_number_values_from_buffer_income(buffer, pos,statement -> depreciationAndAmortization)){
             std::cerr << "Error reading 'depreciationAndAmortization' in " << get_class_name() << std::endl;
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement ->ebitda )){
             std::cerr << "Error reading 'ebitda' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer_income(buffer, pos,statement ->ebitdaratio )){
             std::cerr << "Error reading 'ebitdaratio' in " << get_class_name() << std::endl;
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement -> operatingIncome )){
             std::cerr << "Error reading 'operatingIncome' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer_income(buffer, pos,statement -> operatingIncomeRatio)){
             std::cerr << "Error reading 'operatingIncomeRatio' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer_income(buffer, pos,statement ->totalOtherIncomeExpensesNet )){
             std::cerr << "Error reading 'totalOtherIncomeExpensesNet' in " << get_class_name() << std::endl;
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement ->incomeBeforeTax )){
             std::cerr << "Error reading 'incomeBeforeTax' in " << get_class_name() << std::endl;
            }
            if(!read_number_values_from_buffer_income(buffer, pos,statement ->incomeBeforeTaxRatio )){
             std::cerr << "Error reading 'incomeBeforeTaxRatio' in " << get_class_name() << std::endl;
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement ->incomeTaxExpense )){
             std::cerr << "Error reading 'incomeTaxExpense' in " << get_class_name() << std::endl;
            }
        if(!read_number_values_from_buffer_income(buffer, pos,statement ->netIncome )){
             std::cerr << "Error reading 'netIncome' in " << get_class_name() << std::endl;
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement -> netIncomeRatio)){
             std::cerr << "Error reading 'netIncomeRatio' in " << get_class_name() << std::endl;
            }
            
             if(!read_number_values_from_buffer_income(buffer, pos,statement ->eps )){
             std::cerr << "Error reading 'eps' in " << get_class_name() << std::endl;
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement ->epsdiluted )){
             std::cerr << "Error reading 'epsdiluted' in " << get_class_name() << std::endl;
            }
             if(!read_number_values_from_buffer_income(buffer, pos,statement -> weightedAverageShsOut )){
             std::cerr << "Error reading 'weightedAverageShsOut' in " << get_class_name() << std::endl;
            }
       if(!read_number_values_from_buffer_income(buffer, pos,statement ->weightedAverageShsOutDil)){
             std::cerr << "Error reading 'weightedAverageShsOutDil' in " << get_class_name() << std::endl;
            }
                 
         
         
         if(!reading_string_from_buffer_income(buffer, pos,statement ->link)){
             std::cerr << "Error reading 'link' in " << get_class_name() << std::endl;
            }
            
            if(!reading_string_from_buffer_income(buffer, pos,statement ->finalLink)){
             std::cerr << "Error reading 'finalLink' in " << get_class_name() << std::endl;
             statement -> finalLink ="nf";
            }
     
          //std::cout << "Reading completed for " << statement->symbol << " at position " << pos << std::endl;
    
    
       // Check if entire object was read
        if (pos != obj_size) {
            std::cerr << "Mismatch in object size and bytes read for " << get_class_name() << std::endl;
            delete statement;
            return false;
        }
        
       statements.push_back(statement);
      
      
        
     
     
     
     }
    return true;
    
}