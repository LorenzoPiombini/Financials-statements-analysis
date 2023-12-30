#include "Incomestatement.h"

#include <iostream>

Income_tax_expense_benefit Incomestatement::get_income_tax_expense_benefit() { return income_tax_expense_benefit; }
Participating_securities_distributed_and_undistributed_earnings_loss_basic
Incomestatement::get_participating_securities_distributed_and_undistributed_earnings_loss_basic()
{
    return participating_securities_distributed_and_undistributed_earnings_loss_basic;
}
Cost_of_revenue Incomestatement::get_cost_of_revenue() { return cost_of_revenue; }
Preferred_stock_dividends_and_other_adjustments Incomestatement::get_preferred_stock_dividends_and_other_adjustments()
{
    return preferred_stock_dividends_and_other_adjustments;
}
Research_and_development Incomestatement::get_research_and_development() { return research_and_development; }
Diluted_earnings_per_share Incomestatement::get_diluted_earnings_per_share() { return diluted_earnings_per_share; }
Operating_income_loss Incomestatement::get_operating_income_loss() { return operating_income_loss; }
Gross_profit Incomestatement::get_gross_profit() { return gross_profit; }
Operating_expenses Incomestatement::get_operating_expenses() { return operating_expenses; }
Diluted_average_shares Incomestatement::get_diluted_average_shares() { return diluted_average_shares; }
Net_income_loss_attributable_to_parent Incomestatement::get_net_income_loss_attributable_to_parent()
{
    return net_income_loss_attributable_to_parent;
}
Selling_general_and_administrative_expenses Incomestatement::get_selling_general_and_administrative_expenses()
{
    return selling_general_and_administrative_expenses;
}
Revenues Incomestatement::get_revenues() { return revenues; }
Interest_expense_operating Incomestatement::get_interest_expense_operating() { return interest_expense_operating; }
Net_income_loss_attributable_to_noncontrolling_interest
Incomestatement::get_net_income_loss_attributable_to_noncontrolling_interest()
{
    return net_income_loss_attributable_to_noncontrolling_interest;
}
Benefits_costs_expenses Incomestatement::get_benefits_costs_expenses() { return benefits_costs_expenses; }
Net_income_loss_available_to_common_stockholders_basic
Incomestatement::get_net_income_loss_available_to_common_stockholders_basic()
{
    return net_income_loss_available_to_common_stockholders_basic;
}
Costs_and_expenses Incomestatement::get_costs_and_expenses() { return costs_and_expenses; }
Net_income_loss Incomestatement::get_net_income_loss() { return net_income_loss; }
Basic_average_shares Incomestatement::get_basic_average_shares() { return basic_average_shares; }
Income_loss_from_continuing_operations_before_tax
Incomestatement::get_income_loss_from_continuing_operations_before_tax()
{
    return income_loss_from_continuing_operations_before_tax;
}
Basic_earnings_per_share Incomestatement::get_basic_earnings_per_share() { return basic_earnings_per_share; }
Income_loss_from_continuing_operations_after_tax Incomestatement::get_income_loss_from_continuing_operations_after_tax()
{
    return income_loss_from_continuing_operations_after_tax;
}
Nonoperating_income_loss Incomestatement::get_nonoperating_income_loss() { return nonoperating_income_loss; }

