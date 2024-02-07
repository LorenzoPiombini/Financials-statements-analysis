#include <iostream>
#include <curl/curl.h>
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
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


//functions prototypes
void free_memory(vector<Balancesheet*> &balace_sheets,vector<Income_statement*> &income_statements,
                 vector<Cashflowstatement*> &cashflow_statements,
                 vector<Key_ratios*> &ratios);
                 
void safeTyping(string &str);
void printFileContents(const std::string& filename);

void upload_to_server();

void generate_database(
     std::unordered_set<std::string> user_inputs,
     vector<Balancesheet*> &banace_sheets,
     vector<Cashflowstatement*> &cashflow_statements,  
     vector<Income_statement*> &income_statements,
     vector<Key_ratios*> &ratios);
     
void update_database(std::unordered_set<std::string> user_inputs);

/*************************************************************************************/
/*                              MAIN PROGRAM                                         */  
/*************************************************************************************/

int main()
{    
    //this is a debugging comments to check if there is any problem regarding writing to files
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
    
     if(ticker == "EXIT" || ticker == "QUIT"){
              break;
     }else if(ticker == "UPDATE"){
         
           if(is_file("history_user_research.bin")){
               generate_database(tickers,balance_sheets,cashflow_statements,income_statements,ratios);
               } else {
                 
                update_database(tickers);
                     
               }
           
           
    } else if (ticker == "JSON"){ 
            
               
            
            
            for(auto t : tickers){
                //cout << "starting all over again\n";
                std::string param_to_del = t;
               // cout<<t<<std::endl;
                
                load_data(t,balance_sheets,income_statements,cashflow_statements,ratios);
               
               if(!balance_sheets.empty() && !income_statements.empty() 
                && !cashflow_statements.empty() && !ratios.empty()){
                
               create_json_result(t,balance_sheets,income_statements,cashflow_statements,ratios);
               //cout << "about to free the memory\n";
               free_memory(balance_sheets,income_statements,cashflow_statements,ratios);
               }
            }
             _save = false;
             upload_to_server();
             exit(0);
        
    }else if(ticker == "NEWS"){
        
              string response = get_general_news();
              save_news(response);
        
     }else{ 
      if (!organize_user_input(ticker,tickers)){
          get_company_financials_statements(ticker,balance_sheets,cashflow_statements,income_statements,ratios);
          _save = true;
      } else {
          load_data(ticker,balance_sheets,income_statements,cashflow_statements,ratios);
          _save = false;
      }
       
       
      if(!balance_sheets.empty() && !income_statements.empty() && !cashflow_statements.empty() && !ratios.empty()){
         //cout<< balance_sheets.size() << " " << income_statements.size() <<" "<< cashflow_statements.size()<< " " << ratios.size() << std::endl; 
         
        create_json_result(ticker,balance_sheets,income_statements,cashflow_statements,ratios);
        
      if(_save){
            save_data(ticker,balance_sheets,income_statements,cashflow_statements,ratios);
      }
      
      
      
        
       /*******************FREEING THE MEMORY****************************/
        free_memory(balance_sheets,income_statements,cashflow_statements,ratios);
       
       /***************************************************************/
       
       
      /*SAVING USER INPUT*/
      write_user_input_to_file(tickers,"history_user_research.bin");
      }
      
     }
     
     }while(true);
   
     
     cout<< "\nThank you for using our application. exiting...\n";
     write_user_input_to_file(tickers,"history_user_research.bin");
     
      return 0;

}


/******************************FUNCTIONS IMPLEMENTATION**************************************************/

void free_memory(vector<Balancesheet*> &balace_sheets,
                 vector<Income_statement*> &income_statements,
                 vector<Cashflowstatement*> &cashflow_statements,
                 vector<Key_ratios*> &ratios){
                     
 if(!balace_sheets.empty()){
       //cout << "Freeing memory for balance sheet\n";
               for(auto &ptr : balace_sheets){ 
               delete ptr;
             }}
     
            if(!income_statements.empty()){
            //    cout << "Freeing memory for income statement\n";
             for(auto &ptr : income_statements){ 
              delete ptr;
             }}
      
              if(!cashflow_statements.empty()){
                //  cout << "Freeing memory for cashflow statement\n";
              for(auto &ptr : cashflow_statements){ 
                  delete ptr;
              }}
       
               if(!ratios.empty()){
                   
                  // cout << "Freeing memory for ratios\n";
                   
               for(auto &ptr : ratios)
                   delete ptr;
               }
               
       //cout << "cleaning all the vectors\n";
           balace_sheets.clear();
           income_statements.clear();
           cashflow_statements.clear();
           ratios.clear();    
}


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

void upload_to_server(){
        string bashCommand = "./auto_upload.sh";
    int returnValue = std::system(bashCommand.c_str());

    if (returnValue == 0) {
        cout << "Uploaded to the server succesfully.\n";
    } else {
        cout << "Uploaded to the server was unsucesful.\n";
    }    
}


