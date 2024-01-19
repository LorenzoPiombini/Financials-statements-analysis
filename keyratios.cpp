#include "Keyratios.h"
#include "nlohmann/json.hpp"


// Implementations of getters for std::string members
std::string Key_ratios::get_symbol() const { return symbol; }
std::string Key_ratios::get_date() const { return date; }
std::string Key_ratios::get_calendar_year() const { return calendarYear; }
std::string Key_ratios::get_period() const { return period; }

// Implementations of getters for double members
double Key_ratios::get_revenue_per_share() const { return revenuePerShare; }
double Key_ratios::get_net_income_per_share() const { return netIncomePerShare; }
double Key_ratios::get_operating_cash_flow_per_share() const { return operatingCashFlowPerShare; }
double Key_ratios::get_free_cash_flow_per_share() const { return freeCashFlowPerShare; }
double Key_ratios::get_cash_per_share() const { return cashPerShare; }
double Key_ratios::get_book_value_per_share() const { return bookValuePerShare; }
double Key_ratios::get_tangible_book_value_per_share() const { return tangibleBookValuePerShare; }
double Key_ratios::get_shareholders_equity_per_share() const { return shareholdersEquityPerShare; }
double Key_ratios::get_interest_debt_per_share() const { return interestDebtPerShare; }
double Key_ratios::get_market_cap() const { return marketCap; }
double Key_ratios::get_enterprise_value() const { return enterpriseValue; }
double Key_ratios::get_pe_ratio() const { return peRatio; }
double Key_ratios::get_price_to_sales_ratio() const { return priceToSalesRatio; }
double Key_ratios::get_pocf_ratio() const { return pocfratio; }
double Key_ratios::get_pfcf_ratio() const { return pfcfRatio; }
double Key_ratios::get_pb_ratio() const { return pbRatio; }
double Key_ratios::get_ptb_ratio() const { return ptbRatio; }
double Key_ratios::get_ev_to_sales() const { return evToSales; }
double Key_ratios::get_enterprise_value_over_EBITDA() const { return enterpriseValueOverEBITDA; }
double Key_ratios::get_ev_to_operating_cash_flow() const { return evToOperatingCashFlow; }
double Key_ratios::get_ev_to_free_cash_flow() const { return evToFreeCashFlow; }
double Key_ratios::get_earnings_yield() const { return earningsYield; }
double Key_ratios::get_free_cash_flow_yield() const { return freeCashFlowYield; }
double Key_ratios::get_debt_to_equity() const { return debtToEquity; }
double Key_ratios::get_debt_to_assets() const { return debtToAssets; }
double Key_ratios::get_net_debt_to_EBITDA() const { return netDebtToEBITDA; }
double Key_ratios::get_current_ratio() const { return currentRatio; }
double Key_ratios::get_interest_coverage() const { return interestCoverage; }
double Key_ratios::get_income_quality() const { return incomeQuality; }
double Key_ratios::get_dividend_yield() const { return dividendYield; }
double Key_ratios::get_payout_ratio() const { return payoutRatio; }
double Key_ratios::get_sga_to_revenue() const { return salesGeneralAndAdministrativeToRevenue; }
double Key_ratios::get_rnd_to_revenue() const { return researchAndDdevelopementToRevenue; }
double Key_ratios::get_intangibles_to_total_assets() const { return intangiblesToTotalAssets; }
double Key_ratios::get_capex_to_operating_cash_flow() const { return capexToOperatingCashFlow; }
double Key_ratios::get_capex_to_revenue() const { return capexToRevenue; }
double Key_ratios::get_capex_to_depreciation() const { return capexToDepreciation; }
double Key_ratios::get_stock_based_compensation_to_revenue() const { return stockBasedCompensationToRevenue; }
double Key_ratios::get_graham_number() const { return grahamNumber; }
double Key_ratios::get_roic() const { return roic; }
double Key_ratios::get_return_on_tangible_assets() const { return returnOnTangibleAssets; }
double Key_ratios::get_graham_net_net() const { return grahamNetNet; }
double Key_ratios::get_working_capital() const { return workingCapital; }
double Key_ratios::get_tangible_asset_value() const { return tangibleAssetValue; }
double Key_ratios::get_net_current_asset_value() const { return netCurrentAssetValue; }
double Key_ratios::get_invested_capital() const { return investedCapital; }
double Key_ratios::get_average_receivables() const { return averageReceivables; }
double Key_ratios::get_average_payables() const { return averagePayables; }
double Key_ratios::get_average_inventory() const { return averageInventory; }
double Key_ratios::get_days_sales_outstanding() const { return daysSalesOutstanding; }
double Key_ratios::get_days_payables_outstanding() const { return daysPayablesOutstanding; }
double Key_ratios::get_days_of_inventory_on_hand() const { return daysOfInventoryOnHand; }
double Key_ratios::get_receivables_turnover() const { return receivablesTurnover; }
double Key_ratios::get_payables_turnover() const { return payablesTurnover; }
double Key_ratios::get_inventory_turnover() const { return inventoryTurnover; }
double Key_ratios::get_roe() const { return roe; }
double Key_ratios::get_capex_per_share() const { return capexPerShare; }


