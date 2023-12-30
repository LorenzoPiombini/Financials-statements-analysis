#ifndef _INCOMESTATEMENT_H_
#define _INCOMESTATEMENT_H_


#include "IncomestatementClasses.h"
#include "nlohmann/json.hpp"


class Incomestatement {
    private:
               Income_tax_expense_benefit income_tax_expense_benefit;
               Participating_securities_distributed_and_undistributed_earnings_loss_basic participating_securities_distributed_and_undistributed_earnings_loss_basic;
               Cost_of_revenue cost_of_revenue;
               Preferred_stock_dividends_and_other_adjustments preferred_stock_dividends_and_other_adjustments;
               Research_and_development research_and_development;
               Diluted_earnings_per_share diluted_earnings_per_share;
               Operating_income_loss operating_income_loss;
               Gross_profit gross_profit;
               Operating_expenses operating_expenses;
               Diluted_average_shares diluted_average_shares;
               Net_income_loss_attributable_to_parent net_income_loss_attributable_to_parent;
               Selling_general_and_administrative_expenses selling_general_and_administrative_expenses;
               Revenues revenues;
               Interest_expense_operating interest_expense_operating;
               Net_income_loss_attributable_to_noncontrolling_interest net_income_loss_attributable_to_noncontrolling_interest;
               Benefits_costs_expenses benefits_costs_expenses;
               Net_income_loss_available_to_common_stockholders_basic net_income_loss_available_to_common_stockholders_basic;
               Costs_and_expenses costs_and_expenses;
               Net_income_loss net_income_loss;
               Basic_average_shares basic_average_shares;
               Income_loss_from_continuing_operations_before_tax income_loss_from_continuing_operations_before_tax;
               Basic_earnings_per_share basic_earnings_per_share;
               Income_loss_from_continuing_operations_after_tax income_loss_from_continuing_operations_after_tax;
               Nonoperating_income_loss nonoperating_income_loss;

    public:
               Income_tax_expense_benefit get_income_tax_expense_benefit();
               Participating_securities_distributed_and_undistributed_earnings_loss_basic get_participating_securities_distributed_and_undistributed_earnings_loss_basic();
               Cost_of_revenue get_cost_of_revenue();
               Preferred_stock_dividends_and_other_adjustments get_preferred_stock_dividends_and_other_adjustments();
               Research_and_development get_research_and_development();
               Diluted_earnings_per_share get_diluted_earnings_per_share();
               Operating_income_loss get_operating_income_loss();
               Gross_profit get_gross_profit();
               Operating_expenses get_operating_expenses();
               Diluted_average_shares get_diluted_average_shares();
               Net_income_loss_attributable_to_parent get_net_income_loss_attributable_to_parent();
               Selling_general_and_administrative_expenses get_selling_general_and_administrative_expenses();
               Revenues get_revenues();
               Interest_expense_operating get_interest_expense_operating();
               Net_income_loss_attributable_to_noncontrolling_interest get_net_income_loss_attributable_to_noncontrolling_interest();
               Benefits_costs_expenses get_benefits_costs_expenses();
               Net_income_loss_available_to_common_stockholders_basic get_net_income_loss_available_to_common_stockholders_basic();
               Costs_and_expenses get_costs_and_expenses();
               Net_income_loss get_net_income_loss();
               Basic_average_shares get_basic_average_shares();
               Income_loss_from_continuing_operations_before_tax get_income_loss_from_continuing_operations_before_tax();
               Basic_earnings_per_share get_basic_earnings_per_share();
               Income_loss_from_continuing_operations_after_tax get_income_loss_from_continuing_operations_after_tax();
               Nonoperating_income_loss get_nonoperating_income_loss();
             
               friend void from_json(const nlohmann::json &j, Incomestatement &i);
};


#endif