#ifndef _CASHFLOWSTATEMENT_H_
#define _CASHFLOWSTATEMENT_H_

#include "CashflowStatementClasses.h"
#include "nlohmann/json.hpp"

class Cashflowstatement{
    
    private:
        Net_cash_flow_from_operating_activities net_cash_flow_from_operating_activities;
        Net_cash_flow net_cash_flow;  
        Net_cash_flow_from_financing_activities_continuing net_cash_flow_from_financing_activities_continuing;
        Net_cash_flow_continuing net_cash_flow_continuing;
        Net_cash_flow_from_investing_activities_continuing net_cash_flow_from_investing_activities_continuing;
        Net_cash_flow_from_operating_activities_continuing net_cash_flow_from_operating_activities_continuing;
        Net_cash_flow_from_financing_activities net_cash_flow_from_financing_activities;
        Net_cash_flow_from_investing_activities net_cash_flow_from_investing_activities;

    public:
        Net_cash_flow_from_operating_activities get_net_cash_flow_from_operating_activities();
        Net_cash_flow get_net_cash_flow();  
        Net_cash_flow_from_financing_activities_continuing get_net_cash_flow_from_financing_activities_continuing();
        Net_cash_flow_continuing get_net_cash_flow_continuing();
        Net_cash_flow_from_investing_activities_continuing get_net_cash_flow_from_investing_activities_continuing();
        Net_cash_flow_from_operating_activities_continuing get_net_cash_flow_from_operating_activities_continuing();
        Net_cash_flow_from_financing_activities get_net_cash_flow_from_financing_activities();
        Net_cash_flow_from_investing_activities get_net_cash_flow_from_investing_activities();
    
        friend void from_json(const nlohmann::json &j, Cashflowstatement &c);
    
};


#endif