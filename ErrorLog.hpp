#pragma once
#include<./LogProcessor.hpp>

class ErrorLog: public LogProcessor {
    public:
        ErrorLog(LogProcessor* logger);
        void log(string type, string message);
};

ErrorLog::ErrorLog(LogProcessor * logger):LogProcessor(logger){};

void ErrorLog::log(string type, string message) {
    
    if(type == "error") {
        cout <<"ERROR_LOG"<<":: "<<message<<endl;
    } else {
        LogProcessor::log(type, message);
    }
}