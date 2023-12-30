#include "ComprehensiveIncome.h"
#include "nlohmann/json.hpp"

Other_comprehensive_income_loss_attributable_to_parent Comprehensiveincome::get_other_comprehensive_income_loss_attributable_to_parent(){
    return other_comprehensive_income_loss_attributable_to_parent;
}
Comprehensive_income_loss Comprehensiveincome::get_comprehensive_income_loss(){
    return comprehensive_income_loss;
}
Comprehensive_income_loss_attributable_to_noncontrolling_interest Comprehensiveincome::get_comprehensive_income_loss_attributable_to_noncontrolling_interest(){
    return comprehensive_income_loss_attributable_to_noncontrolling_interest;
}
Comprehensive_income_loss_attributable_to_parent Comprehensiveincome::get_comprehensive_income_loss_attributable_to_parent(){
    return comprehensive_income_loss_attributable_to_parent;
}
Other_comprehensive_income_loss Comprehensiveincome::get_other_comprehensive_income_loss(){
    return other_comprehensive_income_loss;
}

void from_json(const nlohmann::json &j, Comprehensiveincome &ci){
    if(j.contains("other_comprehensive_income_loss_attributable_to_parent") && !j["other_comprehensive_income_loss_attributable_to_parent"].empty()){
        j.at("other_comprehensive_income_loss_attributable_to_parent").get_to(ci.other_comprehensive_income_loss_attributable_to_parent);
    }else {
        ci.other_comprehensive_income_loss_attributable_to_parent = Other_comprehensive_income_loss_attributable_to_parent();
    }
    
    if(j.contains("comprehensive_income_loss") && !j["comprehensive_income_loss"].empty()){
        j.at("comprehensive_income_loss").get_to(ci.comprehensive_income_loss);
    }else {
        ci.comprehensive_income_loss = Comprehensive_income_loss();
    }
    
    if(j.contains("comprehensive_income_loss_attributable_to_noncontrolling_interest") && !j["comprehensive_income_loss_attributable_to_noncontrolling_interest"].empty()){
        j.at("comprehensive_income_loss_attributable_to_noncontrolling_interest").get_to(ci.comprehensive_income_loss_attributable_to_noncontrolling_interest);
    }else {
        ci.comprehensive_income_loss_attributable_to_noncontrolling_interest = Comprehensive_income_loss_attributable_to_noncontrolling_interest();
    }
    
    if(j.contains("comprehensive_income_loss_attributable_to_parent") && !j["comprehensive_income_loss_attributable_to_parent"].empty()){
        j.at("comprehensive_income_loss_attributable_to_parent").get_to(ci.other_comprehensive_income_loss_attributable_to_parent);
    }else {
        ci.comprehensive_income_loss_attributable_to_parent= Comprehensive_income_loss_attributable_to_parent();
    }
    
    if(j.contains("other_comprehensive_income_loss") && !j["other_comprehensive_income_loss"].empty()){
        j.at("other_comprehensive_income_loss").get_to(ci.other_comprehensive_income_loss);
    }else {
        ci.other_comprehensive_income_loss = Other_comprehensive_income_loss();
    }
    
    
    
    
    
    
    
}