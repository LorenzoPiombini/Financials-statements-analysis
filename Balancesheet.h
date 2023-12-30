#ifndef _BALANCESHEET_H_
#define _BALANCESHEET_H_

#include "BalancesheetClasses.h"
#include "nlohmann/json.hpp"

class Balancesheet{
 
  private:
     Long_term_debt long_term_debt;
     Equity_attributable_to_parent equity_attributable_to_parent;
     Accounts_payable accounts_payable;
     Current_assets current_assets;
     Other_noncurrent_liabilities  other_noncurrent_liabilities;
     Liabilities_and_equity  liabilities_and_equity;
     Assets assets;
     Inventory inventory;
     Equity equity;
     Noncurrent_assets noncurrent_assets;
     Other_current_liabilities other_current_liabilities;
     Fixed_assets fixed_assets;
     Noncurrent_liabilities noncurrent_liabilities;
     Other_noncurrent_assets other_noncurrent_assets;
     Equity_attributable_to_noncontrolling_interest equity_attributable_to_noncontrolling_interest;
     Other_current_assets other_current_assets;
     Current_liabilities current_liabilities;
     Liabilities liabilities;
     
    public:
     Long_term_debt get_long_term_debt();
     Equity_attributable_to_parent get_equity_attributable_to_parent();
     Accounts_payable get_accounts_payable();
     Current_assets get_current_assets();
     Other_noncurrent_liabilities  get_other_noncurrent_liabilities();
     Liabilities_and_equity  get_liabilities_and_equity();
     Assets get_assets();
     Inventory get_inventory();
     Equity get_equity();
     Noncurrent_assets get_noncurrent_assets();
     Other_current_liabilities get_other_current_liabilities();
     Fixed_assets get_fixed_assets();
     Noncurrent_liabilities get_noncurrent_liabilities();
     Other_noncurrent_assets get_other_noncurrent_assets();
     Equity_attributable_to_noncontrolling_interest get_equity_attributable_to_noncontrolling_interest();
     Other_current_assets get_other_current_assets();
     Current_liabilities get_current_liabilities();
     Liabilities get_liabilities();
     
     friend void from_json(const nlohmann::json &j, Balancesheet &b);
};


#endif