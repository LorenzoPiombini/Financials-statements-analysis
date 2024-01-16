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


void save_data(std::vector<Balancesheet*> &balance_sheets,
               std::vector<Income_statement*> &income_statements,
               std::vector<Cashflowstatement*> &cashflow_statements){
                   
      std::ofstream out_bs (balance_sheets[0]->create_file_name(""),
                            std::ios::binary | std::ios::app);
       
       if(!out_bs){
            std::cout << "Failed to open the file "<< balance_sheets[0]->create_file_name("") <<"\n";
           }else{
                 for (auto &ptr : balance_sheets){
              ptr->save_to_file(out_bs);
              }           
               
               std::cout<< balance_sheets[0]->create_file_name("") << " written succesfully\n";
               out_bs.close();
               
        }
    
        
      std::ofstream out_is (income_statements[0]->create_file_name(""),
                            std::ios::binary | std::ios::app);
       if(!out_is){
           
           std::cout << "Failed to open the file "<< income_statements[0]->create_file_name("") <<"\n";
           }else{
            for (auto &ptr : income_statements){
              ptr->save_to_file(out_is);
            }           
            std::cout<< income_statements[0]->create_file_name("") << " written succesfully";
            out_is.close(); 
       }
     
       std::ofstream out_cfs (cashflow_statements[0]->create_file_name(""),
                            std::ios::binary | std::ios::app);
       
        if(!out_cfs){
            
            std::cout << "Failed to open the file "<< cashflow_statements[0]->create_file_name("") <<"\n";
            
            }else{
            
       for (auto &ptr : cashflow_statements){
              ptr->save_to_file(out_cfs);
          }  
         
        std::cout<< cashflow_statements[0]->create_file_name("") << " written succesfully";
        out_cfs.close();
        }
    
    
}



void load_data(std::string ticker,
               std::vector<Balancesheet*> &balance_sheets,
               std::vector<Income_statement*> &income_statements,
               std::vector<Cashflowstatement*> &cashflow_statements){
    
    
    std::ifstream in_bs (balance_sheets[0]->create_file_name(ticker), std::ios::binary);
    
    if(!in_bs){
        
       std::cout << "Failed to open the file "<< balance_sheets[0]->create_file_name(ticker) <<"\n";
        
        }else{
             
            while(!in_bs.eof()){
                Balancesheet* sheet = new Balancesheet();
                sheet->read_from_file(in_bs);
                balance_sheets.push_back(sheet);
                
                }
                
            std::cout<< balance_sheets[0]->create_file_name(ticker) << " read succesfully\n";
            in_bs.close();
            }
    
    std::ifstream in_is (income_statements[0]->create_file_name(ticker), std::ios::binary);
    
    if(!in_is){
        std::cout << "Failed to open the file "<< income_statements[0]->create_file_name(ticker) <<"\n";
        }else{
            
            while(!in_is.eof()){
                Income_statement* income = new Income_statement();
                income->read_from_file(in_is);
                income_statements.push_back(income);
                
                }
                
            std::cout<< income_statements[0]->create_file_name(ticker) << " read succesfully\n";
            in_is.close();
            
            }
    
    
    std::ifstream in_cfs (cashflow_statements[0]->create_file_name(ticker), std::ios::binary);
    
    if(!in_cfs){
        std::cout << "Failed to open the file "<< cashflow_statements[0]->create_file_name(ticker) <<"\n";
        }else{
            
            while(!in_cfs.eof()){
                Cashflowstatement* cash = new Cashflowstatement();
                cash->read_from_file(in_cfs);
                cashflow_statements.push_back(cash);

                }
                
            std::cout<< cashflow_statements[0]->create_file_name(ticker) << " read succesfully\n";
            in_cfs.close();
            
            
            
            }
}




#endif