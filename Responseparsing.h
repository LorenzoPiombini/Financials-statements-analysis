#ifndef _RESPONSEPARSING_H_
#define _RESPONSEPARSING_H_


#include "HistoryStockPrices.h"
#include "nlohmann/json.hpp"
#include <string>
#include <iostream>
#include <vector>




template <typename T>
std::vector<T*> parsing_json_from_api(const std::string& responseJson, std::string ticker){
    
     std::vector<T*> responses;
    try{
            
          auto json_obj = nlohmann::json::parse(responseJson);
        
             try{
                    for(const auto& item : json_obj){
                       // std::cout << item;
                        T* response = new T(item.get<T>());
                        responses.push_back(response);
                        
                    }
             } catch (const nlohmann::json::exception &e){
                     std::cerr << "Error parsing json. " << e.what() <<"\n";
                     std::cerr << "Exception id: " << e.id <<"\n";
                     
             }
             
       if (responses.empty()) {
            std::cout << "No result for " << ticker << "\n";
        }
                
              
          
            
        
            
    } catch (const nlohmann::json::exception &e){
          std::cerr << "Error parsing json. " << e.what() <<"\n";
          std::cerr << "Exception id: " << e.id <<"\n";
          
          
        }
    
    
    return responses;
}


/*
 * define the fucntion to parse historical data
 * 
 * */

//History_stock_prices parse_json_from_api_for_history_prices(const std::string &jsonResponse, std::string ticker){
//    try{
//        
//         auto json_obj = nlohmann::json::parse(jsonResponse);
//         
//         return json_obj.get<History_stock_prices>();
//        
//    } catch (const nlohmann::json::exception &e){
//        std::cerr << "Error parsing JSON " << e.what() << "\n";
//    }
//    
//} 



#endif