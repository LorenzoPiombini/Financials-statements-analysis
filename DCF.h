#ifndef _DCF_H_
#define _DCF_H_

#include <string>

class DCF {
   private:
      std::string symbol;
      std::string date;
      double dcf;  
      double StockPrice;
    
   public:
       
     void deserialize(std::string &json_string);
     double get_dcf() const;
     
    
 
    
};


#endif