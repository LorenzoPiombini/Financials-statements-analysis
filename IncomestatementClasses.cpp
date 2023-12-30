#include "IncomestatementClasses.h"
 
    void from_json(const nlohmann::json &j, Income_tax_expense_benefit &income_tax_expense_benefit){
         j.at("value").get_to(income_tax_expense_benefit.value);
         j.at("unit").get_to(income_tax_expense_benefit.unit);
         j.at("label").get_to(income_tax_expense_benefit.label);
         j.at("order").get_to(income_tax_expense_benefit.order);           
    }
    void from_json(const nlohmann::json &j, Participating_securities_distributed_and_undistributed_earnings_loss_basic &participating_securities_distributed_and_undistributed_earnings_loss_basic){
         j.at("value").get_to(participating_securities_distributed_and_undistributed_earnings_loss_basic.value);
         j.at("unit").get_to(participating_securities_distributed_and_undistributed_earnings_loss_basic.unit);
         j.at("label").get_to(participating_securities_distributed_and_undistributed_earnings_loss_basic.label);
         j.at("order").get_to(participating_securities_distributed_and_undistributed_earnings_loss_basic.order); 
    }
    void from_json(const nlohmann::json &j, Cost_of_revenue &cost_of_revenue){
         j.at("value").get_to(cost_of_revenue.value);
         j.at("unit").get_to(cost_of_revenue.unit);
         j.at("label").get_to(cost_of_revenue.label);
         j.at("order").get_to(cost_of_revenue.order); 
    }
    void from_json(const nlohmann::json &j, Preferred_stock_dividends_and_other_adjustments &preferred_stock_dividends_and_other_adjustments){
         j.at("value").get_to(preferred_stock_dividends_and_other_adjustments.value);
         j.at("unit").get_to(preferred_stock_dividends_and_other_adjustments.unit);
         j.at("label").get_to(preferred_stock_dividends_and_other_adjustments.label);
         j.at("order").get_to(preferred_stock_dividends_and_other_adjustments.order); 
    }
    void from_json(const nlohmann::json &j, Research_and_development &research_and_development){
         j.at("value").get_to(research_and_development.value);
         j.at("unit").get_to(research_and_development.unit);
         j.at("label").get_to(research_and_development.label);
         j.at("order").get_to(research_and_development.order); 
    }
    void from_json(const nlohmann::json &j, Diluted_earnings_per_share &diluted_earnings_per_share){
         j.at("value").get_to(diluted_earnings_per_share.value);
         j.at("unit").get_to(diluted_earnings_per_share.unit);
         j.at("label").get_to(diluted_earnings_per_share.label);
         j.at("order").get_to(diluted_earnings_per_share.order); 
    }
    void from_json(const nlohmann::json &j, Operating_income_loss &operating_income_loss){
         j.at("value").get_to(operating_income_loss.value);
         j.at("unit").get_to(operating_income_loss.unit);
         j.at("label").get_to(operating_income_loss.label);
         j.at("order").get_to(operating_income_loss.order); 
    }
    void from_json(const nlohmann::json &j, Gross_profit &gross_profit){
         j.at("value").get_to(gross_profit.value);
         j.at("unit").get_to(gross_profit.unit);
         j.at("label").get_to(gross_profit.label);
         j.at("order").get_to(gross_profit.order); 
    }
    void from_json(const nlohmann::json &j, Operating_expenses &operating_expenses){
         j.at("value").get_to(operating_expenses.value);
         j.at("unit").get_to(operating_expenses.unit);
         j.at("label").get_to(operating_expenses.label);
         j.at("order").get_to(operating_expenses.order); 
    }
    void from_json(const nlohmann::json &j, Diluted_average_shares &diluted_average_shares){
         j.at("value").get_to(diluted_average_shares.value);
         j.at("unit").get_to(diluted_average_shares.unit);
         j.at("label").get_to(diluted_average_shares.label);
         j.at("order").get_to(diluted_average_shares.order); 
    }
    void from_json(const nlohmann::json &j, Net_income_loss_attributable_to_parent &net_income_loss_attributable_to_parent){
        j.at("value").get_to(net_income_loss_attributable_to_parent.value);
         j.at("unit").get_to(net_income_loss_attributable_to_parent.unit);
         j.at("label").get_to(net_income_loss_attributable_to_parent.label);
         j.at("order").get_to(net_income_loss_attributable_to_parent.order); 
    }
    void from_json(const nlohmann::json &j, Selling_general_and_administrative_expenses &selling_general_and_administrative_expenses){
        j.at("value").get_to(selling_general_and_administrative_expenses.value);
         j.at("unit").get_to(selling_general_and_administrative_expenses.unit);
         j.at("label").get_to(selling_general_and_administrative_expenses.label);
         j.at("order").get_to(selling_general_and_administrative_expenses.order); 
    }
    void from_json(const nlohmann::json &j, Revenues &revenues){
        j.at("value").get_to(revenues.value);
         j.at("unit").get_to(revenues.unit);
         j.at("label").get_to(revenues.label);
         j.at("order").get_to(revenues.order); 
    }
    void from_json(const nlohmann::json &j, Interest_expense_operating &interest_expense_operating){
        j.at("value").get_to(interest_expense_operating.value);
         j.at("unit").get_to(interest_expense_operating.unit);
         j.at("label").get_to(interest_expense_operating.label);
         j.at("order").get_to(interest_expense_operating.order); 
    }
    void from_json(const nlohmann::json &j, Net_income_loss_attributable_to_noncontrolling_interest  &net_income_loss_attributable_to_noncontrolling_interest ){
        j.at("value").get_to(net_income_loss_attributable_to_noncontrolling_interest.value);
         j.at("unit").get_to(net_income_loss_attributable_to_noncontrolling_interest.unit);
         j.at("label").get_to(net_income_loss_attributable_to_noncontrolling_interest.label);
         j.at("order").get_to(net_income_loss_attributable_to_noncontrolling_interest.order); 
    }
    void from_json(const nlohmann::json &j, Benefits_costs_expenses &benefits_costs_expenses){
        j.at("value").get_to(benefits_costs_expenses.value);
         j.at("unit").get_to(benefits_costs_expenses.unit);
         j.at("label").get_to(benefits_costs_expenses.label);
         j.at("order").get_to(benefits_costs_expenses.order); 
    }
    void from_json(const nlohmann::json &j, Net_income_loss_available_to_common_stockholders_basic &net_income_loss_available_to_common_stockholders_basic){
        j.at("value").get_to(net_income_loss_available_to_common_stockholders_basic.value);
         j.at("unit").get_to(net_income_loss_available_to_common_stockholders_basic.unit);
         j.at("label").get_to(net_income_loss_available_to_common_stockholders_basic.label);
         j.at("order").get_to(net_income_loss_available_to_common_stockholders_basic.order); 
    }
    void from_json(const nlohmann::json &j, Costs_and_expenses &costs_and_expenses){
        j.at("value").get_to(costs_and_expenses.value);
         j.at("unit").get_to(costs_and_expenses.unit);
         j.at("label").get_to(costs_and_expenses.label);
         j.at("order").get_to(costs_and_expenses.order); 
    }
    void from_json(const nlohmann::json &j, Net_income_loss &net_income_loss){
        j.at("value").get_to(net_income_loss.value);
         j.at("unit").get_to(net_income_loss.unit);
         j.at("label").get_to(net_income_loss.label);
         j.at("order").get_to(net_income_loss.order); 
    }
    void from_json(const nlohmann::json &j, Basic_average_shares &basic_average_shares){
         j.at("value").get_to(basic_average_shares.value);
         j.at("unit").get_to(basic_average_shares.unit);
         j.at("label").get_to(basic_average_shares.label);
         j.at("order").get_to(basic_average_shares.order); 
    }
    void from_json(const nlohmann::json &j, Income_loss_from_continuing_operations_before_tax &income_loss_from_continuing_operations_before_tax){
         j.at("value").get_to(income_loss_from_continuing_operations_before_tax.value);
         j.at("unit").get_to(income_loss_from_continuing_operations_before_tax.unit);
         j.at("label").get_to(income_loss_from_continuing_operations_before_tax.label);
         j.at("order").get_to(income_loss_from_continuing_operations_before_tax.order); 
    }
    void from_json(const nlohmann::json &j, Basic_earnings_per_share &basic_earnings_per_share){
         j.at("value").get_to(basic_earnings_per_share.value);
         j.at("unit").get_to(basic_earnings_per_share.unit);
         j.at("label").get_to(basic_earnings_per_share.label);
         j.at("order").get_to(basic_earnings_per_share.order); 
    }
    void from_json(const nlohmann::json &j, Income_loss_from_continuing_operations_after_tax &income_loss_from_continuing_operations_after_tax){
         j.at("value").get_to(income_loss_from_continuing_operations_after_tax.value);
         j.at("unit").get_to(income_loss_from_continuing_operations_after_tax.unit);
         j.at("label").get_to(income_loss_from_continuing_operations_after_tax.label);
         j.at("order").get_to(income_loss_from_continuing_operations_after_tax.order); 
    }
    void from_json(const nlohmann::json &j, Nonoperating_income_loss &nonoperating_income_loss){
         j.at("value").get_to(nonoperating_income_loss.value);
         j.at("unit").get_to(nonoperating_income_loss.unit);
         j.at("label").get_to(nonoperating_income_loss.label);
         j.at("order").get_to(nonoperating_income_loss.order); 
    }