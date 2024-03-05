#include <iostream>
#include <curl/curl.h>
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <deque>
#include <map>
#include "LoadingSavingdataoperations.h"
#include "Getfunctions.h"
#include "Incomestatement.h"
#include "Balancesheet.h"
#include "Keyratios.h"
#include "Cashflowstatement.h"
#include "IntrinsicValueCalculation.h"
#include "Responseparsing.h"
#include "DCF.h"
#include "Exchange.h"
#include "displayingFunctions.h"
#include "Senate.h"
#include "Base64encoder.h"



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
     
std::unordered_set<string> update_database(std::unordered_set<std::string> user_inputs);

void desktop_mode(std::unordered_set<std::string> &tickers,
     vector<Balancesheet*> &balance_sheets,
     vector<Cashflowstatement*> &cashflow_statements,  
     vector<Income_statement*> &income_statements,
     vector<Key_ratios*> &ratios);
     
void generate_json_files(std::unordered_set<std::string> user_inputs,
    vector<Balancesheet*> &balance_sheets,
     vector<Cashflowstatement*> &cashflow_statements,  
     vector<Income_statement*> &income_statements,
     vector<Key_ratios*> &ratios);
     
void server_mode(std::unordered_set<std::string> updated_tickers, 
     std::unordered_set<std::string> ticker,
     vector<Balancesheet*> &balance_sheets,
     vector<Cashflowstatement*> &cashflow_statements,  
     vector<Income_statement*> &income_statements,
     vector<Key_ratios*> &ratios);

void temp_function_to_fill_user_inputs(std::unordered_set<std::string> user_inputs,
                                       std::map<string,string> &nasdaq, 
                                       std::map<string,string> &amex,
                                       std::map<string,string>&nyse);
void get_symbols(std::map<string,string> &nasdaq,std::map<string,string> &amex,std::map<string,string> &nyse);
void create_db_senator_transaction();
std::map<string,vector<int>> check_st_trasns_update();
vector<string> first_5_tr(vector<string> st_trans);
std::string helper_json_cleaner(const std::string &str);
void check_data_integrety();
std::string extract_sp500_members(std::string &json_string);
vector<Senate*> prepare_mail_result(std::map<string,vector<int>> update_st);
std::string create_mail_messages(vector<Senate*> &senate);
std::string get_email_addresses();
void send_emails(string msg, string addresses);
/*************************************************************************************/
/*                              MAIN PROGRAM                                         */  
/*************************************************************************************/

int main()
{    
    
  // Logger logger("/sites/demo/CppSoftwareDemo/log/process.log");
    // logger.log("process started",Logger::Level::Info);

     vector<Balancesheet*> balance_sheets;
     vector<Cashflowstatement*> cashflow_statements;
     vector<Income_statement*> income_statements;
     std::vector<Key_ratios*> ratios;
     
     std::unordered_set<string> tickers;
     std::unordered_set<string> updated_tickers;
     

      if (is_file("history_user_research.bin")){
          //cout << "file read!\n";
          read_user_input(tickers,"history_user_research.bin");
           
         }
         //cout<<tickers.size();
         std::map<string,string> nasdaq;
         std::map<string,string> amex;
         std::map<string,string> nyse;
      
      //generate_json_files(tickers,balance_sheets,cashflow_statements,income_statements,ratios);
      //server_mode(updated_tickers,tickers,balance_sheets,cashflow_statements,income_statements,ratios);
      //temp_function_to_fill_user_inputs(tickers,nasdaq,amex,nyse);
     
     // create_db_senator_transaction();
      
//
       std::map<string,vector<int>>update_senate = check_st_trasns_update();
//      for(const auto& [key,value] : update_senate){
//          cout<< key << "has Vector of size " << value.size()<< ", value are:"<<std::endl;
//          for(auto i : value){
//              cout<< i <<" ";
//              }
//              cout<<"\n";
//          std::string temp{};
//          getline(std::cin,temp);
//          }
     
        std::vector<Senate*> senate = prepare_mail_result(update_senate);
        std::string message = create_mail_messages(senate);
        std::string addresses = get_email_addresses();
        
        cout<<message<<std::endl;
        
        send_emails(message,addresses);
        
         //free memory
        for(auto pt : senate){
              delete pt;
            }
          //clear the vector  
         senate.clear();   
         
        //send_emails(message,addresses);
        
        
        
        
//      
      
      
      //this function is for debug reasons
      //check_data_integrety();
      
      //desktop_mode(tickers,balance_sheets,cashflow_statements,income_statements,ratios);
      
      
      
//      for(auto t : tickers){
//          DCF dcf_obj;
//          get_dcf(t,dcf_obj);
//          load_data(t,balance_sheets,income_statements,cashflow_statements,ratios);
//          create_json_result(t,balance_sheets,income_statements,cashflow_statements,ratios,dcf_obj);
//          std::this_thread::sleep_for(std::chrono::milliseconds(200));
//          
//          }
      
//        
//       
//       
//       get_symbols(nasdaq,amex,nyse);
//     
//      std::vector<std::map<string,string>> excs;
//        excs.push_back(nasdaq);
//        excs.push_back(amex);
//        excs.push_back(nyse);
//        
//        for(auto e : excs){
//            for(const auto &pair : e){
//                cout << pair.first << " : " << pair.second << std::endl;
//                }
//        }
//        
//      cout << nasdaq.size() << " " << amex.size() << " " << nyse.size() << std::endl;
//          

   // logger.log("process ended",Logger::Level::Info);
    return 0;
}

