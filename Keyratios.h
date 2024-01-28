#ifndef _KEYRATIOS_H_
#define _KEYRATIOS_H_

#include <string>


class Key_ratios{
 
 private:
    std::string symbol;
    std::string date;
    std::string calendarYear;
    std::string period;
    double revenuePerShare;
    double  netIncomePerShare;
    double operatingCashFlowPerShare;
    double freeCashFlowPerShare;
    double cashPerShare;
    double bookValuePerShare;
    double tangibleBookValuePerShare;
    double shareholdersEquityPerShare;
    double interestDebtPerShare;
    double marketCap;
    double enterpriseValue;
    double peRatio;
    double priceToSalesRatio;
    double pocfratio;
    double pfcfRatio;
    double pbRatio;
    double ptbRatio;
    double evToSales;
    double enterpriseValueOverEBITDA;
    double evToOperatingCashFlow;
    double evToFreeCashFlow;
    double earningsYield;
    double freeCashFlowYield;
    double debtToEquity;
    double debtToAssets;
    double netDebtToEBITDA;
    double currentRatio;
    double interestCoverage;
    double incomeQuality;
    double dividendYield;
    double payoutRatio;
    double salesGeneralAndAdministrativeToRevenue;
    double researchAndDdevelopementToRevenue;
    long long intangiblesToTotalAssets;
    double capexToOperatingCashFlow;
    double capexToRevenue;
    double capexToDepreciation;
    double stockBasedCompensationToRevenue;
    double grahamNumber;
    double roic;
    double returnOnTangibleAssets;
    double grahamNetNet;
    long long workingCapital;
    long long tangibleAssetValue;
    long long netCurrentAssetValue;
    double investedCapital;
    long long averageReceivables;
    long  long averagePayables;
    long long averageInventory;
    double daysSalesOutstanding;
    double daysPayablesOutstanding;
    double daysOfInventoryOnHand;
    double receivablesTurnover;
    double payablesTurnover;
    double inventoryTurnover;
    double roe;
    double capexPerShare;
    


public:
    // Getters for std::string members
    std::string get_symbol() const;
    std::string get_date() const;
    std::string get_calendar_year() const;
    std::string get_period() const;

    // Getters for double members
    double get_revenue_per_share() const;
    double get_net_income_per_share() const;
    double get_operating_cash_flow_per_share() const;
    double get_free_cash_flow_per_share() const;
    double get_cash_per_share() const;
    double get_book_value_per_share() const;
    double get_tangible_book_value_per_share() const;
    double get_shareholders_equity_per_share() const;
    double get_interest_debt_per_share() const;
    double get_market_cap() const;
    double get_enterprise_value() const;
    double get_pe_ratio() const;
    double get_price_to_sales_ratio() const;
    double get_pocf_ratio() const;
    double get_pfcf_ratio() const;
    double get_pb_ratio() const;
    double get_ptb_ratio() const;
    double get_ev_to_sales() const;
    double get_enterprise_value_over_EBITDA() const;
    double get_ev_to_operating_cash_flow() const;
    double get_ev_to_free_cash_flow() const;
    double get_earnings_yield() const;
    double get_free_cash_flow_yield() const;
    double get_debt_to_equity() const;
    double get_debt_to_assets() const;
    double get_net_debt_to_EBITDA() const;
    double get_current_ratio() const;
    double get_interest_coverage() const;
    double get_income_quality() const;
    double get_dividend_yield() const;
    double get_payout_ratio() const;
    double get_sga_to_revenue() const;
    double get_rnd_to_revenue() const;
    double get_intangibles_to_total_assets() const;
    double get_capex_to_operating_cash_flow() const;
    double get_capex_to_revenue() const;
    double get_capex_to_depreciation() const;
    double get_stock_based_compensation_to_revenue() const;
    double get_graham_number() const;
    double get_roic() const;
    double get_return_on_tangible_assets() const;
    double get_graham_net_net() const;
    long long get_working_capital() const;
    long long get_tangible_asset_value() const;
    long long get_net_current_asset_value() const;
    double get_invested_capital() const;
    long long get_average_receivables() const;
    long long get_average_payables() const;
    long long get_average_inventory() const;
    double get_days_sales_outstanding() const;
    double get_days_payables_outstanding() const;
    double get_days_of_inventory_on_hand() const;
    double get_receivables_turnover() const;
    double get_payables_turnover() const;
    double get_inventory_turnover() const;
    double get_roe() const;
    double get_capex_per_share() const;
    std::string get_class_name()const;
    std::string create_file_name(std::string ticker)const;
    void save_to_file(std::ofstream &out);
    bool read_from_file(std::ifstream &in,std::vector<Key_ratios*> &ratios);
    size_t compute_object_size() const;
    bool read_size_from_buffer_ratios(const std::vector<char> &buffer, size_t &pos, size_t &value);
    bool reading_string_from_buffer_ratios(const std::vector<char> &buffer, size_t &pos, std::string &value);
    void deserialize(std::string &json_string);
     

    
   // friend void from_json(const nlohmann::json &j, Key_ratios &k);
};

#endif // KEY_RATIOS_H

    
    
    
