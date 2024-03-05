#ifndef _LOADINGSAVINGDATAOPERATIONS_H_
#define _LOADINGSAVINGDATAOPERATIONS_H_

#include <fstream>
#include <unordered_set>
#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include <sstream>
#include "Balancesheet.h"
#include "Incomestatement.h"
#include "Cashflowstatement.h"
#include "Keyratios.h"
#include "Ticker.h"
#include "Logger.h"
#include "Responseparsing.h"


bool organize_user_input(const std::string &user_input, std::unordered_set<std::string> &user_inputs){
   if(user_inputs.count(user_input) > 0){
         return true;
    }
    
   user_inputs.insert(user_input);
   return false;
    
}

void write_user_input_to_file(const std::unordered_set<std::string> &user_inputs, const std::string file_name){
    
    std::ofstream out(file_name, std::ios::binary);
    size_t size {user_inputs.size()};
    
    out.write(reinterpret_cast<const char*>(&size), sizeof(size));
    
     for(const auto& user_input : user_inputs){
            size = user_input.size();
            out.write(reinterpret_cast<const char*>(&size), sizeof(size));
            out.write(user_input.data(), size);
             
         }
         
    out.close();
    
}


void read_user_input(std::unordered_set<std::string> &user_inputs, const std::string &filename){
    
    std::ifstream in(filename, std::ios::binary);
    
    size_t size, len;
    in.read(reinterpret_cast<char*>(&size), sizeof(size));
    
    for(size_t i{0}; i < size; ++i){
            std::string user_input{};
            
            in.read(reinterpret_cast<char*>(&len), sizeof(len));
            user_input.resize(len);
            in.read(&user_input[0],len);
            user_inputs.insert(user_input);
        
    }
    
    in.close();
    
    

}


bool is_file(std::string filename){
       return std::filesystem::exists(filename);
    
}


template <typename T>
bool is_different(std::vector<T*> new_data, std::vector<T*> old_data){
        if (new_data.empty()) {
        return false; // No new data to compare
        }    
    
         const auto &newest_entry = new_data.front();
            
         for(const auto& old_entry : old_data){
              if(newest_entry->date == old_entry->date){
                  return false;
                  }
        }

        return true; 
}



void save_data(std::string &ticker, std::vector<Balancesheet*> &balance_sheets,
               std::vector<Income_statement*> &income_statements,
               std::vector<Cashflowstatement*> &cashflow_statements,
               std::vector<Key_ratios*> &ratios, 
               bool remove){
                   
      if (remove == true){
             std::filesystem::remove(balance_sheets[0]->create_file_name(ticker));
             std::filesystem::remove(income_statements[0]->create_file_name(ticker));
             std::filesystem::remove(cashflow_statements[0]->create_file_name(ticker));
             std::filesystem::remove(ratios[0]->create_file_name(ticker));
       }
       
           Logger logger("saving_statments.log");
       if(!balance_sheets.empty()){
           std::ofstream out_bs (balance_sheets[0]->create_file_name(ticker),
                            std::ios::binary | std::ios::app);
           //use this on server side
           //std::ofstream out_bs ("/sites/demo/bin_database/"+balance_sheets[0]->create_file_name(ticker),
           //                 std::ios::binary | std::ios::app);
                            
           if(!out_bs){
            logger.log("Failed to open the file "+balance_sheets[0]->create_file_name(ticker),Logger::Level::Error);
           }else{
                 for (auto &ptr : balance_sheets){
              ptr->save_to_file(out_bs);
              }           
               
               logger.log(balance_sheets[0]->create_file_name(ticker) +" written succesfully",Logger::Level::Info);
               out_bs.close();
               
        }
       }
        
      
       if(!income_statements.empty()){
           
          std::ofstream out_is (income_statements[0]->create_file_name(ticker),
                            std::ios::binary | std::ios::app);
          //use this on server side                   
//          std::ofstream out_is ("/sites/demo/bin_database/"+income_statements[0]->create_file_name(ticker),
//                            std::ios::binary | std::ios::app);                  
                            
           if(!out_is){
           
           logger.log("Failed to open the file "+ income_statements[0]->create_file_name(ticker),Logger::Level::Error);
           }else{
            for (auto &ptr : income_statements){
              ptr->save_to_file(out_is);
            }           
            logger.log(income_statements[0]->create_file_name(ticker)+ " written succesfully",Logger::Level::Info);
            out_is.close(); 
            }
       }
             
      
        
         if(!cashflow_statements.empty()){   
            
             std::ofstream out_cfs (cashflow_statements[0]->create_file_name(ticker),
                            std::ios::binary | std::ios::app);
             //use this on server side
//             std::ofstream out_cfs ("/sites/demo/bin_database/"+cashflow_statements[0]->create_file_name(ticker),
//                            std::ios::binary | std::ios::app);
               
            if(!out_cfs){
            
             logger.log("Failed to open the file "+cashflow_statements[0]->create_file_name(""),Logger::Level::Error);
            
            }else{
            
                for (auto &ptr : cashflow_statements){
                ptr->save_to_file(out_cfs);
                }  
         
                logger.log(cashflow_statements[0]->create_file_name(ticker) + " written succesfully.",Logger::Level::Info);
                out_cfs.close();
            }
        
         }
         
         if(!ratios.empty()){
            
           std::ofstream out_rt (ratios[0]->create_file_name(ticker),
           std::ios::binary | std::ios::app);
           //use this on server side
//            std::ofstream out_rt ("/sites/demo/bin_database/"+ ratios[0]->create_file_name(ticker),
//           std::ios::binary | std::ios::app);
           
            if(!out_rt){
            
            logger.log("Failed to open the file "+ratios[0]->create_file_name(ticker),Logger::Level::Error);
            
            }else{
            
              for (auto &ptr : ratios){
              ptr->save_to_file(out_rt);
              }  
         
             logger.log(ratios[0]->create_file_name(ticker) +" written succesfully",Logger::Level::Info);
             out_rt.close();
            }
         }
}
       
    
    






