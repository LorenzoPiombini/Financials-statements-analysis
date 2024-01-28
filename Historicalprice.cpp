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
//void from_json(const nlohmann::json &j, Historical_price &h){
//   
//   if(j.contains("date") && !j["date"].empty()){
//       j.at("date").get_to(h.date);
//    }else {
//        h.date = "nf";
//    } 
//  
//   if(j.contains("open") && !j["open"].empty()){
//        j.at("open").get_to(h.open);
//    }else {
//        h.open = 0.0;
//    }  
//   if(j.contains("high") && !j["high"].empty()){
//        j.at("high").get_to(h.high);
//    }else {
//        h.high = 0.0;
//    }  
//   if(j.contains("low") && !j["low"].empty()){
//        j.at("low").get_to(h.low);
//    }else {
//        h.low = 0.0;
//    }  
//   if(j.contains("close") && !j["close"].empty()){
//       j.at("close").get_to(h.close);
//    }else {
//        h.close = 0;
//    }  
//   if(j.contains("adjClose") && !j["adjClose"].empty()){
//       j.at("adjClose").get_to(h.adjClose);
//    }else {
//        h.adjClose = 0.0;
//    }  
//   if(j.contains("volume") && !j["volume"].empty()){
//       j.at("volume").get_to(h.volume);
//    }else {
//        h.volume = 0.0;
//    }  
//   if(j.contains("unadjustedVolume") && !j["unadjustedVolume"].empty()){
//       j.at("unadjustedVolume").get_to(h.unadjustedVolume);
//    }else {
//        h.unadjustedVolume=0.0;
//    }  
//    
//    if(j.contains("change") && !j["change"].empty()){
//       j.at("change").get_to(h.change);
//    }else {
//        h.change =0.0;
//    }  
//    
//    if(j.contains("changePercent") && !j["changePercent"].empty()){
//       j.at("changePercent").get_to(h.changePercent);
//    }else {
//        h.changePercent=0.0;
//    }  
//    
//    if(j.contains("vwap") && !j["vwap"].empty()){
//       j.at("vwap").get_to(h.vwap);
//    }else {
//       h.vwap = 0.0;
//    }  
//    
//    if(j.contains("label") && !j["label"].empty()){
//       j.at("label").get_to(h.label);
//    }else {
//        h.label = "nf";
//    }  
//    
//    if(j.contains("changeOverTime") && !j["changeOverTime"].empty()){
//       j.at("changeOverTime").get_to(h.changeOverTime);
//    }else {
//       h.changeOverTime = 0.0;
//    }  
//}