std::string Key_ratios::get_class_name() const {
   return  "key_ratios";   
}
// from_json implementation

void from_json(const nlohmann::json &j, Key_ratios& k) {
    // Parsing std::string members with check
    k.symbol = j.contains("symbol") && !j["symbol"].empty() ? j["symbol"].get<std::string>() : "none";
    k.date = j.contains("date") && !j["date"].empty() ? j["date"].get<std::string>() : "none";
    k.calendarYear = j.contains("calendarYear") && !j["calendarYear"].empty() ? j["calendarYear"].get<std::string>() : "none";
    k.period = j.contains("period") && !j["period"].empty() ? j["period"].get<std::string>() : "none";

    // Parsing double members with check
    k.revenuePerShare = j.contains("revenuePerShare") ? j["revenuePerShare"].get<double>() : 0.0;
    k.netIncomePerShare = j.contains("netIncomePerShare") ? j["netIncomePerShare"].get<double>() : 0.0;
    k.operatingCashFlowPerShare = j.contains("operatingCashFlowPerShare") ? j["operatingCashFlowPerShare"].get<double>() : 0.0;
    k.freeCashFlowPerShare = j.contains("freeCashFlowPerShare") ? j["freeCashFlowPerShare"].get<double>() : 0.0;
    k.cashPerShare = j.contains("cashPerShare") ? j["cashPerShare"].get<double>() : 0.0;
    k.bookValuePerShare = j.contains("bookValuePerShare") ? j["bookValuePerShare"].get<double>() : 0.0;
    k.tangibleBookValuePerShare = j.contains("tangibleBookValuePerShare") ? j["tangibleBookValuePerShare"].get<double>() : 0.0;
    k.shareholdersEquityPerShare = j.contains("shareholdersEquityPerShare") ? j["shareholdersEquityPerShare"].get<double>() : 0.0;
    k.interestDebtPerShare = j.contains("interestDebtPerShare") ? j["interestDebtPerShare"].get<double>() : 0.0;
    k.marketCap = j.contains("marketCap") ? j["marketCap"].get<double>() : 0.0;
    k.enterpriseValue = j.contains("enterpriseValue") ? j["enterpriseValue"].get<double>() : 0.0;
    k.peRatio = j.contains("peRatio") ? j["peRatio"].get<double>() : 0.0;
    k.priceToSalesRatio = j.contains("priceToSalesRatio") ? j["priceToSalesRatio"].get<double>() : 0.0;
    k.pocfratio = j.contains("pocfratio") ? j["pocfratio"].get<double>() : 0.0;
    k.pfcfRatio = j.contains("pfcfRatio") ? j["pfcfRatio"].get<double>() : 0.0;
    k.pbRatio = j.contains("pbRatio") ? j["pbRatio"].get<double>() : 0.0;
    k.ptbRatio = j.contains("ptbRatio") ? j["ptbRatio"].get<double>() : 0.0;
    k.evToSales = j.contains("evToSales") ? j["evToSales"].get<double>() : 0.0;
    k.enterpriseValueOverEBITDA = j.contains("enterpriseValueOverEBITDA") ? j["enterpriseValueOverEBITDA"].get<double>() : 0.0;
    k.evToOperatingCashFlow = j.contains("evToOperatingCashFlow") ? j["evToOperatingCashFlow"].get<double>() : 0.0;
    k.evToFreeCashFlow = j.contains("evToFreeCashFlow") ? j["evToFreeCashFlow"].get<double>() : 0.0;
    k.earningsYield = j.contains("earningsYield") ? j["earningsYield"].get<double>() : 0.0;
    k.freeCashFlowYield = j.contains("freeCashFlowYield") ? j["freeCashFlowYield"].get<double>() : 0.0;
    k.debtToEquity = j.contains("debtToEquity") ? j["debtToEquity"].get<double>() : 0.0;
    k.debtToAssets = j.contains("debtToAssets") ? j["debtToAssets"].get<double>() : 0.0;
    k.netDebtToEBITDA = j.contains("netDebtToEBITDA") ? j["netDebtToEBITDA"].get<double>() : 0.0;
    k.currentRatio = j.contains("currentRatio") ? j["currentRatio"].get<double>() : 0.0;
    k.interestCoverage = j.contains("interestCoverage") ? j["interestCoverage"].get<double>() : 0.0;
    k.incomeQuality = j.contains("incomeQuality") ? j["incomeQuality"].get<double>() : 0.0;
    k.dividendYield = j.contains("dividendYield") ? j["dividendYield"].get<double>() : 0.0;
    k.payoutRatio = j.contains("payoutRatio") ? j["payoutRatio"].get<double>() : 0.0;
    k.salesGeneralAndAdministrativeToRevenue = j.contains("salesGeneralAndAdministrativeToRevenue") ? j["salesGeneralAndAdministrativeToRevenue"].get<double>() : 0.0;
    k.researchAndDdevelopementToRevenue = j.contains("researchAndDdevelopementToRevenue") ? j["researchAndDdevelopementToRevenue"].get<double>() : 0.0;
    k.intangiblesToTotalAssets = j.contains("intangiblesToTotalAssets") ? j["intangiblesToTotalAssets"].get<double>() : 0.0;
    k.capexToOperatingCashFlow = j.contains("capexToOperatingCashFlow") ? j["capexToOperatingCashFlow"].get<double>() : 0.0;
    k.capexToRevenue = j.contains("capexToRevenue") ? j["capexToRevenue"].get<double>() : 0.0;
    k.capexToDepreciation = j.contains("capexToDepreciation") ? j["capexToDepreciation"].get<double>() : 0.0;
    k.stockBasedCompensationToRevenue = j.contains("stockBasedCompensationToRevenue") ? j["stockBasedCompensationToRevenue"].get<double>() : 0.0;
    k.grahamNumber = j.contains("grahamNumber") ? j["grahamNumber"].get<double>() : 0.0;
    k.roic = j.contains("roic") ? j["roic"].get<double>() : 0.0;
    k.returnOnTangibleAssets = j.contains("returnOnTangibleAssets") ? j["returnOnTangibleAssets"].get<double>() : 0.0;
    k.grahamNetNet = j.contains("grahamNetNet") ? j["grahamNetNet"].get<double>() : 0.0;
    k.workingCapital = j.contains("workingCapital") ? j["workingCapital"].get<double>() : 0.0;
    k.tangibleAssetValue = j.contains("tangibleAssetValue") ? j["tangibleAssetValue"].get<double>() : 0.0;
    k.netCurrentAssetValue = j.contains("netCurrentAssetValue") ? j["netCurrentAssetValue"].get<double>() : 0.0;
    k.investedCapital = j.contains("investedCapital") ? j["investedCapital"].get<double>() : 0.0;
    k.averageReceivables = j.contains("averageReceivables") ? j["averageReceivables"].get<double>() : 0.0;
    k.averagePayables = j.contains("averagePayables") ? j["averagePayables"].get<double>() : 0.0;
    k.averageInventory = j.contains("averageInventory") ? j["averageInventory"].get<double>() : 0.0;
    k.daysSalesOutstanding = j.contains("daysSalesOutstanding") ? j["daysSalesOutstanding"].get<double>() : 0.0;
    k.daysPayablesOutstanding = j.contains("daysPayablesOutstanding") ? j["daysPayablesOutstanding"].get<double>() : 0.0;
    k.daysOfInventoryOnHand = j.contains("daysOfInventoryOnHand") ? j["daysOfInventoryOnHand"].get<double>() : 0.0;
    k.receivablesTurnover = j.contains("receivablesTurnover") ? j["receivablesTurnover"].get<double>() : 0.0;
    k.payablesTurnover = j.contains("payablesTurnover") ? j["payablesTurnover"].get<double>() : 0.0;
    k.inventoryTurnover = j.contains("inventoryTurnover") ? j["inventoryTurnover"].get<double>() : 0.0;
    k.roe = j.contains("roe") ? j["roe"].get<double>() : 0.0;
    k.capexPerShare = j.contains("capexPerShare") ? j["capexPerShare"].get<double>() : 0.0;
}