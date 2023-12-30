#include "Balancesheet.h"
#include "nlohmann/json.hpp"


Long_term_debt Balancesheet::get_long_term_debt(){
      return long_term_debt;
}

Equity_attributable_to_parent Balancesheet::get_equity_attributable_to_parent(){
        return equity_attributable_to_parent;
}
Accounts_payable Balancesheet::get_accounts_payable(){
        return accounts_payable;
}
Current_assets Balancesheet::get_current_assets(){
        return current_assets;
}
Other_noncurrent_liabilities  Balancesheet::get_other_noncurrent_liabilities(){
        return other_noncurrent_liabilities;
}
Liabilities_and_equity  Balancesheet::get_liabilities_and_equity(){
        return liabilities_and_equity;
}
Assets Balancesheet::get_assets(){
        return assets;
}

Inventory Balancesheet::get_inventory(){
        return inventory;
}
Equity Balancesheet::get_equity(){
        return equity;
}
Noncurrent_assets Balancesheet::get_noncurrent_assets(){
        return noncurrent_assets;
}
Other_current_liabilities Balancesheet::get_other_current_liabilities(){
        return other_current_liabilities;
}

Fixed_assets Balancesheet::get_fixed_assets(){
        return fixed_assets;
}

Noncurrent_liabilities Balancesheet::get_noncurrent_liabilities(){
       return noncurrent_liabilities;
}

Other_noncurrent_assets Balancesheet::get_other_noncurrent_assets(){
       return other_noncurrent_assets;
}
Equity_attributable_to_noncontrolling_interest Balancesheet::get_equity_attributable_to_noncontrolling_interest(){
        return equity_attributable_to_noncontrolling_interest;
}
Other_current_assets Balancesheet::get_other_current_assets(){
        return other_current_assets;
}

Current_liabilities Balancesheet::get_current_liabilities(){
        return current_liabilities;
}

Liabilities Balancesheet::get_liabilities(){
        return liabilities;
}

void from_json(const nlohmann::json &j, Balancesheet &b){
  
    if(j.contains("long_term_debt") && !j["long_term_debt"].empty()){
          j.at("long_term_debt").get_to(b.long_term_debt);
    } else {
          b.long_term_debt = Long_term_debt();
    }
  
   if(j.contains("equity_attributable_to_parent") && !j["equity_attributable_to_parent"].empty()){
          j.at("equity_attributable_to_parent").get_to(b.equity_attributable_to_parent);
    } else {
          b.equity_attributable_to_parent = Equity_attributable_to_parent();
    }
  
  
  if(j.contains("accounts_payable") && !j["accounts_payable"].empty()){
          j.at("accounts_payable").get_to(b.accounts_payable);
   }else{
          b.accounts_payable = Accounts_payable(); 
   }
  
  
  if(j.contains("current_assets") && !j["current_assets"].empty()){
     j.at("current_assets").get_to(b.current_assets);
   } else {
     b.current_assets = Current_assets();
  }
  
  
  if(j.contains("other_noncurrent_liabilities") && j["other_noncurrent_liabilities"].empty()){
        j.at("other_noncurrent_liabilities").get_to(b.other_noncurrent_liabilities);
   } else {
        b.other_noncurrent_liabilities = Other_noncurrent_liabilities();
   }
  
  if(j.contains("liabilities_and_equity") && !j["liabilities_and_equity"].empty()){
       j.at("liabilities_and_equity").get_to(b.liabilities_and_equity);
   } else {
       b.liabilities_and_equity = Liabilities_and_equity();
   }
 
  
  if(j.contains("assets") && !j["assets"].empty()){
        j.at("assets").get_to(b.assets);
  }else {
        b.assets = Assets();
  }
  
  if(j.contains("inventory") && !j["inventory"].empty()){
        j.at("inventory").get_to(b.inventory);
  } else {
        b.inventory = Inventory();
  }
  
  if(j.contains("equity") && !j["equity"].empty()){
        j.at("equity").get_to(b.equity);
  }else {
        b.equity = Equity();
  }
  
  if(j.contains("noncurrent_assets") && !j["noncurrent_assets"].empty()){
        j.at("noncurrent_assets").get_to(b.noncurrent_assets);
  }else{
        b.noncurrent_assets = Noncurrent_assets();
  }
  if(j.contains("other_current_liabilities") && !j["other_current_liabilities"].empty()){
        j.at("other_current_liabilities").get_to(b.other_current_liabilities);
  } else {
        b.other_current_liabilities = Other_current_liabilities();
  }
  
  if(j.contains("equity_attributable_to_noncontrolling_interest") && !j["equity_attributable_to_noncontrolling_interest"].empty()){
  j.at("equity_attributable_to_noncontrolling_interest").get_to(b.equity_attributable_to_noncontrolling_interest);
  } else{
      b.equity_attributable_to_noncontrolling_interest = Equity_attributable_to_noncontrolling_interest();
  }
  
  if(j.contains("other_current_assets") && !j["other_current_assets"].empty()){
      j.at("other_current_assets").get_to(b.other_current_assets);
   } else {
     b.other_current_assets = Other_current_assets();
   }
  
  
  if(j.contains("current_liabilities") && !j["current_liabilities"].empty()){
      j.at("current_liabilities").get_to(b.current_liabilities);
   } else {
       b.current_liabilities = Current_liabilities();
   }
  
  
  if(j.contains("liabilities") && !j["liabilities"].empty()){
      j.at("liabilities").get_to(b.liabilities);
   }else{
      b.liabilities = Liabilities();
   }
   
  if(j.contains("fixed_assets") && !j["fixed_assets"].empty()){
      j.at("fixed_assets").get_to(b.fixed_assets);
  }else{
      b.fixed_assets = Fixed_assets();
  }
  
  if(j.contains("noncurrent_liabilities") && !j["noncurrent_liabilities"].empty()){
     j.at("noncurrent_liabilities").get_to(b.noncurrent_liabilities);
  }else{
     b.noncurrent_liabilities = Noncurrent_liabilities();    
  }
  
  if(j.contains("other_noncurrent_assets") && !j["other_noncurrent_assets"].empty()){
        j.at("other_noncurrent_assets").get_to(b.other_noncurrent_assets);
  }else{
        b.other_noncurrent_assets = Other_noncurrent_assets();
  }
  
}