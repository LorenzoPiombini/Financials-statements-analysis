#ifndef _BALANCESHEETCLASSES_H
#define _BALANCESHEETCLASSES_H

#include <string>
#include "nlohmann/json.hpp"



class Accounts_payable {
    public:
            long long value; 
            std::string unit;
            std::string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Accounts_payable &account_payable);
};
class Fixed_assets{
    public:
            long long value;
            std::string unit;
            std::string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Fixed_assets &fixed_assets);
};
class Equity_attributable_to_noncontrolling_interest{
    public:
            long long value;
            std::string unit;
            std::string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Equity_attributable_to_noncontrolling_interest &equity_attributable_to_noncontrolling_interest);
};
class Noncurrent_liabilities{
    public:
            long long value;
            std::string unit;
            std::string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Noncurrent_liabilities &noncurrent_liabilities);
};
class Equity_attributable_to_parent{
    public:
            long long value;
            std::string unit;
            std::string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Equity_attributable_to_parent &equity_attributable_to_parent);
};
class Liabilities_and_equity {
    public:
            long long value;
            std::string unit;
            std::string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Liabilities_and_equity &liabilities_and_equity);
};
class Current_liabilities {
    public:
            long long value;
            std::string unit;
            std::string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Current_liabilities &current_liabilities);
};
class Other_noncurrent_assets {
    public:
            long long value;
            std::string unit;
            std::string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Other_noncurrent_assets &other_noncurrent_assets);
};
class Inventory{
    public:
            long long value;
            std::string unit;
            std::string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Inventory &inventory);
};
class Noncurrent_assets{
    public:
            long long value;
            std::string unit;
            std::string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Noncurrent_assets &noncurrent_assets);
};
class Other_noncurrent_liabilities{
   public:
            long long value;
            std::string unit;
            std::string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Other_noncurrent_liabilities &other_noncurrent_liabilities);
};
class Equity {
   public:
            long long value;
            std::string unit;
            std::string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Equity &equity);
};
class Long_term_debt {
   public:
            long long value;
            std::string unit;
            std::string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Long_term_debt &long_term_debt );
};
class Current_assets {
    public:
            long long value;
            std::string unit;
            std::string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Current_assets &current_assets);
};
class Assets{
   public:
            long long value;
            std::string unit;
            std::string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Assets &assets);
};
class Other_current_assets {
        public:
            long long value;
            std::string unit;
            std::string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Other_current_assets &other_current_assets);
};

class Other_current_liabilities {
        public:
            long long value;
            std::string unit;
            std::string label;
            int order;
            
            friend  void from_json(const nlohmann::json &j, Other_current_liabilities &other_current_liabilities);
};
class Liabilities {
    public:
            long long value;
            std::string unit;
            std::string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Liabilities &liabilities);
};

#endif