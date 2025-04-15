#pragma once
#include<./LogProcessor.hpp>

class InfoLog: public LogProcessor {
    public:
        InfoLog(LogProcessor* logger);
        void log(string type, string message);
};

InfoLog::InfoLog(LogProcessor * logger):LogProcessor(logger){};

void InfoLog::log(string type, string message) {
    
    if(type == "info") {
        cout <<"INFO_LOG"<<":: "<<message<<endl;
    } else {
        LogProcessor::log(type, message);
    }
}