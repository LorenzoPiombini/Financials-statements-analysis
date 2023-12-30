#include "BalancesheetClasses.h"
#include "nlohmann/json.hpp"


void from_json(const nlohmann::json &j, Accounts_payable &account_payable){
    j.at("value").get_to(account_payable.value);
    j.at("unit").get_to(account_payable.unit);
    j.at("label").get_to(account_payable.label);
    j.at("order").get_to(account_payable.order);
    
}
void from_json(const nlohmann::json &j, Fixed_assets &fixed_assets){
    j.at("value").get_to(fixed_assets.value);
    j.at("unit").get_to(fixed_assets.unit);
    j.at("label").get_to(fixed_assets.label);
    j.at("order").get_to(fixed_assets.order);
}
void from_json(const nlohmann::json &j, Equity_attributable_to_noncontrolling_interest &equity_attributable_to_noncontrolling_interest){
    j.at("value").get_to(equity_attributable_to_noncontrolling_interest.value);
    j.at("unit").get_to(equity_attributable_to_noncontrolling_interest.unit);
    j.at("label").get_to(equity_attributable_to_noncontrolling_interest.label);
    j.at("order").get_to(equity_attributable_to_noncontrolling_interest.order);
}
void from_json(const nlohmann::json &j, Noncurrent_liabilities &noncurrent_liabilities){
    j.at("value").get_to(noncurrent_liabilities.value);
    j.at("unit").get_to(noncurrent_liabilities.unit);
    j.at("label").get_to(noncurrent_liabilities.label);
    j.at("order").get_to(noncurrent_liabilities.order);
}
void from_json(const nlohmann::json &j, Equity_attributable_to_parent &equity_attributable_to_parent){
    j.at("value").get_to(equity_attributable_to_parent.value);
    j.at("unit").get_to(equity_attributable_to_parent.unit);
    j.at("label").get_to(equity_attributable_to_parent.label);
    j.at("order").get_to(equity_attributable_to_parent.order);
}
void from_json(const nlohmann::json &j, Liabilities_and_equity &liabilities_and_equity){
    j.at("value").get_to(liabilities_and_equity.value);
    j.at("unit").get_to(liabilities_and_equity.unit);
    j.at("label").get_to(liabilities_and_equity.label);
    j.at("order").get_to(liabilities_and_equity.order);
}

void from_json(const nlohmann::json &j, Other_noncurrent_assets &other_noncurrent_assets){
    j.at("value").get_to(other_noncurrent_assets.value);
    j.at("unit").get_to(other_noncurrent_assets.unit);
    j.at("label").get_to(other_noncurrent_assets.label);
    j.at("order").get_to(other_noncurrent_assets.order);
}
void from_json(const nlohmann::json &j, Inventory &inventory){
    j.at("value").get_to(inventory.value);
    j.at("unit").get_to(inventory.unit);
    j.at("label").get_to(inventory.label);
    j.at("order").get_to(inventory.order);
}
void from_json(const nlohmann::json &j, Noncurrent_assets &noncurrent_assets){
    j.at("value").get_to(noncurrent_assets.value);
    j.at("unit").get_to(noncurrent_assets.unit);
    j.at("label").get_to(noncurrent_assets.label);
    j.at("order").get_to(noncurrent_assets.order);
}
void from_json(const nlohmann::json &j, Other_noncurrent_liabilities &other_noncurrent_liabilities){
    j.at("value").get_to(other_noncurrent_liabilities.value);
    j.at("unit").get_to(other_noncurrent_liabilities.unit);
    j.at("label").get_to(other_noncurrent_liabilities.label);
    j.at("order").get_to(other_noncurrent_liabilities.order);
}
void from_json(const nlohmann::json &j, Equity &equity){
    j.at("value").get_to(equity.value);
    j.at("unit").get_to(equity.unit);
    j.at("label").get_to(equity.label);
    j.at("order").get_to(equity.order);
}
void from_json(const nlohmann::json &j, Long_term_debt &long_term_debt ){
    j.at("value").get_to(long_term_debt.value);
    j.at("unit").get_to(long_term_debt.unit);
    j.at("label").get_to(long_term_debt.label);
    j.at("order").get_to(long_term_debt.order);
}
void from_json(const nlohmann::json &j, Current_assets &current_assets){
    j.at("value").get_to(current_assets.value);
    j.at("unit").get_to(current_assets.unit);
    j.at("label").get_to(current_assets.label);
    j.at("order").get_to(current_assets.order);
}
void from_json(const nlohmann::json &j, Assets &assets){
    j.at("value").get_to(assets.value);
    j.at("unit").get_to(assets.unit);
    j.at("label").get_to(assets.label);
    j.at("order").get_to(assets.order);
}
void from_json(const nlohmann::json &j, Other_current_assets &other_current_assets){
    j.at("value").get_to(other_current_assets.value);
    j.at("unit").get_to(other_current_assets.unit);
    j.at("label").get_to(other_current_assets.label);
    j.at("order").get_to(other_current_assets.order);
}
void from_json(const nlohmann::json &j, Other_current_liabilities &other_current_liabilities){
    j.at("value").get_to(other_current_liabilities.value);
    j.at("unit").get_to(other_current_liabilities.unit);
    j.at("label").get_to(other_current_liabilities.label);
    j.at("order").get_to(other_current_liabilities.order);
}
void from_json(const nlohmann::json &j, Liabilities &liabilities){
    j.at("value").get_to(liabilities.value);
    j.at("unit").get_to(liabilities.unit);
    j.at("label").get_to(liabilities.label);
    j.at("order").get_to(liabilities.order);
}

void from_json(const nlohmann::json &j, Current_liabilities &current_liabilities){
    j.at("value").get_to(current_liabilities.value);
    j.at("unit").get_to(current_liabilities.unit);
    j.at("label").get_to(current_liabilities.label);
    j.at("order").get_to(current_liabilities.order);
}
