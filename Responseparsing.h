#ifndef _RESPONSEPARSING_H_
#define _RESPONSEPARSING_H_


#include "HistoryStockPrices.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>


/*
 * 
 * function that handle the Json response from th API
 * 
 */

std::vector<std::string> split_json_objects(const std::string &json_response){
     char ch {};
     std::vector<std::string> json_objects;
     std::istringstream stream(json_response);
     bool in_string = false; // flag to check if we are inside the string 
     int brace_count = 0;
     std::string obj_str{};
     
     while(stream.get(ch)){
            
          if(ch == '"'){
                in_string = !in_string;
           }
           
           if(!in_string){
                 if(ch =='{'){
                        if(brace_count == 0){
                               obj_str.clear();
                            }
                            brace_count++;
                  }else if(ch == '}'){
                      brace_count--;
                        if(brace_count == 0){
                                obj_str.push_back(ch);
                                json_objects.push_back(obj_str);
                                continue;
                         }
                  }
               }
               
               if(brace_count > 0){
                      obj_str.push_back(ch);
                   }
         
         
    }
    
    return json_objects;
}



template <typename T>
std::vector<T*> parsing_atempt(const std::string &response_json, std::string &ticker){
    std::vector<std::string> extracyed_json = split_json_objects(response_json);
     
    std::vector<T*> responses;
    // Ensure T has a deserialize method accepting a std::string
//    static_assert(std::is_member_function_pointer<decltype(&T::deserialize)>::value,
//                  "T must have a deserialize method accepting std::string");
//                  
    
    
    for(auto &item : extracyed_json){
         
        T* response = new T();
        response ->deserialize(item);
        responses.push_back(response); 
     }
     
     return responses;
    
}






#endif