void load_data(std::string &ticker,
               std::vector<Balancesheet*> &balance_sheets,
               std::vector<Income_statement*> &income_statements,
               std::vector<Cashflowstatement*> &cashflow_statements,
               std::vector<Key_ratios*> &ratios){
    
  Logger logger("reading_file_statments.log");
  Balancesheet mock_obj;
  std::string file_name_BS = ticker + "_balance_sheet.bin";
  
//  use this on server side
//   std::string file_name_BS = "/sites/demo/bin_database/"+mock_obj.create_file_name(ticker);


  std::ifstream in_bs (file_name_BS, std::ios::binary);
  
  if(!mock_obj.read_from_file(in_bs,balance_sheets)){
        logger.log("Failed to read the file "+file_name_BS,Logger::Level::Error);
        in_bs.close();
    }else{
        logger.log(file_name_BS +" read succesfully",Logger::Level::Info);
        in_bs.close();
    }
    
    Income_statement mock_income;
    std::string file_name_IS = ticker + "_income_statement.bin";
    //  use this on server side
//   std::string file_name_IS = "/sites/demo/bin_database/"+mock_income.create_file_name(ticker);
    
    
    std::ifstream in_is (file_name_IS, std::ios::binary);
    
    if(!mock_income.read_from_file(in_is,income_statements)){
           logger.log("Failed to read the file "+file_name_IS,Logger::Level::Error);
           in_is.close();
        } else {  
            logger.log(file_name_IS + " read succesfully",Logger::Level::Info);
            in_is.close();
        }
        
    
    Cashflowstatement mock_cash;
    std::string file_name_CFS = ticker + "_cashflow_statement.bin";
    
      //  use this on server side
//   std::string file_name_CFS = "/sites/demo/bin_database/"+mock_cash.create_file_name(ticker);
    
    
    
    std::ifstream in_cfs (file_name_CFS, std::ios::binary);
    if(!mock_cash.read_from_file(in_cfs, cashflow_statements)){
          logger.log("Failed to open the file "+file_name_CFS,Logger::Level::Error);
          in_cfs.close();
        }else {
          logger.log(file_name_CFS +" read succesfully",Logger::Level::Info);
            in_cfs.close();
        }
    
    
    Key_ratios mock_ratio;
    std::string file_name_RT = ticker + "_key_ratios.bin";
    
       //  use this on server side
//   std::string file_name_RT = "/sites/demo/bin_database/"+mock_ratio.create_file_name(ticker);
    
    std::ifstream in_rt (file_name_RT, std::ios::binary);
    if(!mock_ratio.read_from_file(in_rt, ratios)){
          logger.log("Failed to open the file "+file_name_RT,Logger::Level::Error);
          in_rt.close();
        }else {
            logger.log(file_name_RT + " read succesfully",Logger::Level::Info);
            in_rt.close();
        }
    
}


