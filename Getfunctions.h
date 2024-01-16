#ifndef _GETFUNCTIONS_H_
#define _GETFUNCTIONS_H_

#include <iostream>
#include <string>
#include "Balancesheet.h"
#include "Incomestatement.h"
#include "Keyratios.h"
#include "Cashflowstatement.h"
#include "Responseparsing.h"
#include <curl/curl.h>

using std::cout;
using std:: cerr;

size_t writeCallback(void *ptr, size_t size, size_t nmemb, std::string *data){
    data -> append((char*)ptr, size * nmemb);
    return size*nmemb;
}


std::string perform_get_request(std::string url){
    
    const char* cStyleUrl = url.c_str();
    
    
    //initialize libcurl
	curl_global_init(CURL_GLOBAL_DEFAULT);
    
    //curl handle 
    CURL *curlHandle = curl_easy_init();
    
    if(curlHandle){
        std::string responseString;
        std::string headerString;
        
        //set the URL 
        curl_easy_setopt(curlHandle, CURLOPT_URL, cStyleUrl);
        
        //set call back function
        curl_easy_setopt(curlHandle,CURLOPT_WRITEFUNCTION, writeCallback);
        
        //set a pointer to the response string
        curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &responseString);
        
        //set a pointer to Header string
        curl_easy_setopt(curlHandle, CURLOPT_HEADERDATA, &headerString);
        
        //perform the request
        CURLcode res = curl_easy_perform(curlHandle);
        
         //cleanup
         curl_easy_cleanup(curlHandle);
        
        if(res != CURLE_OK){
               std::string error(curl_easy_strerror(res));
               std::string message = "curl_easy_perform() failed: ";
               return message+error;
               
         }else{
                return responseString;
         }

    } else{
        std::string error = "Error initializing curl\n";
        return error;
    }
    
    
}      




std::string get_company_income_statement(const std::string &ticker, const std::string &period){
    
      std::string response {""};

      std::string base_url = "https://financialmodelingprep.com/api/v3/income-statement/";
      std::string annual = "?period=annual";
      std::string quarter = "?period=quarter";
      std::string api_key = "&apikey=QF2iqVota4NgpfTScti1x5YrGdXIuaPw";
     
     
     
     if(period == "annual") {
            std::string url = base_url+ ticker + annual + api_key;
            response = perform_get_request(url);
            
        } else {
            std::string url = base_url+ ticker + quarter + api_key;
            response = perform_get_request(url); 
            
      }
      
      return response;
}

std::string get_company_balance_sheet(const std::string &ticker, const std::string &period){
    
    std::string response {""};
    
    std::string base_url = "https://financialmodelingprep.com/api/v3/balance-sheet-statement/";
    std::string annual = "?period=annual";
    std::string quarter = "?period=quarter";
    std::string api_key = "&apikey=QF2iqVota4NgpfTScti1x5YrGdXIuaPw";
    
    
    
     if(period == "annual") {
      std::string url = base_url+ ticker + annual + api_key;
      response = perform_get_request(url);
    
    } else {
      std::string url = base_url+ ticker + quarter + api_key;
      response = perform_get_request(url);
      
    }
    
    
    return response;
}


std::string get_company_historical_price(std::string ticker){
    std::string base_url = "https://financialmodelingprep.com/api/v3/historical-price-full/";
    std::string api_key ="&apikey=QF2iqVota4NgpfTScti1x5YrGdXIuaPw";
    
    std::string url = base_url+ticker+api_key;

    
    return  perform_get_request(url);
    
}


std::string get_company_key_ratios(std::string ticker){
   std::string base_url = "https://financialmodelingprep.com/api/v3/key-metrics/";
   std::string api_key = "&apikey=QF2iqVota4NgpfTScti1x5YrGdXIuaPw";
   std::string annual = "?period=annual";
   std::string quarter = "?period=quarter";
   
   std::string url = base_url+ ticker + annual + api_key;
   
   
   return perform_get_request(url);
    
}

std::string get_company_cash_flow(const std::string &ticker, const std::string &period){
   
   std::string response {""};
    
   std::string base_url = "https://financialmodelingprep.com/api/v3/cash-flow-statement/";
   std::string api_key = "&apikey=QF2iqVota4NgpfTScti1x5YrGdXIuaPw";
   std::string annual = "?period=annual";
   std::string quarter = "?period=quarter";
   
   if(period == "annual") {
      std::string url = base_url+ ticker + annual + api_key;
      response = perform_get_request(url);
      
    } else {
      std::string url = base_url+ ticker + quarter + api_key;
      response = perform_get_request(url);
     
    }
   
   
   return response;
    
    
}


void get_company_financials_statements(
     std::string ticker,
     std::vector<Balancesheet*> &banace_sheets,
     std::vector<Cashflowstatement*> &cashflow_statements,  
     std::vector<Income_statement*> &income_statements,
     std::vector<Key_ratios*> &ratios){
     
     std::string bs_response = get_company_balance_sheet(ticker, "annual");
     std::string cfs_response = get_company_cash_flow(ticker,"annual");
     std::string is_response = get_company_income_statement(ticker,"annual");
     std::string ratio_response = get_company_key_ratios(ticker);
     
     banace_sheets= parsing_json_from_api<Balancesheet>(bs_response,ticker);
     cashflow_statements = parsing_json_from_api<Cashflowstatement>(cfs_response,ticker);
     income_statements = parsing_json_from_api<Income_statement>(is_response,ticker);
     
    
    
}


void read_financials_from_file(std::string &ticker,
     std::vector<Balancesheet*> &banace_sheets,
     std::vector<Cashflowstatement*> &cashflow_statements,  
     std::vector<Income_statement*> &income_statements){
     
     
      
      
        
    
}


      
      
      
#endif