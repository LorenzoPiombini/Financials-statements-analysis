#ifndef _RESPONSE_H_
#define _RESPONSE_H_

#include <string>
#include <vector>
#include "Financials.h"
#include "nlohmann/json_fwd.hpp"

using std::string;
using std::vector;



class Response{
private:
     string id;
     string start_date;
     string end_date;
     string filing_date;
     string acceptance_datetime;
     string timeframe;
     string fiscal_period;
     string fiscal_year;
     string cik;
     string sic;
     vector<string> tickers;
     string company_name;
     string source_filing_url;
     string source_filing_file_url;
     Financials financials;
     
public:
     string get_id();
     string get_start_date();
     string get_end_date();
     string get_filing_date();
     string get_acceptance_datetime();
     string get_timeframe();
     string get_fiscal_period();
     string get_fiscal_year();
     string get_cik();
     string get_sic();
     vector<string> get_tickers();
     string get_company_name();
     string get_source_filing_url();
     string get_source_filing_file_url();
     Financials get_financials();
     
     friend void from_json(const nlohmann::json &j, Response &res);
     
};





#endif