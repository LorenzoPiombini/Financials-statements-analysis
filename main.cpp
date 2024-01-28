#include <iostream>
#include <curl/curl.h>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Savingdataoperations.h"
#include "Getfunctions.h"
#include "Incomestatement.h"
#include "Balancesheet.h"
#include "Keyratios.h"
#include  "Cashflowstatement.h"
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

//this funtion is to debug a file proccesing 
void printFileContents(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Cannot open file " << filename << std::endl;
        return;
    }

    char byte;
    while (file.read(&byte, sizeof(byte))) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (0xff & static_cast<unsigned int>(byte)) << " ";
    }
    std::cout << std::endl;
}

int main()
{    
//     std::string filename = "KO_income_statement.bin"; // Replace with your file name
//      printFileContents(filename);


     vector<Balancesheet*> balance_sheets;
     vector<Cashflowstatement*> cashflow_statements;
     vector<Income_statement*> income_statements;
     std::vector<Key_ratios*> ratios;
     
     std::unordered_set<string> tickers;
     
     
     bool _save;
     
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
          _save = true;
      } else {
          load_data(ticker,balance_sheets,income_statements,cashflow_statements,ratios);
          _save = false;
      }
       
       
      if(!balance_sheets.empty() && !income_statements.empty() && !cashflow_statements.empty()){
          
          
      double value_of_company = get_pe_evaluetion(ticker, income_statements, ratios);
      cout << ticker <<" value according to P/E valuetion is: "<< value_of_company << "\n";
      double dfc = get_dcf_model(ticker,cashflow_statements,balance_sheets,income_statements);
      cout << ticker<<" value according to DFC is: "<< dfc << "\n";
       
      past_performance_five_years(ticker, cashflow_statements,balance_sheets,income_statements);
      
      //cout << "mine ROIC is : " << get_ROIC(balance_sheets,income_statements,cashflow_statements)<< std::endl;
      cout << "ROIC is : " << ratios[0]->get_roic() * 100<< std::endl;
      cout << "P/B is : " <<ratios[0]->get_pb_ratio()<< std::endl;
      cout <<  "Owner Earnings: " << get_owner_earnings(balance_sheets,income_statements,cashflow_statements) <<std::endl;
      //cout << ticker + " statment link:" << balance_sheets[0]->get_final_link() << std::endl;
      
      if(_save){
            save_data(balance_sheets,income_statements,cashflow_statements,ratios);
          }
      
      
      
        
       /*******************FREEING THE MEMORY****************************/
     
       if(!balance_sheets.empty()){
     for(auto &ptr : balance_sheets){ 
          delete ptr;
       }}
     
      if(!income_statements.empty()){
     for(auto &ptr : income_statements){ 
          delete ptr;
      }}
      
      if(!cashflow_statements.empty()){
      for(auto &ptr : cashflow_statements){ 
          delete ptr;
      }}
       
       if(!ratios.empty()){
       for(auto &ptr : ratios)
           delete ptr;
       }
       
       
       balance_sheets.clear();
       income_statements.clear();
       cashflow_statements.clear();
       ratios.clear();
       
       /***************************************************************/
       
       
      /*SAVING USER INPUT*/
      write_user_input_to_file(tickers,"history_user_research.bin");
     
     
      }
     }while(true);
     
     cout<< "\nThank you for using our application. exiting...\n";
     write_user_input_to_file(tickers,"history_user_research.bin");
     
      return 0;

}






	
