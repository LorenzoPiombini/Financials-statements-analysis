#ifndef _CASHFLOWSTATEMENTCLASSES_H_
#define _CASHFLOWSTATEMENTCLASSES_H_

#include <string>
#include "nlohmann/json.hpp"

using std::string;

class Net_cash_flow_continuing {
    public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Net_cash_flow_continuing &net_cash_flow_continuing);
};
class Net_cash_flow_from_financing_activities_continuing{
    public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Net_cash_flow_from_financing_activities_continuing &net_cash_flow_from_financing_activities_continuing);
};
class Net_cash_flow_from_operating_activities {
    public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Net_cash_flow_from_operating_activities &net_cash_flow_from_operating_activities);
};

class Net_cash_flow_from_investing_activities {
    public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Net_cash_flow_from_investing_activities &net_cash_flow_from_investing_activities);
};

class Net_cash_flow_from_investing_activities_continuing {
      public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Net_cash_flow_from_investing_activities_continuing &net_cash_flow_from_investing_activities_continuing);
};

class Net_cash_flow {
    public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Net_cash_flow &net_cash_flow);
};

class Net_cash_flow_from_operating_activities_continuing {
    public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j, Net_cash_flow_from_operating_activities_continuing &net_cash_flow_from_operating_activities_continuing);
};
class Net_cash_flow_from_financing_activities {
    public:
            long long value; 
            string unit;
            string label;
            int order;
            
            friend void from_json(const nlohmann::json &j,Net_cash_flow_from_financing_activities &net_cash_flow_from_financing_activities);

};

#endif