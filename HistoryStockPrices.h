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
        
       //friend void from_json(nlohmann::json &j, History_stock_prices &h);
        
    
};


#endif