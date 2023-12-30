#ifndef _COMPREHENSIVEINCOME_H_
#define _COMPREHENSIVEINCOME_H_

#include "ComprehensiveIncomeClasses.h"
#include "nlohmann/json.hpp"


class Comprehensiveincome {
    
        private:
            Other_comprehensive_income_loss_attributable_to_parent other_comprehensive_income_loss_attributable_to_parent;
            Comprehensive_income_loss comprehensive_income_loss;
            Comprehensive_income_loss_attributable_to_noncontrolling_interest comprehensive_income_loss_attributable_to_noncontrolling_interest;
            Comprehensive_income_loss_attributable_to_parent comprehensive_income_loss_attributable_to_parent;
            Other_comprehensive_income_loss other_comprehensive_income_loss;

        public:
            
            Other_comprehensive_income_loss_attributable_to_parent get_other_comprehensive_income_loss_attributable_to_parent();
            Comprehensive_income_loss get_comprehensive_income_loss();
            Comprehensive_income_loss_attributable_to_noncontrolling_interest get_comprehensive_income_loss_attributable_to_noncontrolling_interest();
            Comprehensive_income_loss_attributable_to_parent get_comprehensive_income_loss_attributable_to_parent();
            Other_comprehensive_income_loss get_other_comprehensive_income_loss();

            friend void from_json(const nlohmann::json &j, Comprehensiveincome &ci);
    
    
};


#endif