/*****************************************************************************************************/
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

void upload_to_server(string ticker){
        //string bashCommand = "./auto_upload.sh";
        string bash_script= "./upload_json.sh " + ticker;
    int returnValue = std::system(bash_script.c_str());
    
    if (returnValue == 0) {
        cout << "Uploaded to the server succesfully.\n";
    } else {
        cout << "Upload to the server was unsucesful.\n";
    }    
}

void send_emails(string msg, string addresses){
   string bash_script = "./email_send.sh " + msg +" "+ addresses;    
   int returnValue = std::system(bash_script.c_str());
   
   
   if (returnValue == 0) {
        cout << "emails sent succesfully.\n";
    } else {
        cout << "problem sending the emails.\n";
    }   
}


void generate_database(
     std::unordered_set<std::string> user_inputs,
     vector<Balancesheet*> &banace_sheets,
     vector<Cashflowstatement*> &cashflow_statements,  
     vector<Income_statement*> &income_statements,
     vector<Key_ratios*> &ratios) {
   
       
   std::string filePath = "companies_ticker_map.json";      
   

    
       std::map<string,string> nasdaq;
       std::map<string,string> amex;
       std::map<string,string> nyse;
          
        
        
       get_symbols(nasdaq,amex,nyse);
       
       
       
  
       std::vector<std::map<string,string>> excs;
        excs.push_back(nasdaq);
        excs.push_back(amex);
        excs.push_back(nyse);
       
       for(auto exc : excs){
        
        
        for (const auto &pair : exc){
             string ticker = pair.first;
             string name = pair.second;
            if(!organize_user_input(ticker, user_inputs)){
           
                 
                 get_company_financials_statements(ticker,banace_sheets,cashflow_statements,income_statements,ratios);
                
                if(!banace_sheets.empty() && !income_statements.empty() && !cashflow_statements.empty() && !ratios.empty()){
         
                 save_data(ticker,banace_sheets,income_statements,cashflow_statements,ratios, false);
                 write_user_input_to_file(user_inputs,"history_user_research.bin");
        
                 //this creates a JSON map of name of the company and the ticker
                 //this is to achive a better user experiense on the server side,
                 add_or_update_map(name,ticker,filePath);
                 
                 //making sure we do not pass the 300 calls per minute on our API
                  
                   std::this_thread::sleep_for(std::chrono::milliseconds(200));
                   free_memory(banace_sheets,income_statements,cashflow_statements,ratios);
                 }
           }
            
        } 
       }       

}


