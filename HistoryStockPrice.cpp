#include "HistoryStockPrices.h"


std::string History_stock_prices::get_symbol()const{
  return  symbol;   
}
std::vector<Historical_price> History_stock_prices::get_historical() const& {
    return historical;
}
        
void from_json(nlohmann::json &j, History_stock_prices &h){
    
    if(j.contains("symbol") && !j["symbol"].empty()){
        j.at("symbol").get_to(h.symbol);
    }else{
        h.symbol = "nf";
     }
    
      if(j.contains("historical") && !j["historical"].empty()){
        j.at("historical").get_to(h.historical);
     }
}