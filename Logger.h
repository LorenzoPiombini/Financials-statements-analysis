#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <mutex>
#include <filesystem>
#include <chrono>



class Logger{
    
    
    
    
    public:
    enum class Level {
        Debug,
        Info,
        Warning,
        Error
        
        };
        
        Logger(const std::string file_name) 
             : log_file(file_name, std::ios::app){
                 if(!log_file.is_open()){
                     throw std::runtime_error("Unable to open log file: " + file_name);
                     }
                 }
                 
        ~Logger(){
            if(log_file.is_open()){
                log_file.close();
                }
            }
    
    
       void log(const std::string &message, Level level){
           std::lock_guard<std::mutex> guard(log_mutex);
           auto now = std::chrono::system_clock::now();
           auto nowTimeT = std::chrono::system_clock::to_time_t(now);
           auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
           
           std::tm bt = *std::localtime(&nowTimeT);
           std::ostringstream oss;
           oss << std::put_time(&bt, "%Y-%m-%d %H:%M:%S");
           oss << '.' << std::setfill('0') << std::setw(3) << nowMs.count();
           
           log_file << "[" << oss.str() << "] [" << level_to_string(level) << "]" << message <<std::endl;
           
           }
    
    private:
       std::ofstream log_file;
       std::mutex log_mutex;
       
        std::string  level_to_string(Level level){
            switch(level){
                
                case Level::Debug: return "DEBUG";
                case Level::Info: return "INFO";
                case Level::Warning: return "WARNING";
                case Level::Error: return "ERROR";
                default: return "UNKNOWN";
                
                }
        }
    
    
};




#endif 