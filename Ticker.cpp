#include "Ticker.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include "Logger.h"


std::string Ticker::get_symbol() const{
 return symbol;    
}
std::string Ticker::get_exchange() const{
 return exchange;    
}
std::string Ticker::get_exchange_short_name() const{
 return exchangeShortName; 
}
double Ticker::get_price()const{
 return price;    
}

std::string Ticker::get_type() const{
 return type;    
}

std::string Ticker::get_name()const{
 return name;    
}

std::string Ticker::get_class_name()const{
  return "ticker";    
}

std::string Ticker::create_file_name()const{
    
         return "all_ticker.bin";
        
}

//functions used in the deserialized method
std::string Ticker::trim_ticker(const std::string &str){
  size_t first = str.find_first_not_of(" \t\n\r");
  
  if(first == std::string::npos) return "";    
  
   size_t last = str.find_last_not_of(" \t\n\r");
   return str.substr(first, (last - first +1));
}

void Ticker::deserialize(std::string &json_string){
   std::string token;

   std::string trimmed_json = trim_ticker(json_string);
    
    
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
         
         auto key = trim_ticker(token.substr(0, separator_pos));
         auto value = trim_ticker(token.substr(separator_pos + 1));
         
         if (!key.empty() && key.front() == '"' && key.back() == '"') {
            key = key.substr(1, key.size() - 2);
          }
         if(!value.empty() && value.front() == '"' && value.back() =='"'){
             value = value.substr(1, value.size() - 2);
             }
             
        //std::cout<<"Key: " << key << "Value: "<< value << std::endl;
    
         if(key == "symbol"){symbol = value;}
         if(key == "exchange"){exchange = value;}
         if(key == "exchangeShortName"){exchangeShortName = value;}
         if(key == "price" && value != "null"){price = stod(value);}
         if(key == "name" ){name = value;}
         if(key == "type"){type = value;}
    }
}


size_t Ticker::compute_object_size() const {
     size_t total_size {0};
     total_size += symbol.size() * sizeof(char);
     total_size += exchange.size() * sizeof(char);
     total_size += exchangeShortName.size() * sizeof(char);
     total_size += name.size() * sizeof(char);
     total_size += type.size() * sizeof(char);
     
     total_size += sizeof(size_t) * 5; // number of the string members
     total_size += sizeof(double); // just one double
     
     return total_size;
}

void Ticker::save_to_file(std::ofstream &out){
    
   
    
    
     size_t obj_size = this-> compute_object_size();
     out.write(reinterpret_cast<const char*>(&obj_size), sizeof(obj_size));
     
     
      size_t symbol_len = symbol.size();
      out.write(reinterpret_cast<const char*>(&symbol_len), sizeof(symbol_len));
      out.write(symbol.c_str(), symbol_len);
      
      size_t name_len = name.size();
      out.write(reinterpret_cast<const char*>(&name_len), sizeof(name_len));
      out.write(name.c_str(), name_len);
      
      out.write(reinterpret_cast<const char*>(&price), sizeof(price));
      
      size_t exchange_len = exchange.size();
      out.write(reinterpret_cast<const char*>(&exchange_len), sizeof(exchange_len));
      out.write(exchange.c_str(), exchange_len);
      
      size_t exchange_short_name_len = exchangeShortName.size();
      out.write(reinterpret_cast<const char*>(&exchange_short_name_len), sizeof(exchange_short_name_len));
      out.write(exchangeShortName.c_str(), exchange_short_name_len);
      
      size_t type_len = type.size();
      out.write(reinterpret_cast<const char*>(&type_len), sizeof(type_len));
      out.write(type.c_str(), type_len);
      
      
      
    
}

bool Ticker::read_size_from_buffer_tk(const std::vector<char> &buffer, size_t &pos, size_t &value){
     if(pos+sizeof(size_t)> buffer.size()) return false;
        std::memcpy(&value, buffer.data() + pos, sizeof(size_t));
        pos += sizeof(size_t);
        
        return true;
}
bool Ticker::reading_string_from_buffer_tk(const std::vector<char> &buffer, size_t &pos, std::string &value){
    size_t lenght;
    
    if(!read_size_from_buffer_tk(buffer,pos,lenght)) return false;
    
    if(pos + lenght > buffer.size())return false;
    
    value.assign(buffer.data() + pos, lenght);
    pos += lenght;
    
    return true;
}

template <typename T>
bool read_number_values_from_buffer_tk(std::vector<char> &buffer, size_t &pos, T &value){
    if(pos + sizeof(T) > buffer.size()) return false;
    
    std::memcpy(&value, buffer.data() + pos, sizeof(T));
    
    pos += sizeof(T);
    return true;
    
}

bool Ticker::read_from_file(std::ifstream &in,std::vector<Ticker*> &tickers){
     Logger logger("read_all_tickers_file");
     if (!in){
      logger.log("IO stream it is not open or some error with it.",Logger::Level::Error);   
    }
    
    
    while(in && !in.eof()){
    
    size_t obj_size;
    
    if(!in.read(reinterpret_cast<char*>(&obj_size), sizeof(obj_size))){
        if(in.eof()){
            break;
        }  
        logger.log("Couldn't read object size from the file regarding class " + get_class_name(),Logger::Level::Error);
        return false;
    }
    
    
    
     Ticker* ticker = new Ticker();
     std::vector<char> buffer(obj_size);
     
     if(!in.read(buffer.data(),obj_size)){
         logger.log("failed to read object data from file class "+get_class_name(),Logger::Level::Error);
         return false;
      }
      
      
      
            size_t bytes_read = in.gcount();
        if (bytes_read != obj_size) {
            delete ticker; // Clean up on error
            return false;
        }
        size_t pos = 0;
        
       
        if(!reading_string_from_buffer_tk(buffer, pos,ticker ->symbol)){
            logger.log("Error reading 'symbol' in " +get_class_name(),Logger::Level::Error);
            }
            
            if(!reading_string_from_buffer_tk(buffer, pos,ticker ->name)){
             logger.log("Error reading 'name' in " +get_class_name(),Logger::Level::Error);
             }
             
              if(!read_number_values_from_buffer_tk(buffer, pos,ticker ->price)){
             logger.log("Error reading 'price' in " +get_class_name(),Logger::Level::Error);
             }
             
        if(!reading_string_from_buffer_tk(buffer, pos,ticker ->exchange)){
             logger.log("Error reading 'exchange' in "  +get_class_name(),Logger::Level::Error);
             }
         if(!reading_string_from_buffer_tk(buffer, pos,ticker ->exchangeShortName)){
             logger.log("Error reading 'exchangeShortName' in " +get_class_name(),Logger::Level::Error);
             }
             
             if(!reading_string_from_buffer_tk(buffer, pos,ticker ->type)){
             logger.log("Error reading 'type' in " +get_class_name(),Logger::Level::Error);
             }
         
           
             
             
           if(ticker != nullptr){
             
             tickers.push_back(ticker);
         }else {
           logger.log("there is no value in this ptr",Logger::Level::Info);   
             
         }
         
         
        if(bytes_read  < buffer.size()){
           
            logger.log("Reached EOF! no more data to read in for "+get_class_name(),Logger::Level::Warning);
            return false;
            
            }
       
     }


    return true;    
      
}
            
