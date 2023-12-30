#ifndef _COMPREHENSIVEINCOMECLASSES_H_
#define _COMPREHENSIVEINCOMECLASSES_H_


#include <string>
#include "nlohmann/json.hpp"

using std::string;

class Other_comprehensive_income_loss_attributable_to_parent{
        public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Other_comprehensive_income_loss_attributable_to_parent &other_comprehensive_income_loss_attributable_to_parent);

};

class Comprehensive_income_loss{
        public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j,Comprehensive_income_loss &comprehensive_income_loss);

};

class Comprehensive_income_loss_attributable_to_noncontrolling_interest {
           public:
            long long value; 
            string unit;
            string label;
            int order;  
            
            friend void from_json(const nlohmann::json &j, Comprehensive_income_loss_attributable_to_noncontrolling_interest &comprehensive_income_loss_attributable_to_noncontrolling_interest);  
};

class Comprehensive_income_loss_attributable_to_parent {
    public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j,Comprehensive_income_loss_attributable_to_parent &comprehensive_income_loss_attributable_to_parent);

};
class Other_comprehensive_income_loss {
     public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j,Other_comprehensive_income_loss &other_comprehensive_income_loss );
};



#endif