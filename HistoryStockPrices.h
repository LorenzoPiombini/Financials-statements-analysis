#ifndef _HISTORYSTOCKPRICES_H_
#define  _HISTORYSTOCKPRICES_H_

#include <string>
#include <vector>
#include "HistoricalPrice.h"


class History_stock_prices {

    private:
        std::string symbol;
        std::vector<Historical_price> historical;    
    public:
        std::string get_symbol()const;
        std::vector<Historical_price> get_historical() const&; 
        
       // if you want to use this class, you have to implement the follwing method:
       /****************************************************************************************************************
        *  void save_to_file(std::ofstream &out);                                                                      *
        *  bool read_from_file(std::ifstream &in,std::vector<HistoryStockPrice*> &prices);                             *      
        *  size_t compute_object_size() const ;                                                                        *
        *  bool read_size_from_buffer_balance(const std::vector<char> &buffer, size_t &pos, size_t &value);            * 
        *  bool reading_string_from_buffer_balance(const std::vector<char> &buffer, size_t &pos, std::string &value);  *
        *  void deserialize(std::string &json_string);                                                                 *
        ***************************************************************************************************************/
        
    
};


#endif