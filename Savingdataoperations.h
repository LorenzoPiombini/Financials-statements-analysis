#ifndef _SAVINGDATAOPERATIONS_H_
#define _SAVINGDATAOPERATIONS_H_

#include <fstream>
#include <unordered_set>
#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include "Balancesheet.h"
#include "Incomestatement.h"
#include "Cashflowstatement.h"
#include "Keyratios.h"
#include "Ticker.h"
#include "Logger.h"


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
               std::vector<Key_ratios*> &ratios){
                   
      
       
           Logger logger("saving_statments.log");
       if(!balance_sheets.empty()){
           std::ofstream out_bs (balance_sheets[0]->create_file_name(ticker),
                            std::ios::binary | std::ios::app);
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
           if(!out_is){
           
           logger.log("Failed to open the file "+ income_statements[0]->create_file_name(ticker),Logger::Level::Error);
           }else{
            for (auto &ptr : income_statements){
              ptr->save_to_file(out_is);
            }           
            std::cout<< income_statements[0]->create_file_name(ticker) << " written succesfully\n";
            out_is.close(); 
            }
       }
             
      
        
         if(!cashflow_statements.empty()){   
             std::ofstream out_cfs (cashflow_statements[0]->create_file_name(ticker),
                            std::ios::binary | std::ios::app);
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
  std::ifstream in_bs (file_name_BS, std::ios::binary);
  
  if(!mock_obj.read_from_file(in_bs,balance_sheets)){
        logger.log("Failed to read the file "+file_name_BS,Logger::Level::Error);
        in_bs.close();
    }else {
        logger.log(file_name_BS +" read succesfully",Logger::Level::Info);
        in_bs.close();
        }
  
    Income_statement mock_income;
    std::string file_name_IS = ticker + "_income_statement.bin";
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

#endif