void generate_database(
     std::unordered_set<std::string> user_inputs,
     vector<Balancesheet*> &banace_sheets,
     vector<Cashflowstatement*> &cashflow_statements,  
     vector<Income_statement*> &income_statements,
     vector<Key_ratios*> &ratios) {
   
       
   std::string filePath = "companies_ticker_map.json";      
   std::vector<Ticker*> tickers = get_tickers();

    
   for(size_t i{0}; i < tickers.size(); ++i){
      // cout<<"inside the loop looking for stocks "<< i << tickers[i]->get_exchange_short_name() <<std::endl;
    if((tickers[i]-> get_type() == "stock") && 
       (tickers[i]->get_exchange_short_name() =="AMEX" || tickers[i]->get_exchange_short_name() =="NYSE" ||
        tickers[i]->get_exchange_short_name() == "NASDAQ")){
            
            std::string sym = tickers[i]->get_symbol();
            std::string name = tickers[i]->get_name();
            
            //cout<< "symbol is: " << sym << ", name is: " << name << std::endl; 
            
            if(!sym.empty() || !(sym.length() == 0)){

                   if(!organize_user_input(tickers[i]->get_symbol(), user_inputs)){
           
                 
                 get_company_financials_statements(sym,banace_sheets,cashflow_statements,income_statements,ratios);
                
                if(!banace_sheets.empty() && !income_statements.empty() && !cashflow_statements.empty() && !ratios.empty()){
         
                 save_data(sym,banace_sheets,income_statements,cashflow_statements,ratios);
                 write_user_input_to_file(user_inputs,"history_user_research.bin");
        
                 //this creates a JSON map of name of the company and the ticker
                 //this is to achive a better user experiense on the server side,
                 add_or_update_map(name,sym,filePath);
                 
                 //making sure we do not pass the 350 calls per minute on our API
                  if(user_inputs.size() > 5000){
                   std::this_thread::sleep_for(std::chrono::milliseconds(200));
                   } 
                 }
            }
        }
         
           
          free_memory(banace_sheets,income_statements,cashflow_statements,ratios);
    } 
    } //for loop

             
         

}


void update_database(std::unordered_set<std::string> user_inputs){
/************  DATA SAVED ON DISK  **********************/
     vector<Balancesheet*> o_bs;
     vector<Income_statement*> o_is;
     vector<Cashflowstatement*> o_cfs;
     vector<Key_ratios*> o_kr;
     
/************  NEW DATA FROM API  **********************/        
     vector<Balancesheet*> n_bs;
     vector<Income_statement*> n_is;
     vector<Cashflowstatement*> n_cfs;
     vector<Key_ratios*> n_kr;    
     
     for(auto u : user_inputs){
        load_data(u,o_bs,o_is,o_cfs,o_kr);
        get_company_financials_statements(u,n_bs,n_cfs,n_is,n_kr); 
        
        vector<Balancesheet*> writing_new_bs;
        vector<Income_statement*> writing_new_is;
        vector<Cashflowstatement*> writing_new_cfs;
        vector<Key_ratios*> writing_new_kr;
        
        
        if(o_bs[0]->get_period() != n_bs[0]->get_period()){
             writing_new_bs.push_back(n_bs[0]);
             save_data(u,writing_new_bs,writing_new_is,writing_new_cfs,writing_new_kr);
             free_memory(writing_new_bs,writing_new_is,writing_new_cfs,writing_new_kr);
         }
         
         if(o_is[0]->get_period() != n_is[0]->get_period()){
             writing_new_is.push_back(n_is[0]);
             save_data(u,writing_new_bs,writing_new_is,writing_new_cfs,writing_new_kr);
             free_memory(writing_new_bs,writing_new_is,writing_new_cfs,writing_new_kr);
         }
         
         if(o_cfs[0]->get_period() != n_cfs[0]->get_period()){
             writing_new_cfs.push_back(n_cfs[0]);
             save_data(u,writing_new_bs,writing_new_is,writing_new_cfs,writing_new_kr);
             free_memory(writing_new_bs,writing_new_is,writing_new_cfs,writing_new_kr);
         }
         
         if(o_kr[0]->get_period() != n_kr[0]->get_period()){
             writing_new_kr.push_back(n_kr[0]);
             save_data(u,writing_new_bs,writing_new_is,writing_new_cfs,writing_new_kr);
             free_memory(writing_new_bs,writing_new_is,writing_new_cfs,writing_new_kr);
         }
         
         free_memory(o_bs,o_is,o_cfs,o_kr);
         free_memory(n_bs,n_is,n_cfs,n_kr);
         
         
     }        
/******************************************************************/
         
}// end of functions

/*************************************************************************************************/
/*************************************************************************************************/