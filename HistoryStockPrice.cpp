#include "HistoryStockPrices.h"


std::string History_stock_prices::get_symbol()const{
  return  symbol;   
}
std::vector<Historical_price> History_stock_prices::get_historical() const& {
    return historical;
}
  