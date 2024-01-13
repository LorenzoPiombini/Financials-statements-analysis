#include <iostream>
#include <curl/curl.h>
#include <string>
#include <vector>
#include "Getfunctions.h"
#include "Incomestatement.h"
#include "Balancesheet.h"
#include "IntrinsicValueCalculation.h"
#include "Responseparsing.h"


using std::cout;
using std::cin;
using std::string;
using std:: cerr;
using std::toupper;
using std::vector;

// this function is to guarantee that the ticker is caps
// it will change the string in place
void safeTyping(string &str){
    for(char &c : str){
        c = toupper(c);
        }
}


int main()
{
    
    
     cout<< "financials statement of company: ";
     
     string ticker{};
     std::getline(cin,ticker);
     safeTyping(ticker);
     
     
       //double value = median_historical_pe(ticker);
       //cout << value << "\n";
      
     
      double value_of_company = get_pe_evaluetion(ticker);
      cout << ticker <<" value according to P/E valuetion is: "<< value_of_company << "\n";
      double dfc = get_dcf_model(ticker);
      cout << ticker<<" value according to DFC is: "<< dfc << "\n";
       
      past_performance_five_years(ticker);
     
//       std::string is = get_company_income_statement(ticker);
//       cout<<is;
//       std::vector<Income_statement> responses = parsing_json_from_api<Income_statement>(is,ticker);
//     std::string response= get_company_key_ratios(ticker);
//     std::string response1 = get_company_income_statement(ticker);
//      
//    cout<< response << "\n";
//    cout<< response1 << "\n";
     
//     vector<Balancesheet> responses;
//     std::string response_json = get_company_balance_sheet(ticker,"quarter");
//     responses = parsing_json_from_api<Balancesheet>(response_json,ticker);
//     cout<<response_json;
//     //display a result to confirm that the parsing happened correctcly
//      
//      for(size_t i{0}; i < responses.size(); ++i){
//      cout << responses[i].get_revenue()<< "\n";
//      }
      return 0;

}
   
	
