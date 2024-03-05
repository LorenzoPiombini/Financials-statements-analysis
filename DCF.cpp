#include "DCF.h"
#include <sstream>

double DCF::get_dcf() const{
  return dcf;    
}

std::string trim_dcf(const std::string &str){
  size_t first = str.find_first_not_of(" \t\n\r");
  
  if(first == std::string::npos) return "";    
  
   size_t last = str.find_last_not_of(" \t\n\r");
   return str.substr(first, (last - first +1));
}

void DCF::deserialize(std::string &json_string){
    std::string token;
    
    std::string trimmed_json = trim_dcf(json_string);
    
    
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
         
         auto key = trim_dcf(token.substr(0, separator_pos));
         auto value = trim_dcf(token.substr(separator_pos + 1));
         
        
        
          
          if (!key.empty() && key.front() == '"' && key.back() == '"') {
            key = key.substr(1, key.size() - 2);
          }
         if(!value.empty() && value.front() == '"' && value.back() =='"'){
             value = value.substr(1, value.size() - 2);
             }

//this line is for debugging 
//          std::cout <<"Key is long : " << key.length() << "and it looks like"+key<< std::endl;
          
          
         if(key == "symbol"){symbol = value;}
         if(key == "date"){date = value;}
         if(key == "dcf" && value != "null"){dcf = std::stod(value);}
         if(key == "Stock Price" && value != "null"){StockPrice = std::stod(value);}
    
        
    
}    
}

