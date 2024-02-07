#include "HistoricalPrice.h"



std::string Historical_price::get_date(){
 return date;    
}
double Historical_price::get_open(){
 return open;
}
double Historical_price::get_high(){
 return high;    
}

double Historical_price::get_low(){
    return low;
}
double Historical_price::get_close(){
  return close;    
}
double Historical_price::get_adj_close(){
   return adjClose;
}
double Historical_price::get_volume(){
   return volume;
}
double Historical_price::get_unadjusted_volume(){
   return   unadjustedVolume;  
}
double Historical_price::get_change(){
    return change;
}
double Historical_price::get_change_percent(){
    return changePercent;
}
double Historical_price::get_vwap(){
   return vwap;    
}
std::string Historical_price::get_label(){
    return label;
}
double Historical_price::get_change_over_time(){
   return changeOverTime; 
}