void from_json(const nlohmann::json& j, Incomestatement& i)
{
    if(j.contains("income_tax_expense_benefit") && !j["income_tax_expense_benefit"].empty()) {
        j.at("income_tax_expense_benefit").get_to(i.income_tax_expense_benefit);
    } else {
        i.income_tax_expense_benefit = Income_tax_expense_benefit();
    }

    if(j.contains("participating_securities_distributed_and_undistributed_earnings_loss_basic") && !j["participating_securities_distributed_and_undistributed_earnings_loss_basic"].empty()) {
        j.at("participating_securities_distributed_and_undistributed_earnings_loss_basic").get_to(i.participating_securities_distributed_and_undistributed_earnings_loss_basic);
    } else {
        i.participating_securities_distributed_and_undistributed_earnings_loss_basic = Participating_securities_distributed_and_undistributed_earnings_loss_basic();
    }

    if(j.contains("cost_of_revenue") && !j["cost_of_revenue"].empty()) {
        j.at("cost_of_revenue").get_to(i.cost_of_revenue);
    } else {
        i.cost_of_revenue = Cost_of_revenue();
    }

    if(j.contains("preferred_stock_dividends_and_other_adjustments") && !j["preferred_stock_dividends_and_other_adjustments"].empty()) {
        j.at("preferred_stock_dividends_and_other_adjustments").get_to(i.preferred_stock_dividends_and_other_adjustments);
    } else {
        i.preferred_stock_dividends_and_other_adjustments = Preferred_stock_dividends_and_other_adjustments();
    }

    if(j.contains("research_and_development") && !j["research_and_development"].empty()) {
        j.at("research_and_development").get_to(i.research_and_development);
    } else {
        i.research_and_development = Research_and_development();
    }

    if(j.contains("diluted_earnings_per_share") && !j["diluted_earnings_per_share"].empty()) {
        j.at("diluted_earnings_per_share").get_to(i.diluted_earnings_per_share);
    } else {
        i.diluted_earnings_per_share = Diluted_earnings_per_share();
    }

    if(j.contains("operating_income_loss") && !j["operating_income_loss"].empty()) {
        j.at("operating_income_loss").get_to(i.operating_income_loss);
    } else {
        i.operating_income_loss = Operating_income_loss();
    }

    if(j.contains("gross_profit") && !j["gross_profit"].is_null()) {
        j.at("gross_profit").get_to(i.gross_profit);
    } else {
        i.gross_profit = Gross_profit();
    }

    if(j.contains("operating_expenses") && !j["operating_expenses"].empty()) {
        j.at("operating_expenses").get_to(i.operating_expenses);
    } else {
        i.operating_expenses = Operating_expenses();
    }

    if(j.contains("diluted_average_shares") && !j["diluted_average_shares"].empty()) {
        j.at("diluted_average_shares").get_to(i.diluted_average_shares);
    } else {
        i.diluted_average_shares = Diluted_average_shares();
    }

    if(j.contains("net_income_loss_attributable_to_parent") && !j["net_income_loss_attributable_to_parent"].empty()) {
        j.at("net_income_loss_attributable_to_parent").get_to(i.net_income_loss_attributable_to_parent);
    } else {
        i.net_income_loss_attributable_to_parent = Net_income_loss_attributable_to_parent();
    }

    if(j.contains("selling_general_and_administrative_expenses") && !j["selling_general_and_administrative_expenses"].empty()) {
        j.at("selling_general_and_administrative_expenses").get_to(i.selling_general_and_administrative_expenses);
    } else {
        i.selling_general_and_administrative_expenses = Selling_general_and_administrative_expenses();
    }

    if(j.contains("revenues") && !j["revenues"].empty()) {
        j.at("revenues").get_to(i.revenues);
    } else {
        i.revenues = Revenues();
    }

    if(j.contains("interest_expense_operating") && !j["interest_expense_operating"].empty()) {
        j.at("interest_expense_operating").get_to(i.interest_expense_operating);
    } else {
        i.interest_expense_operating = Interest_expense_operating();
    }

    if(j.contains("net_income_loss_attributable_to_noncontrolling_interest") && !j["net_income_loss_attributable_to_noncontrolling_interest"].empty()) {
        j.at("net_income_loss_attributable_to_noncontrolling_interest").get_to(i.net_income_loss_attributable_to_noncontrolling_interest);
    } else {
        i.net_income_loss_attributable_to_noncontrolling_interest = Net_income_loss_attributable_to_noncontrolling_interest();
    }
    
    if(j.contains("benefits_costs_expenses") && !j["benefits_costs_expenses"].empty()) {
        j.at("benefits_costs_expenses").get_to(i.benefits_costs_expenses);
    } else {
        i.benefits_costs_expenses = Benefits_costs_expenses();
    }

    if(j.contains("net_income_loss_available_to_common_stockholders_basic") && !j["net_income_loss_available_to_common_stockholders_basic"].empty()) {
        j.at("net_income_loss_available_to_common_stockholders_basic").get_to(i.net_income_loss_available_to_common_stockholders_basic);
    } else {
        i.net_income_loss_available_to_common_stockholders_basic = Net_income_loss_available_to_common_stockholders_basic();
    }
    
    if(j.contains("costs_and_expenses") && !j["costs_and_expenses"].empty()) {
        j.at("costs_and_expenses").get_to(i.costs_and_expenses);
    } else {
        i.costs_and_expenses = Costs_and_expenses();
    }

    if(j.contains("net_income_loss") && !j["net_income_loss"].empty()) {
        j.at("net_income_loss").get_to(i.net_income_loss);
    } else {
        i.net_income_loss = Net_income_loss();
    }
    
    if(j.contains("basic_average_shares") && !j["basic_average_shares"].empty()) {
        j.at("basic_average_shares").get_to(i.basic_average_shares);
    } else {
        i.basic_average_shares = Basic_average_shares();
    }

    if(j.contains("income_loss_from_continuing_operations_before_tax") && !j["income_loss_from_continuing_operations_before_tax"].empty()) {
        j.at("income_loss_from_continuing_operations_before_tax").get_to(i.income_loss_from_continuing_operations_before_tax);
    } else {
        i.income_loss_from_continuing_operations_before_tax = Income_loss_from_continuing_operations_before_tax();
    }
    
    if(j.contains("basic_earnings_per_share") && !j["basic_earnings_per_share"].empty()) {
        j.at("basic_earnings_per_share").get_to(i.basic_earnings_per_share);
    } else {
        i.basic_earnings_per_share = Basic_earnings_per_share();
    }

    if(j.contains("income_loss_from_continuing_operations_after_tax") && !j["income_loss_from_continuing_operations_after_tax"].empty()) {
        j.at("income_loss_from_continuing_operations_after_tax").get_to(i.income_loss_from_continuing_operations_after_tax);
    } else {
        i.income_loss_from_continuing_operations_after_tax = Income_loss_from_continuing_operations_after_tax();
    }
    
    if(j.contains("nonoperating_income_loss") && !j["nonoperating_income_loss"].empty()) {
        j.at("nonoperating_income_loss").get_to(i.nonoperating_income_loss);
    } else {
        i.nonoperating_income_loss = Nonoperating_income_loss();
    }

    
}