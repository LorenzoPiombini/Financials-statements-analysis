#ifndef _BALANCESHEET_H_
#define _BALANCESHEET_H_

#include <string>
#include "nlohmann/json.hpp"


class Balancesheet {
    private:
         std::string date;
        std::string symbol;
        std::string reportedCurrency;
        std::string cik;
        std::string fillingDate;
        std::string acceptedDate;
        std::string calendarYear;
        std::string period;
		long long cashAndCashEquivalents;
		long long shortTermInvestments;
		long long cashAndShortTermInvestments;
		long long netReceivables;
		long long inventory;
		long long otherCurrentAssets;
		long long totalCurrentAssets;
		long long propertyPlantEquipmentNet;
		long long goodwill;
		long long intangibleAssets;
		long long goodwillAndIntangibleAssets;
		long long longTermInvestments;
		long long taxAssets;
		long long otherNonCurrentAssets;
		long long totalNonCurrentAssets;
		long long otherAssets;
		long long totalAssets;
		long long accountPayables;
		long long shortTermDebt;
		long long taxPayables;
		long long deferredRevenue;
		long long otherCurrentLiabilities;
		long long totalCurrentLiabilities;
		long long longTermDebt;
		long long deferredRevenueNonCurrent;
		long long deferredTaxLiabilitiesNonCurrent;
		long long otherNonCurrentLiabilities;
		long long totalNonCurrentLiabilities;
		long long otherLiabilities;
		long long capitalLeaseObligations;
		long long totalLiabilities;
		long long preferredStock;
		long long commonStock;
		long long retainedEarnings; 
		long long accumulatedOtherComprehensiveIncomeLoss;
		long long othertotalStockholdersEquity;
		long long totalStockholdersEquity;
		long long totalEquity;
		long long totalLiabilitiesAndStockholdersEquity;
		long long minorityInterest;
		long long totalLiabilitiesAndTotalEquity;
		long long totalInvestments;
		long long totalDebt;
		long long netDebt;
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
		long long get_cash_and_cash_equivalents() const;
		long long get_short_term_investments() const;
		long long get_cash_and_short_term_investments() const;
		long long get_net_receivables() const;
		long long get_inventory() const;
		long long get_other_current_assets() const;
		long long get_total_current_assets() const;
		long long get_property_plant_equipment_net() const;
		long long get_goodwill() const;
		long long get_intangible_assets() const;
		long long get_goodwill_and_intangible_assets() const;
		long long get_long_term_investments() const;
		long long get_tax_assets() const;
		long long get_other_non_current_assets() const;
		long long get_total_non_current_assets() const;
		long long get_other_assets() const;
		long long get_total_assets() const;
		long long get_account_payables() const;
		long long get_short_term_debt() const;
		long long get_tax_payables() const;
		long long get_deferred_revenue() const;
		long long get_other_current_liabilities() const;
		long long get_total_current_liabilities() const;
		long long get_long_term_Debt() const;
		long long get_deferred_revenue_non_current() const;
		long long get_deferred_tax_liabilities_non_current() const;
		long long get_other_non_current_liabilities() const;
		long long get_total_non_current_liabilities() const;
		long long get_other_liabilities() const;
		long long get_capital_lease_obligations() const;
		long long get_total_liabilities() const;
		long long get_preferred_stock() const;
		long long get_common_stock() const;
		long long get_retained_earnings() const; 
		long long get_accumulated_other_comprehensive_income_loss() const;
		long long get_other_total_stockholders_equity() const;
		long long get_total_stockholders_equity() const;
		long long get_total_equity() const;
		long long get_total_liabilities_and_stockholders_equity() const;
		long long get_minority_interest() const;
		long long get_total_liabilities_and_total_equity() const;
		long long get_total_investments() const;
		long long get_total_debt() const;
		long long get_net_debt() const;
		std::string get_link() const; 
		std::string get_final_link() const;
        
        
        friend void from_json(const nlohmann::json &j, Balancesheet &b);
    
    
    
    
    };


#endif