#pragma once
#include<./LogProcessor.hpp>

class DebugLog: public LogProcessor {
    public:
        DebugLog(LogProcessor* logger);
        void log(string type, string message);
};

DebugLog::DebugLog(LogProcessor * logger):LogProcessor(logger){};

void DebugLog::log(string type, string message) {
    
    if(type == "debug") {
        cout <<"DEBUG_LOG"<<":: "<<message<<endl;
    } else {
        LogProcessor::log(type, message);
    }
}