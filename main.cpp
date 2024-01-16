#include <iostream>
#include <curl/curl.h>
#include <string>
#include <vector>
#include <fstream>
#include "Savingdataoperations.h"
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
     vector<Balancesheet*> balance_sheets;
     vector<Cashflowstatement*> cashflow_statements;
     vector<Income_statement*> income_statements;
     std::vector<Key_ratios*> ratios;
     
     std::unordered_set<string> tickers;
     
     
      if (is_file("history_user_research.bin")){
         
          read_user_input(tickers,"history_user_research.bin");
          
         }
     
     do{
     
     cout<< "financials statement of company (write exit to quit): ";
     
     string ticker{};
     std::getline(cin,ticker);
     safeTyping(ticker);
    
     if(ticker == "EXIT" || ticker == "QUIT")
                  break;
      
      
      if (!organize_user_input(ticker,tickers)){
          get_company_financials_statements(ticker,balance_sheets,cashflow_statements,income_statements,ratios);
      } else {
          load_data(ticker,balance_sheets,income_statements,cashflow_statements);
          
      }
      
      
      double value_of_company = get_pe_evaluetion(ticker, income_statements, ratios);
      cout << ticker <<" value according to P/E valuetion is: "<< value_of_company << "\n";
      double dfc = get_dcf_model(ticker,cashflow_statements,balance_sheets,income_statements);
      cout << ticker<<" value according to DFC is: "<< dfc << "\n";
       
      past_performance_five_years(ticker, cashflow_statements,balance_sheets,income_statements);
      
      
      save_data(balance_sheets,income_statements,cashflow_statements);
      
      
        
       /*******************FREEING THE MEMORY****************************/
     
       
     for(auto &ptr : balance_sheets){ 
          delete ptr;
      }
     
      
     for(auto &ptr : income_statements){ 
          delete ptr;
      }
      
      for(auto &ptr : cashflow_statements){ 
          delete ptr;
       }
       
       for(auto &ptr : ratios) delete ptr;
       
       balance_sheets.clear();
       income_statements.clear();
       cashflow_statements.clear();
       ratios.clear();
     
     /***************************************************************/
     
     }while(true);
     
     cout<< "\nThank you for using our application. exiting...\n";
     write_user_input_to_file(tickers,"history_user_research.bin");
     
      return 0;

}
   
	