std::unordered_set<string> update_database(std::unordered_set<std::string> user_inputs){
     
    std::unordered_set<string> updated_user_inputs;

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
             save_data(u,writing_new_bs,writing_new_is,writing_new_cfs,writing_new_kr,false);
             free_memory(writing_new_bs,writing_new_is,writing_new_cfs,writing_new_kr);
             updated_user_inputs.insert(u);
         }
         
         if(o_is[0]->get_period() != n_is[0]->get_period()){
             writing_new_is.push_back(n_is[0]);
             save_data(u,writing_new_bs,writing_new_is,writing_new_cfs,writing_new_kr,false);
             free_memory(writing_new_bs,writing_new_is,writing_new_cfs,writing_new_kr);
             updated_user_inputs.insert(u);
         }
         
         if(o_cfs[0]->get_period() != n_cfs[0]->get_period()){
             writing_new_cfs.push_back(n_cfs[0]);
             save_data(u,writing_new_bs,writing_new_is,writing_new_cfs,writing_new_kr,false);
             free_memory(writing_new_bs,writing_new_is,writing_new_cfs,writing_new_kr);
             updated_user_inputs.insert(u);
         }
         
         if(o_kr[0]->get_period() != n_kr[0]->get_period()){
             writing_new_kr.push_back(n_kr[0]);
             save_data(u,writing_new_bs,writing_new_is,writing_new_cfs,writing_new_kr,false);
             free_memory(writing_new_bs,writing_new_is,writing_new_cfs,writing_new_kr);
             updated_user_inputs.insert(u);
         }
         
         free_memory(o_bs,o_is,o_cfs,o_kr);
         free_memory(n_bs,n_is,n_cfs,n_kr);
         
         
     }       

     return updated_user_inputs; 
        
}


