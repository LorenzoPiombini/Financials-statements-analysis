#include "Senate.h"
#include "Logger.h"

#include <string>
#include <sstream>

std::string Senate::get_first_name() const {
  return firstName;  
} 
std::string Senate::get_last_name() const{
   return lastName;  
}   
std::string Senate::get_office() const{
   return  office;   
}
std::string Senate::get_link() const{
   return  link;  
}
std::string Senate::get_date_recieved() const{
   return dateRecieved;    
}
std::string Senate::get_transaction_date() const{
   return transactionDate;    
}
std::string Senate::get_owner()const{
   return  owner;   
}
std::string Senate::get_asset_description()const{
   return assetDescription;    
}
std::string Senate::get_asset_type()const{
   return assetType;     
}
std::string Senate::get_type()const{
   return  type;    
}
std::string Senate::get_amount() const{
   return amount;    
}
std::string Senate::get_comment() const{
   return comment;    
}
std::string Senate::get_symbol() const{
   return symbol;   
}

std::string trim_senator(const std::string &str){
  size_t first = str.find_first_not_of(" \t\n\r");
  
  if(first == std::string::npos) return "";    
  
   size_t last = str.find_last_not_of(" \t\n\r");
   return str.substr(first, (last - first +1));
}

void Senate::deserialize(std::string &json_string){
    std::string token;
    
    std::string trimmed_json = trim_senator(json_string);
    
    
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
         
         auto key = trim_senator(token.substr(0, separator_pos));
         auto value = trim_senator(token.substr(separator_pos + 1));
         
        
        
          
          if (!key.empty() && key.front() == '"' && key.back() == '"') {
            key = key.substr(1, key.size() - 2);
          }
         if(!value.empty() && value.front() == '"' && value.back() =='"'){
             value = value.substr(1, value.size() - 2);
             }

//this line is for debugging 
 //         std::cout <<"Key is long : " << key.length() << "and it looks like"+key<< std::endl;

          if(key == "firstName"){firstName = value;}
          if(key == "lastName"){lastName = value;}
          if(key == "office"){office = value;}
          if(key == "link"){link = value;}
          if(key == "dateRecieved"){dateRecieved = value;}
          if(key == "transactionDate"){transactionDate = value;}
          if(key == "owner"){owner = value;}
          if(key == "assetDescription"){assetDescription = value;}
          if(key == "assetType"){assetType = value;}
          if(key == "type"){type = value;}
          if(key == "amount"){amount = value;}
          if(key == "comment"){comment = value;}
          if(key == "symbol"){symbol = value;}
    
    }
    
}


