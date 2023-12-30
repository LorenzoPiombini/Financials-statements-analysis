#include "Response.h"
#include <iostream>
#include <vector>
#include <string>
#include "nlohmann/json.hpp"

using std::string;
using std::vector;


string Response::get_id(){
    return id;
}
string Response::get_start_date(){
    return start_date;
}
string Response::get_end_date(){
    return end_date;
}
string Response::get_filing_date(){
    return filing_date;
}
string Response::get_acceptance_datetime(){
    return acceptance_datetime;
}
string Response::get_timeframe(){
    return timeframe;
}
string Response::get_fiscal_period(){
    return fiscal_period;
}
string Response::get_fiscal_year(){
    return fiscal_year;
}
string Response::get_cik(){
    return cik;
}
string Response::get_sic(){
    return sic;
}
vector<string> Response::get_tickers(){
    return tickers;
}
string Response::get_company_name(){
    return company_name;
}
string Response::get_source_filing_url(){
    return source_filing_url;
}
string Response::get_source_filing_file_url(){
    return source_filing_file_url;
}
Financials Response::get_financials(){
    return financials;
}


void from_json(const nlohmann::json &j, Response &res){
    j.at("id").get_to(res.id);
    j.at("start_date").get_to(res.start_date);
    j.at("end_date").get_to(res.end_date);
    
    if(j.contains("filing_date") && !j["filing_date"].empty()){
        j.at("filing_date").get_to(res.filing_date);
    } else {
           res.filing_date = "nf";      
    }
    
    if(j.contains("acceptance_datetime") && !j["acceptance_datetime"].empty()){
        j.at("acceptance_datetime").get_to(res.acceptance_datetime);
    } else {
        res.acceptance_datetime = "nf";
    }
    
    j.at("timeframe").get_to(res.timeframe);
    j.at("fiscal_period").get_to(res.fiscal_period);
    j.at("fiscal_year").get_to(res.fiscal_year);
    j.at("cik").get_to(res.cik);
    j.at("sic").get_to(res.sic);
    j.at("tickers").get_to(res.tickers);
    j.at("company_name").get_to(res.company_name);
    
    if(j.contains("source_filing_url") && !j["source_filing_url"].empty()){
        j.at("source_filing_url").get_to(res.source_filing_url);
    } else {
        res.source_filing_url = "nf";
    }
    
    if(j.contains("source_filing_file_url") && !j["source_filing_file_url"].empty()){
        j.at("source_filing_file_url").get_to(res.source_filing_file_url);
    } else {
        res.source_filing_url = "nf";
    }
    
    
    j.at("financials").get_to(res.financials); //asumng financials has a from_json
    
}

