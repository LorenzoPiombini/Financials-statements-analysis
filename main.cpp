#include <iostream>
#include <curl/curl.h>
#include <string>
#include <vector>
#include "Getfunctions.h"
#include "Responseparsing.h"
#include "Printingfunctions.h"

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
     
     string responseStr= get_company_data(ticker);
    
     
     vector<Response> responses;
     responses = parsingJsonFromTheAPI(responseStr);
     
     //display a result to confirm that the parsing happened correctcly
      
      /* print_income_statement(responses); */
      
      print_income_statement_ratios(responses);
      return 0;

}
   
	
