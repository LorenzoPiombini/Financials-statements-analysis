#ifndef _RESPONSEPARSING_H_
#define _RESPONSEPARSING_H_

#include "nlohmann/json.hpp"
#include "Response.h"
#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::cerr;
using std::vector;

vector<Response> parsingJsonFromTheAPI(string responseJson){
    
     vector<Response> responses;
    try{
            
          auto json_obj = nlohmann::json::parse(responseJson);
          
          if(json_obj.contains("results") && !json_obj["results"].empty()){
                
              
                 auto &result = json_obj["results"];
                 
                 for(size_t i{0}; i < result.size(); ++i){
                    
                     Response response = result[i].get<Response>();
                     responses.push_back(response);
                     std::cout << "parsing attepmpt nr: "<< i<<"\n";
                 }
                
                    
                return responses;
              
            } else {
                std::cout<< "there is no results array.";
                
            }
            
            
            
            //from_json(json_obj,response);
            
    } catch (const nlohmann::json::exception &e){
          cerr << "Error parsing json. " << e.what() <<"\n";
          cerr << "Exception id: " << e.id <<"\n";
          
        }
    
    
    return responses;
}


#endif