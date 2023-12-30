#ifndef _INCOMESTATEMENTCLASSES_H_
#define _INCOMESTATEMENTCLASSES_H_

#include <string>
#include "nlohmann/json.hpp"

using std::string;

class Income_tax_expense_benefit {
        public:
            long long value; 
            string unit;
            string label;
            int order;
            
         friend void from_json(const nlohmann::json &j, Income_tax_expense_benefit &income_tax_expense_benefit);
};


class Participating_securities_distributed_and_undistributed_earnings_loss_basic {
        public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Participating_securities_distributed_and_undistributed_earnings_loss_basic &participating_securities_distributed_and_undistributed_earnings_loss_basic);
};
class Cost_of_revenue {
        public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Cost_of_revenue &cost_of_revenue);
};
  class Preferred_stock_dividends_and_other_adjustments{
     public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Preferred_stock_dividends_and_other_adjustments &preferred_stock_dividends_and_other_adjustments);
};

class Research_and_development{
        public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Research_and_development &research_and_development);
};
class Diluted_earnings_per_share {
        public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Diluted_earnings_per_share &diluted_earnings_per_share);
};

class Operating_income_loss{
        public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Operating_income_loss &operating_income_loss);
};
class Gross_profit {
       public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Gross_profit &gross_profit);
};
               
class Operating_expenses{
        public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Operating_expenses &operating_expenses);
};
class Diluted_average_shares {
        public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Diluted_average_shares &diluted_average_shares);
};
class Net_income_loss_attributable_to_parent {
     public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Net_income_loss_attributable_to_parent &net_income_loss_attributable_to_parent);
};
class Selling_general_and_administrative_expenses {
     public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Selling_general_and_administrative_expenses &selling_general_and_administrative_expenses);
};

class Revenues {
               public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Revenues &revenues);
};

class Interest_expense_operating {
        public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Interest_expense_operating &interest_expense_operating);
};

class Net_income_loss_attributable_to_noncontrolling_interest {
        public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Net_income_loss_attributable_to_noncontrolling_interest  &net_income_loss_attributable_to_noncontrolling_interest );
};

class Benefits_costs_expenses {
        public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Benefits_costs_expenses &benefits_costs_expenses);
};

class Net_income_loss_available_to_common_stockholders_basic {
         public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Net_income_loss_available_to_common_stockholders_basic &net_income_loss_available_to_common_stockholders_basic);
};

class Costs_and_expenses {
        public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Costs_and_expenses &costs_and_expenses);
};
               
class Net_income_loss {
      public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Net_income_loss &net_income_loss);
};

class Basic_average_shares {
     public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Basic_average_shares &basic_average_shares);
};

class Income_loss_from_continuing_operations_before_tax {
        public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Income_loss_from_continuing_operations_before_tax &income_loss_from_continuing_operations_before_tax);
};

class Basic_earnings_per_share {
      public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Basic_earnings_per_share &basic_earnings_per_share);
};
class Income_loss_from_continuing_operations_after_tax {
        public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Income_loss_from_continuing_operations_after_tax &income_loss_from_continuing_operations_after_tax);
};
              
class Nonoperating_income_loss {
           public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Nonoperating_income_loss &nonoperating_income_loss);
};
             

#endif