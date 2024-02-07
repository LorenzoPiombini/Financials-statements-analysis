#ifndef _CASHFLOWSTATEMENT_H_
#define _CASHFLOWSTATEMENT_H_


#include <fstream>
#include <string>
#include <vector>

class Cashflowstatement{
    
    private:
        std::string date;
        std::string symbol;
        std::string reportedCurrency; 
        std::string cik; 
		std::string fillingDate;
		std::string acceptedDate;
		std::string calendarYear;
		std::string period;
        long long netIncome;
		long long depreciationAndAmortization;
		long long deferredIncomeTax;
		long long stockBasedCompensation;
		long long changeInWorkingCapital;
		long long accountsReceivables;
		long long inventory;
		long long accountsPayables;
		long long otherWorkingCapital;
		long long otherNonCashItems;
		long long netCashProvidedByOperatingActivities;
		long long investmentsInPropertyPlantAndEquipment;
		long long acquisitionsNet;
		long long purchasesOfInvestments;
		long long salesMaturitiesOfInvestments;
		long long otherInvestingActivites;
		long long netCashUsedForInvestingActivites;
		long long debtRepayment;
		long long commonStockIssued;
		long long commonStockRepurchased;
		long long dividendsPaid;
		long long otherFinancingActivites;
		long long netCashUsedProvidedByFinancingActivities;
		long long effectOfForexChangesOnCash;
		long long netChangeInCash;
		long long cashAtEndOfPeriod;
		long long cashAtBeginningOfPeriod;
		long long operatingCashFlow;
		long long capitalExpenditure;
		long long freeCashFlow;
		std::string link;
		std::string finalLink;
 
    public:
        std::string get_date() const;
        std::string get_symbol() const;
        std::string get_reported_currency() const;
        std::string get_cik() const;
        std::string get_filling_date() const;
        std::string get_accepted_date() const;
        std::string get_calendar_year() const;
        std::string get_period() const;
        long long get_net_income() const;
        long long get_depreciation_and_amortization() const;
        long long get_deferred_income_tax() const;
        long long get_stock_based_compensation() const;
        long long get_change_in_working_capital() const;
        long long get_accounts_receivables() const;
        long long get_inventory() const;
        long long get_accounts_payables() const;
        long long get_other_working_capital() const;
        long long get_other_non_cash_items() const;
        long long get_net_cash_provided_by_operating_activities() const;
        long long get_investments_in_property_plant_and_equipment() const;
        long long get_acquisitions_net() const;
        long long get_purchases_of_investments() const;
        long long get_sales_maturities_of_investments() const;
        long long get_other_investing_activites() const;
        long long get_net_cash_used_for_investing_activites() const;
        long long get_debt_repayment() const;
        long long get_common_stock_issued() const;
        long long get_common_stock_repurchased() const;
        long long get_dividends_paid() const;
        long long get_other_financing_activites() const;
        long long get_net_cash_used_provided_by_financing_activities() const;
        long long get_effect_of_forex_changes_on_cash() const;
        long long get_net_change_in_cash() const;
        long long get_cash_at_end_of_period() const;
        long long get_cash_at_beginning_of_period() const;
        long long get_operating_cash_flow() const;
        long long get_capital_expenditure() const;
        long long get_free_cash_flow() const;
        std::string get_link() const;
        std::string get_final_link() const;
        std::string get_class_name() const;     
        std::string create_file_name(std::string ticker)const;
        void save_to_file(std::ofstream &out);
        bool read_from_file(std::ifstream &in, std::vector<Cashflowstatement*> &statements);
        size_t compute_object_size() const;
        void deserialize(std::string &json_string);
        

       // friend void from_json(const nlohmann::json &j, Cashflowstatement &c);
};


#endif
