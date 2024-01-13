#ifndef _SHARESFLOAT_H_
#define _SHARESFLOAT_H_

#include <string>
#include "nlohmann/json.hpp"
class Shares_float{
    
    private:
        std::string symbol;
		double freeFloat;
		long long floatShares;
		long long outstandingShares;
		std::string source;
        std::string date;
    public:
        std::string get_symbol() const;
		double get_free_float() const;
		long long get_float_shares() const;
		long long get_outstanding_shares() const;
		std::string get_source() const;
        std::string get_date() const;
        
        friend void from_json(const nlohmann::json &j, Shares_float &s);
};
		


#endif