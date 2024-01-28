#ifndef _INCOMESTATEMENT_H_
#define _INCOMESTATEMENT_H_


#include <string>
#include <fstream>

class Income_statement{
 
  private:
         std::string date;
		 std::string symbol;
		 std::string reportedCurrency;
		 std::string cik;
		 std::string fillingDate;
		 std::string acceptedDate;
		 std::string calendarYear;
		 std::string period;
		 long long revenue; 
		 long long costOfRevenue;
		 long long grossProfit;
		 double grossProfitRatio;
		 long long researchAndDevelopmentExpenses;
		 long long generalAndAdministrativeExpenses;
		 long long sellingAndMarketingExpenses;
		 long long sellingGeneralAndAdministrativeExpenses;
		 long long otherExpenses;
		 long long operatingExpenses;
		 long long costAndExpenses;
		 long long interestIncome;
		 long long interestExpense;
		 long long depreciationAndAmortization;
		 long long ebitda;
		 double ebitdaratio;
		 long long operatingIncome;
         double operatingIncomeRatio;
		 long long totalOtherIncomeExpensesNet;
		 long long incomeBeforeTax;
		 double incomeBeforeTaxRatio;
		 long long incomeTaxExpense;
		 long long netIncome;
		 long long netIncomeRatio;
		 double  eps;
		 double epsdiluted;
		 long long weightedAverageShsOut;
		 long long  weightedAverageShsOutDil;
		 std::string link;
		 std::string finalLink;
     
    public:
         std::string get_date() const;
		 std::string get_symbol()const;
		 std::string get_reported_currency()const;
		 std::string get_cik()const;
		 std::string get_filling_date()const;
		 std::string get_accepted_date()const;
		 std::string get_calendar_year()const;
		 std::string get_period()const;
		 long long get_revenue()const; 
		 long long get_cost_of_revenue()const;
		 long long get_gross_profit()const;
		 double get_gross_profit_ratio()const;
		 long long get_research_and_development_expenses()const;
		 long long get_general_and_administrative_expenses()const;
		 long long get_selling_and_marketing_expenses()const;
		 long long get_selling_general_and_administrative_expenses()const;
		 long long get_other_expenses()const;
		 long long get_operating_expenses()const;
		 long long get_cost_and_expenses()const;
		 long long get_interest_income()const;
		 long long get_interest_expense()const;
		 long long get_depreciation_and_amortization()const;
		 long long get_ebitda()const;
		 double get_ebitda_ratio()const;
		 long long get_operating_income()const;
         double get_operating_income_ratio()const;
		 long long get_total_other_income_expensesNet()const;
		 long long get_income_before_tax()const;
		 double get_income_before_tax_ratio()const;
		 long long get_income_tax_expense()const;
		 long long get_net_income()const;
		 long long get_net_income_ratio()const;
		 double  get_eps()const;
		 double get_eps_diluted()const;
		 long long get_weighted_average_shs_out()const;
		 long long  get_weighted_average_dhs_out_dil()const;
		 std::string get_link()const;
		 std::string get_finalLink()const;
         std::string get_class_name()const;
         std::string create_file_name(std::string ticker)const;
         void save_to_file(std::ofstream &out);
         bool read_from_file(std::ifstream &in, std::vector<Income_statement*> &statements );
         size_t compute_object_size() const;
         void deserialize(std::string &json_string);
         
         
     
     //friend void from_json(const nlohmann::json &j, Income_statement &i);

};


#endif