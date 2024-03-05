#ifndef _FINANCIAL_DATA_INTERFACE_
#define _FINANCIAL_DATA_INTERFACE_

#include <string>


class Financial_data_interface{
    
 public:
     virtual ~Financial_data_interface() = default;

        virtual std::string get_date() const = 0;
        virtual std::string get_symbol() const = 0;
        virtual std::string get_reported_currency() const = 0;
        virtual std::string get_cik() const = 0;
        virtual std::string get_filling_date() const = 0;
        virtual std::string get_accepted_date() const = 0;
        virtual std::string get_calendar_year() const = 0;
        virtual std::string get_period() const = 0;
     
};




#endif