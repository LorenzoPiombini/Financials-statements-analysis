#ifndef _SENATE_H_
#define _SENATE_H_


#include <string>

class Senate {

    private:
    std::string firstName; 
    std::string lastName; 
    std::string office;
    std::string link; 
    std::string dateRecieved;
    std::string transactionDate;
    std::string owner;
    std::string assetDescription;
    std::string assetType;
    std::string type;
    std::string amount;
    std::string comment;
    std::string symbol;
    
    public:
    std::string get_first_name() const; 
    std::string get_last_name() const; 
    std::string get_office() const;
    std::string get_link() const; 
    std::string get_date_recieved() const;
    std::string get_transaction_date() const;
    std::string get_owner()const;
    std::string get_asset_description()const;
    std::string get_asset_type()const;
    std::string get_type()const;
    std::string get_amount() const;
    std::string get_comment() const;
    std::string get_symbol() const;
    void deserialize(std::string &json_string);
    void save_to_file(std::string &json_string, std::string &ticker);
    
    
};

#endif