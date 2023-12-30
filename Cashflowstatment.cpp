#include <iostream>

#include "Cashflowstatement.h"
#include "nlohmann/json.hpp"

Net_cash_flow_from_operating_activities Cashflowstatement::get_net_cash_flow_from_operating_activities(){
    return net_cash_flow_from_operating_activities;
}
Net_cash_flow Cashflowstatement::get_net_cash_flow(){
    return net_cash_flow;
}
Net_cash_flow_from_financing_activities_continuing Cashflowstatement::get_net_cash_flow_from_financing_activities_continuing(){
    return net_cash_flow_from_financing_activities_continuing;
}
Net_cash_flow_continuing Cashflowstatement::get_net_cash_flow_continuing(){
    return net_cash_flow_continuing;
}
Net_cash_flow_from_investing_activities_continuing Cashflowstatement::get_net_cash_flow_from_investing_activities_continuing(){
    return net_cash_flow_from_investing_activities_continuing;
}
Net_cash_flow_from_operating_activities_continuing Cashflowstatement::get_net_cash_flow_from_operating_activities_continuing(){
    return net_cash_flow_from_operating_activities_continuing;
}
Net_cash_flow_from_financing_activities Cashflowstatement::get_net_cash_flow_from_financing_activities(){
    return net_cash_flow_from_financing_activities;
}
Net_cash_flow_from_investing_activities Cashflowstatement::get_net_cash_flow_from_investing_activities(){
    return net_cash_flow_from_investing_activities;
}

void from_json(const nlohmann::json &j, Cashflowstatement &c){
   j.at("net_cash_flow_from_operating_activities").get_to(c.net_cash_flow_from_operating_activities);
   j.at("net_cash_flow").get_to(c.net_cash_flow);
   j.at("net_cash_flow_from_financing_activities_continuing").get_to(c.net_cash_flow_from_financing_activities_continuing);
   j.at("net_cash_flow_continuing").get_to(c.net_cash_flow_continuing);
   j.at("net_cash_flow_from_investing_activities_continuing").get_to(c.net_cash_flow_from_investing_activities_continuing);
   j.at("net_cash_flow_from_operating_activities_continuing").get_to(c.net_cash_flow_from_operating_activities_continuing);
   j.at("net_cash_flow_from_financing_activities").get_to(c.net_cash_flow_from_financing_activities);
   j.at("net_cash_flow_from_investing_activities").get_to(c.net_cash_flow_from_investing_activities);
   
}