#ifndef _EXCHANGE_H_
#define _EXCHANGE_H_

#include <string>
#include <map>


class Exchange{
      private:
          std::map<std::string,std::string> symbols;
          
      public:
          std::map<std::string,std::string>  get_symbols() const;
          void deserialize(std::string &json_string);
        
    
    }; 

#endif 