void desktop_mode(std::unordered_set<std::string> &tickers,
     vector<Balancesheet*> &balance_sheets,
     vector<Cashflowstatement*> &cashflow_statements,  
     vector<Income_statement*> &income_statements,
     vector<Key_ratios*> &ratios){
     //this is a debugging comments to check if there is any problem regarding writing to files
//     std::string filename = "KO_income_statement.bin"; // Replace with your file name
//      printFileContents(filename);

 
     
     
     bool _save;
    
     
     do{
     
     cout<< "financials statement of company (write exit to quit): ";
     
     string ticker{};
     std::getline(cin,ticker);
     safeTyping(ticker);
    
     if(ticker == "EXIT" || ticker == "QUIT"){
              break;
     }else if(ticker == "UPDATE"){
         
           if(!is_file("history_user_research.bin")){
               generate_database(tickers,balance_sheets,cashflow_statements,income_statements,ratios);
               } else {
                 
                update_database(tickers);
                     
               }
           
           
    } else if (ticker == "JSON"){ 
            
               
            //cout << "I am inside json IF/nsize of tickers is " << tickers.size();
            
            for(auto t : tickers){
                //cout << "starting all over again\n";
                //std::string param_to_del = t;
               // cout<<t<<std::endl;
                
               // cout << "I am inside json LOOP/n";
                
                load_data(t,balance_sheets,income_statements,cashflow_statements,ratios);
               
               if(!balance_sheets.empty() && !income_statements.empty() 
                && !cashflow_statements.empty() && !ratios.empty()){
                 DCF dcf_obj;
                 get_dcf(t,dcf_obj);
                 
                create_json_result(t,balance_sheets,income_statements,cashflow_statements,ratios,dcf_obj);
               //cout << "about to free the memory\n";
               
               free_memory(balance_sheets,income_statements,cashflow_statements,ratios);
               std::this_thread::sleep_for(std::chrono::milliseconds(200));
               }
            }
             _save = false;
             //upload_to_server();
             //exit(0);
        
    }else if(ticker == "NEWS"){
        
              string response = get_general_news();
              save_news(response);
        
     }else if(ticker == "DEBUG"){
         
     std::cout << "Welcome to the DEBUG mode, you can check the integrety of your data in this section\n";
     std::cout << "then you can compute the data again, in a more accurate way.\n";
         
     bool exit =false;
         
    while(!exit){ 
    
     cout << "which ticker are you troubleshooting:\n";
     cout << "(enter q to exit)\n";
     std::getline(cin,ticker);
     safeTyping(ticker);
     
     if(ticker == "Q" || ticker == "q")
         break;
         
         
     if(!organize_user_input(ticker,tickers)){
         
           cout<< "This ticker is not currently in the database,  do you want to fetch the data for this company? (Y/N) ";
          string user_input{};
          std::getline(cin,ticker);
          safeTyping(ticker);
          
          if(user_input == "Y"){
              get_company_financials_statements(ticker,balance_sheets,cashflow_statements,income_statements,ratios);
          }else if(user_input == "N"){
              cout<<"you choose not to fetch the data at the moment.\n";
              tickers.erase(ticker);
              continue;
           }else{
               cout<<"invalid input, operation cancelled.\n";
               tickers.erase(ticker);
               continue;
           }
    } else {
        //loading the data from disk
        load_data(ticker,balance_sheets,income_statements,cashflow_statements,ratios);
        
        if(!balance_sheets.empty() && !income_statements.empty() 
           && !cashflow_statements.empty() && !ratios.empty()){

                while(true){
                    std::cout << "Please select one of the follwing:\n";
                    std::cout << "0 - Balance sheet,\n1 - Cashflow statement,\n2 - Income statement\n3 - Key metrics\n";
                    std::cout << "enter q to quit this company menu...\n";
                    std::string input{};
                    std::getline(cin,input);
                    
     
                            if(is_number(input)){
                                //convert the string into integer number
                               int selection = stoi(input);
                               switch(selection){
                                   
                                    case 0 : display_bs(balance_sheets);break;
                                    case 1 : display_cfs(cashflow_statements);break;
                                    case 2 : display_is(income_statements);break;
                                    case 3 : display_rt(ratios);break;
                                   
                                   }
                               cout << "do you want to override this cpmpany data? N/y\n";
                               string change_data{};
                               getline(cin,change_data);
                               
                               if(change_data == "Y" || change_data == "y"){
                                   
                                   free_memory(balance_sheets,income_statements, cashflow_statements, ratios);
                                   get_company_financials_statements(ticker,balance_sheets,cashflow_statements,income_statements,ratios);
                                   save_data(ticker, balance_sheets,income_statements,cashflow_statements,ratios,true);
                                   //get dcf from the API
                                   DCF dcf_obj;
                                   get_dcf(ticker,dcf_obj);
                                   
                                   create_json_result(ticker,balance_sheets,income_statements,cashflow_statements,ratios,dcf_obj);
                                   upload_to_server(ticker);
                                   cout<<"check if the data are looking good.\n";
                                   
                                   
                                   
                                   }
                               
                            } else {
                     
                                    safeTyping(input);
                                    
                                    if (input == "Q"){
                                        free_memory(balance_sheets,income_statements, cashflow_statements, ratios);

                                        break;
                                    }
                            }
                }// inner while loop   
        }// if to check that we do have data loaded in the vectors
    }//else if
    
     
     
    
    
    }//while loop
         
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
            DCF dcf_obj;
      
           get_dcf(ticker,dcf_obj);
        
        cout << ticker << ": "<< dcf_obj.get_dcf() << std::endl;
        create_json_result(ticker,balance_sheets,income_statements,cashflow_statements,ratios,dcf_obj);
        
      if(_save){
            save_data(ticker,balance_sheets,income_statements,cashflow_statements,ratios,false);
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
    
    
}

void generate_json_files(std::unordered_set<std::string> user_inputs,
     vector<Balancesheet*> &balance_sheets,
     vector<Cashflowstatement*> &cashflow_statements,  
     vector<Income_statement*> &income_statements,
     vector<Key_ratios*> &ratios){
     
            for(auto t : user_inputs){
                //cout << "starting all over again\n";
                //std::string param_to_del = t;
               // cout<<t<<std::endl;
                
                load_data(t,balance_sheets,income_statements,cashflow_statements,ratios);
               
               if(!balance_sheets.empty() && !income_statements.empty() 
                && !cashflow_statements.empty() && !ratios.empty()){
                 
                       DCF dcf_obj;
                       get_dcf(t,dcf_obj);
               create_json_result(t,balance_sheets,income_statements,cashflow_statements,ratios,dcf_obj);
               //cout << "about to free the memory\n";
               free_memory(balance_sheets,income_statements,cashflow_statements,ratios);
               std::this_thread::sleep_for(std::chrono::milliseconds(200));
               }
            }
            
            //uncomment these lines if you are using the desktop version
            // _save = false;
            // upload_to_server();
             //exit(0);
    
    
    }
    
void server_mode(std::unordered_set<std::string> updated_tickers, 
     std::unordered_set<std::string> tickers,
     vector<Balancesheet*> &balance_sheets,
     vector<Cashflowstatement*> &cashflow_statements,  
     vector<Income_statement*> &income_statements,
     vector<Key_ratios*> &ratios){
    
    if(is_file("/sites/demo/bin_database/history_user_research.bin")){
            updated_tickers = update_database(tickers);
            generate_json_files(updated_tickers,balance_sheets,cashflow_statements,income_statements,ratios);
            }else{
              generate_database(tickers,balance_sheets,cashflow_statements,income_statements,ratios);
              generate_json_files(tickers,balance_sheets,cashflow_statements,income_statements,ratios);
            }
    
    }
    
//usefull in debug
void temp_function_to_fill_user_inputs(std::unordered_set<std::string> user_inputs,
                                       std::map<string,string> &nasdaq, 
                                       std::map<string,string> &amex,
                                       std::map<string,string>&nyse)
{
    
    get_symbols(nasdaq,amex,nyse);
    
       std::vector<std::map<string,string>> excs;
        excs.push_back(nasdaq);
        excs.push_back(amex);
        excs.push_back(nyse);
    
   for(size_t i{0}; i < excs.size(); ++i){
      // cout<<"inside the loop looking for stocks "<< i << tickers[i]->get_exchange_short_name() <<std::endl;
    
               for(const auto &pair : excs[i]){
                   
                   if(!organize_user_input(pair.first, user_inputs)){
                            write_user_input_to_file(user_inputs,"history_user_research.bin");
                       }
               }
        
   
    
}

}



void get_symbols(std::map<string,string> &nasdaq, std::map<string,string> &amex,std::map<string,string>&nyse){
    
     string exchanges[3] = {"AMEX","NASDAQ","NYSE"};
       
       for(auto ex : exchanges){
            
                 if(ex == exchanges[0]){
                    Exchange excg;  
                    vector<string> js_r = get_exchange_symbols(ex);
                        
                        for(auto js : js_r){ 
                            excg.deserialize(js);
                        }
                    
                    amex = excg.get_symbols();                 
                 }else if(ex == exchanges[1]){
                      Exchange excg;  
                      vector<string> js_r = get_exchange_symbols(ex);
                     
                        for(auto js : js_r){ 
                            excg.deserialize(js);
                        }
                      nasdaq = excg.get_symbols();  
                     
                 }else if(ex == exchanges[2]){
                      Exchange excg;  
                      vector<string> js_r = get_exchange_symbols(ex);
                     
                        for(auto js : js_r){ 
                            excg.deserialize(js);
                        }
                      nyse = excg.get_symbols();  
                }     
        }
    
}

std::string helper_json_cleaner(const std::string &str){
  size_t first = str.find_first_not_of(" \t\n\r");
  
  if(first == std::string::npos) return "";    
  
   size_t last = str.find_last_not_of(" \t\n\r");
   return str.substr(first, (last - first +1));
}


std::string extract_sp500_members(std::string &json_string){
    std::string token;
    
    std::string trimmed_json = helper_json_cleaner(json_string);
    
    
    if(!trimmed_json.empty() && trimmed_json.back() =='}'){
        trimmed_json.pop_back();
        }
    
    std::istringstream json_stream(trimmed_json);
    
    if(json_stream.peek() == '{'){
            json_stream.get();
    }
    
    while(getline(json_stream, token, ',')){
         auto separator_pos = token.find(':');
         if (separator_pos == std::string::npos) continue; 
         
         auto key = helper_json_cleaner(token.substr(0, separator_pos));
         auto value = helper_json_cleaner(token.substr(separator_pos + 1));
         
        
        
          
          if (!key.empty() && key.front() == '"' && key.back() == '"') {
            key = key.substr(1, key.size() - 2);
          }
         if(!value.empty() && value.front() == '"' && value.back() =='"'){
             value = value.substr(1, value.size() - 2);
             }

//this line is for debugging 
 //         std::cout <<"Key is long : " << key.length() << "and it looks like"+key<< std::endl;
         
         if(key == "symbol"){ return value;}

    }    
    return "";
}

vector<string> mebers_sp500(){
    vector<string> resp = get_sp500_m();
     vector<string> sp500;
   
   
      for(auto r : resp){
          std::string member = extract_sp500_members(r);
          sp500.push_back(member);
      }  

 return sp500;  
}

vector<string> first_5_tr(vector<string> st_trans){
    
     if(st_trans.size() > 5){
            vector<string>  recent_st(st_trans.begin(), st_trans.begin() + 5);
            return recent_st;   
    }
    
    vector<string> empty;
     return empty;
}

void create_db_senator_transaction(){
   
   vector<string> sp500 = mebers_sp500();
   //int counter{};
     
     for(auto mb : sp500){
         
         std::vector<std::string> st_trans = get_snt_transactions(mb);
            
                   vector<string>  recent_st = first_5_tr(st_trans);
                     if(!recent_st.empty()){
                     for (auto rst : recent_st){
                           save_st_to_file(rst,mb);
                           }
                      
                     }
                     
              std::this_thread::sleep_for(std::chrono::milliseconds(200));
//         counter++;
//         cout<< "call number: " << counter<<"\n";       
         }
}


void check_data_integrety(){
    vector<string> sp500 = mebers_sp500();
    std::vector<string> old_st;
    
    for(auto sp: sp500){
           std::cout<<"check data for " << sp << "..."<<std::endl;
           old_st = load_st_transaction(sp);
           std::cout<< "olda data has size " << old_st.size()<<std::endl;
           
           if (!old_st.empty()){
               
               for(auto o : old_st){
                    cout<< o<<std::endl;
                   }
               
               }
           std::string temp{};
           getline(std::cin,temp);
    }
    
    
    
    
}
std::map<string,vector<int>> check_st_trasns_update(){
    vector<string> sp500 = mebers_sp500();
    std::vector<string> old_st;
    std::vector<string> nw_st;
    std::map<string,vector<int>> updated_list;
    std::vector<int> equal_positions;
    //int counter{};
     
     for(auto sp: sp500){
           old_st = load_st_transaction(sp);
           vector<string> response = get_snt_transactions(sp);
           //cout<< "checking for updates for "<<sp<<std::endl;
           nw_st = first_5_tr(response);
           
           //cout<< "old data size: "<< old_st.size()<<std::endl;
           
           //check if they have the right size
           
           if(!old_st.empty() && !nw_st.empty()){
          
               //check for update
                if(is_updates_st_trans(old_st,nw_st)){
                      //update
                     updated_list[sp] = update_db_st_tr(sp,nw_st);
                      
                 }
                
           }else if(old_st.empty() && nw_st.size() > 0){
                  for(auto nw : nw_st){
                      vector<int> empty;
                      updated_list[sp] = empty;
                      save_st_to_file(nw,sp);
                      cout<< "new data saved for " << sp<<std::endl;
                      }   
                  
           }
         
         std::this_thread::sleep_for(std::chrono::milliseconds(200));
//         counter++;
//         cout<< "call number: " << counter<<"\n";
     }
     
     return updated_list;
      
      
    
}

vector<Senate*> prepare_mail_result(std::map<string,vector<int>> update_st){
     vector<Senate*> senate;
     vector<string> response;
     
     for(const auto& [key, value] : update_st){
         std::string ticker = key;
         
         response = get_snt_transactions(ticker);
         vector<string> transactions= first_5_tr(response);
           
           if(!value.empty()){
                       for(int i{0};i < value.size();++i){
                            //deleting the elemnt that we do not need
                            transactions.at(value[i]) = "";
                              }
                        
                        
                        
                        for (auto tr: transactions){
                                   if(tr == ""){
                                       continue;
                                       } 
                                       
                               Senate* senator = new Senate();
                               senator->deserialize(tr);
                               senate.push_back(senator);
                     }                
                        
            }else {
                 for (auto tr: transactions){
                     Senate* senator = new Senate();
                       senator->deserialize(tr);
                       senate.push_back(senator);
                     }                
                
                
             }
             
             std::this_thread::sleep_for(std::chrono::milliseconds(200));
     }
     
     return senate;

}


std::string create_mail_messages(vector<Senate*> &senate){
     
    std::string message{};
         
          for(const auto pt : senate){
                string last_name = helper_json_cleaner(pt->get_last_name());
                string asset_description = helper_json_cleaner(pt->get_asset_description());
                string first_name = helper_json_cleaner(pt->get_first_name());
                string type = helper_json_cleaner(pt->get_type());
                string transaction_date = helper_json_cleaner(pt ->get_transaction_date());
                
                
                 message +=   asset_description +"\n";  
                 message += "Senator: "+ first_name + " " + last_name+ ",\n";
                 message += "Type: "+ type +",\n";
                 message +=  "transaction date: " + transaction_date +",\n";
                 message += "__________________________________________________________\n";
                 message += "__________________________________________________________\n";
                 
              }
              
         
        return  message;
    
}


std::string get_email_addresses(){
       std::ifstream file("email_addresses.txt");
       std::vector<string> addresses;
       std::string address;
       
       while(file >> address){
           addresses.push_back(address);
           }
           
        file.close();
        
        std::stringstream ss;
        
        for (size_t i = 0; i < addresses.size(); ++i) {
                    ss << addresses[i];
                    if (i != addresses.size() - 1) { // Check if this is not the last word
                        ss << ", ";
                    }
         }
         
         std::string result = ss.str();
         
         return result;
    
}

/*************************************************************************************************/
/*************************************************************************************************/
