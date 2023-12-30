#include "CashflowStatementClasses.h"
#include "nlohmann/json.hpp"

void from_json(const nlohmann::json &j, Net_cash_flow_continuing &net_cash_flow_continuing){
    j.at("value").get_to(net_cash_flow_continuing.value);
    j.at("unit").get_to(net_cash_flow_continuing.unit);
    j.at("label").get_to(net_cash_flow_continuing.label);
    j.at("order").get_to(net_cash_flow_continuing.order);
}
void from_json(const nlohmann::json &j, Net_cash_flow_from_financing_activities_continuing &net_cash_flow_from_financing_activities_continuing){
    j.at("value").get_to(net_cash_flow_from_financing_activities_continuing.value);
    j.at("unit").get_to(net_cash_flow_from_financing_activities_continuing.unit);
    j.at("label").get_to(net_cash_flow_from_financing_activities_continuing.label);
    j.at("order").get_to(net_cash_flow_from_financing_activities_continuing.order);
}
void from_json(const nlohmann::json &j, Net_cash_flow_from_operating_activities &net_cash_flow_from_operating_activities){
    j.at("value").get_to(net_cash_flow_from_operating_activities.value);
    j.at("unit").get_to(net_cash_flow_from_operating_activities.unit);
    j.at("label").get_to(net_cash_flow_from_operating_activities.label);
    j.at("order").get_to(net_cash_flow_from_operating_activities.order);
}
void from_json(const nlohmann::json &j, Net_cash_flow_from_investing_activities &net_cash_flow_from_investing_activities){
    j.at("value").get_to(net_cash_flow_from_investing_activities.value);
    j.at("unit").get_to(net_cash_flow_from_investing_activities.unit);
    j.at("label").get_to(net_cash_flow_from_investing_activities.label);
    j.at("order").get_to(net_cash_flow_from_investing_activities.order);
}
void from_json(const nlohmann::json &j, Net_cash_flow_from_investing_activities_continuing &net_cash_flow_from_investing_activities_continuing){
    j.at("value").get_to(net_cash_flow_from_investing_activities_continuing.value);
    j.at("unit").get_to(net_cash_flow_from_investing_activities_continuing.unit);
    j.at("label").get_to(net_cash_flow_from_investing_activities_continuing.label);
    j.at("order").get_to(net_cash_flow_from_investing_activities_continuing.order);
}
void from_json(const nlohmann::json &j, Net_cash_flow &net_cash_flow){
    j.at("value").get_to(net_cash_flow.value);
    j.at("unit").get_to(net_cash_flow.unit);
    j.at("label").get_to(net_cash_flow.label);
    j.at("order").get_to(net_cash_flow.order);
}
void from_json(const nlohmann::json &j, Net_cash_flow_from_operating_activities_continuing &net_cash_flow_from_operating_activities_continuing){
    j.at("value").get_to(net_cash_flow_from_operating_activities_continuing.value);
    j.at("unit").get_to(net_cash_flow_from_operating_activities_continuing.unit);
    j.at("label").get_to(net_cash_flow_from_operating_activities_continuing.label);
    j.at("order").get_to(net_cash_flow_from_operating_activities_continuing.order);
}
void from_json(const nlohmann::json &j,Net_cash_flow_from_financing_activities &net_cash_flow_from_financing_activities){
    j.at("value").get_to(net_cash_flow_from_financing_activities.value);
    j.at("unit").get_to(net_cash_flow_from_financing_activities.unit);
    j.at("label").get_to(net_cash_flow_from_financing_activities.label);
    j.at("order").get_to(net_cash_flow_from_financing_activities.order);
}



