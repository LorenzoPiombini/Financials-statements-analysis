#include "Sharesfloat.h"


std::string Shares_float::get_symbol() const{
  return  symbol;
}
double Shares_float::get_free_float() const{
  return freeFloat;    
}
long long Shares_float::get_float_shares() const{
    return floatShares;
}
long long Shares_float::get_outstanding_shares() const{
    return outstandingShares;    
}
std::string Shares_float::get_source() const{
  return source;    
}
std::string Shares_float::get_date() const{
  return date;    
}
        
//void from_json(const nlohmann::json &j, Shares_float &s) {
//     
//     s.
//    
// 
//    }