void save_data_all_tickers(std::vector<Ticker*> tickers){
    std::ofstream out (tickers[0]->create_file_name(), std::ios::binary);
    
    Logger logger("saving_all_tickers_data.log");
    
    if(!out){
        
         logger.log("Failed to open the file " + tickers[0]->create_file_name(), Logger::Level::Error);
        
        } else {
            
          for (auto &item : tickers){
            item -> save_to_file(out);
           }
           logger.log(tickers[0]->create_file_name() +"has been written succesfully",Logger::Level::Info);
           out.close();
        }
}


void load_data_all_tickers(std::vector<Ticker*> tickers){
    Logger logger("load_ticker_data.log");
    Ticker mockObj;
    std::ifstream in (mockObj.create_file_name(), std::ios::binary);
    
    if(!mockObj.read_from_file(in,tickers)){
          
          logger.log("Failed to open the file "+ mockObj.create_file_name(),Logger::Level::Error);
          in.close();
        } else {
         logger.log(mockObj.create_file_name() + " has been opened succesfully",Logger::Level::Info);
         in.close();    
        }
}


void save_news(std::string response_json){
    
    std::string fileName = "general-news.json"; 
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << response_json;
        outFile.close();
        std::cout << "Data saved to " << fileName<< std::endl;
    } else {
        std::cout << "Unable to open file for writing." << std::endl;
    }
}


std::vector<std::string> load_st_transaction(std::string &ticker){
  
std::string file_name = ticker+"_st.json";
std::ifstream in_file(file_name);
std::vector<std::string> st_trans; 
  
   if(in_file.is_open()){
       
        std::stringstream buffer;
        buffer << in_file.rdbuf();
        std::string json_string = buffer.str();
        
        st_trans = split_json_objects(json_string);
    }

   in_file.close();   
    return st_trans; 
}


//save senate transaction to file 
void save_st_to_file(std::string &json_string, std::string &ticker){
    Logger logger("save_senate.log");
    std::string fileName = ticker + "_st.json"; 
    std::ofstream outFile(fileName, std::ios::app);
    if (outFile.is_open()) {
        outFile << json_string;
        outFile.close();
        logger.log("Data saved to " + fileName,Logger::Level::Info);
    } else {
        logger.log("Unable to open "+fileName+" for writing",Logger::Level::Error);
    }
    
}

//helper function to see if there is an update
bool is_updates_st_trans(std::vector<std::string> old_st, std::vector<std::string> nw_st_trans){
     int counter{0};
     if(!old_st.empty() && !nw_st_trans.empty()){  
         
                 for(auto st : old_st){
                     //uncomment these lines for debugging
//                     std::cout<< "showing old data\n";
//                      std::cout<<st<<std::endl;
//                      std::string temp;
//                        getline(std::cin,temp) ;
                       for(size_t i{0}; i < nw_st_trans.size(); ++i){
                                //uncomment these lines for debugging
//                                std::cout<< "showing new data\n";
//                                std::cout << nw_st_trans[i] <<std::endl;
//                                std::string temp;
//                                getline(std::cin,temp) ;
                                if(st == nw_st_trans[i]){
                                    //uncomment these lines for debugging
                                        counter++;
//                                      std::cout<< "this two data are equal, counter is :" <<counter <<"\n";    
                                       break;
                                    }else{
                                        //uncomment these lines for debugging
//                                      std::cout<< "this two data are not equal\n";    
                                    }
                           }
                 }
     }
     if (counter == old_st.size()){
         return false;
     } else{
             return true;
         }
}

//update senate transaction
std::vector<int> update_db_st_tr(std::string &ticker, std::vector<std::string> nw_st){
    std::string file_name = ticker + "_st.json";
    std::vector<int> positions;
    std::vector<std::string> old_st = load_st_transaction(ticker);
    
    if(!old_st.empty()){
        
        for(auto old : old_st){
               for(int i{0}; i < nw_st.size(); ++i){
                    if(old == nw_st[i]){
                         positions.push_back(i);
                        }
                   }
            }
    }
    
    
    if(is_file(file_name)){
    std::filesystem::remove(file_name);  
    }
    
    
    for(auto nw : nw_st){
        save_st_to_file(nw,ticker);
        
        }
        std::cout<< ticker << " has been updated\n";
    
   return positions;
}




#endif
