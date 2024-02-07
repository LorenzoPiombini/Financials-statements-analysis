#ifndef _TICKER_H_
#define _TICKER_H_

#include <string>
#include <fstream>
#include <vector>

class Ticker{
       private: 
        std::string symbol;
        std::string name;
        double price;
		std::string exchange;
		std::string exchangeShortName;
         std::string type;
		
		
   
        public:
            std::string get_type() const;
            std::string get_symbol() const;
            std::string get_exchange() const;
            std::string get_exchange_short_name() const;
            double get_price()const;
            std::string get_name()const;
            void deserialize(std::string &json_string);
            std::string trim_ticker(const std::string &str);
            std::string get_class_name()const;
            std::string create_file_name()const;
            size_t compute_object_size() const ;
            void save_to_file(std::ofstream &out);
            bool read_from_file(std::ifstream &in,std::vector<Ticker*> &tickers);
            bool read_size_from_buffer_tk(const std::vector<char> &buffer, size_t &pos, size_t &value);
            bool reading_string_from_buffer_tk(const std::vector<char> &buffer, size_t &pos, std::string &value);
            
    
};


#endif