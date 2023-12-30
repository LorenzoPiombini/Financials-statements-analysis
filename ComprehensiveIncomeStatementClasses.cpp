#include "ComprehensiveIncomeClasses.h"
#include "nlohmann/json.hpp"

void from_json(const nlohmann::json &j, Other_comprehensive_income_loss_attributable_to_parent &other_comprehensive_income_loss_attributable_to_parent){
    j.at("value").get_to(other_comprehensive_income_loss_attributable_to_parent.value);
    j.at("unit").get_to(other_comprehensive_income_loss_attributable_to_parent.unit);
    j.at("label").get_to(other_comprehensive_income_loss_attributable_to_parent.label);
    j.at("order").get_to(other_comprehensive_income_loss_attributable_to_parent.order);
}

void from_json(const nlohmann::json &j,Comprehensive_income_loss &comprehensive_income_loss){
    j.at("value").get_to(comprehensive_income_loss.value);
    j.at("unit").get_to(comprehensive_income_loss.unit);
    j.at("label").get_to(comprehensive_income_loss.label);
    j.at("order").get_to(comprehensive_income_loss.order);
}
void from_json(const nlohmann::json &j, Comprehensive_income_loss_attributable_to_noncontrolling_interest &comprehensive_income_loss_attributable_to_noncontrolling_interest){
    j.at("value").get_to(comprehensive_income_loss_attributable_to_noncontrolling_interest.value);
    j.at("unit").get_to(comprehensive_income_loss_attributable_to_noncontrolling_interest.unit);
    j.at("label").get_to(comprehensive_income_loss_attributable_to_noncontrolling_interest.label);
    j.at("order").get_to(comprehensive_income_loss_attributable_to_noncontrolling_interest.order);
}
void from_json(const nlohmann::json &j,Comprehensive_income_loss_attributable_to_parent &comprehensive_income_loss_attributable_to_parent){
    j.at("value").get_to(comprehensive_income_loss_attributable_to_parent.value);
    j.at("unit").get_to(comprehensive_income_loss_attributable_to_parent.unit);
    j.at("label").get_to(comprehensive_income_loss_attributable_to_parent.label);
    j.at("order").get_to(comprehensive_income_loss_attributable_to_parent.order);
}
void from_json(const nlohmann::json &j, Other_comprehensive_income_loss &other_comprehensive_income_loss){
    j.at("value").get_to(other_comprehensive_income_loss.value);
    j.at("unit").get_to(other_comprehensive_income_loss.unit);
    j.at("label").get_to(other_comprehensive_income_loss.label);
    j.at("order").get_to(other_comprehensive_income_loss.order);
}

