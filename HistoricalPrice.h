#ifndef _HISTORICALPRICE_H_
#define  _HISTORICALPRICE_H_

#include <string>
#include "nlohmann/json.hpp"

class Historical_price{
    
  private:
      std::string date;
      double open;
      double high;
      double low;
      double close;
      double adjClose;
      double volume;
      double unadjustedVolume;
      double change;
      double changePercent;
      double vwap;
      std::string label;
      double changeOverTime;

  public:
      std::string get_date();
      double get_open();
      double get_high();
      double get_low();
      double get_close();
      double get_adj_close();
      double get_volume();
      double get_unadjusted_volume();
      double get_change();
      double get_change_percent();
      double get_vwap();
      std::string get_label();
      double get_change_over_time();
      
      friend void from_json(const nlohmann::json &json, Historical_price &h);
 
};



#endif