#ifndef _GETFUNCTIONS_H_
#define _GETFUNCTIONS_H_

#include <iostream>
#include <string>
#include <curl/curl.h>

using std::cout;
using std::string;
using std:: cerr;

size_t writeCallback(void *ptr, size_t size, size_t nmemb, string *data){
    data -> append((char*)ptr, size * nmemb);
    return size*nmemb;
}

string get_company_data(string ticker){
    
    string base_url = "https://api.polygon.io/vX/reference/financials?";
    string company = "ticker=";
    string apiKey = "&apiKey=ZHogS3Ewx7wCAHAqXMNoPoKhhuj8ph1h";
    string url = base_url + company + ticker + apiKey;
    const char* cStyleUrl = url.c_str();
    
    
    //initialize libcurl
	curl_global_init(CURL_GLOBAL_DEFAULT);
    
    //curl handle 
    CURL *curlHandle = curl_easy_init();
    
    if(curlHandle){
        string responseString;
        string headerString;
        
        //set the URL 
        curl_easy_setopt(curlHandle, CURLOPT_URL, cStyleUrl);
        
        //set call back function
        curl_easy_setopt(curlHandle,CURLOPT_WRITEFUNCTION, writeCallback);
        
        //set a pointer to the response string
        curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &responseString);
        
        //set a pointer to Header string
        curl_easy_setopt(curlHandle, CURLOPT_HEADERDATA, &headerString);
        
        //perform the request
        CURLcode res = curl_easy_perform(curlHandle);
        
        if(res != CURLE_OK){
               string error(curl_easy_strerror(res));
               string message = "curl_easy_perform() failed: ";
               return message+error;
               
         }else{
                //cleanup
                curl_easy_cleanup(curlHandle);
                //global clean up;
                curl_global_cleanup();
                return responseString;
         }

    } else{
        string error = "Error initializing curl\n";
        return error;
    }
        
}


#endif