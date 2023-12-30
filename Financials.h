#ifndef _FINANCIALS_H_
#define _FINANCIALS_H_

#include "Balancesheet.h"
#include "Cashflowstatement.h"
#include "Incomestatement.h"
#include "ComprehensiveIncome.h"
#include "nlohmann/json.hpp"


class Financials {
    private:
     Balancesheet balance_sheet;
     Incomestatement income_statement;
     Cashflowstatement cash_flows_statement;
     Comprehensiveincome comprehensive_income;
     
    public:
     Balancesheet get_balance_sheet();
     Incomestatement get_income_statement();
     Cashflowstatement get_cash_flows_statement();
     Comprehensiveincome get_comprehensive_income();
     
     friend void from_json(const nlohmann::json &j, Financials &f);
    
};


#endif