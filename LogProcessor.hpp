#pragma once
#include<bits/stdc++.h>
#include<Logger.hpp>
using namespace std;

class LogProcessor: public Logger {
    public:
        LogProcessor* nextLogger;

        LogProcessor(LogProcessor* logger) {
            this->nextLogger = logger;
        }

        void log(string type, string message);
};

void LogProcessor::log(string type, string message) {
    if (this->nextLogger != nullptr) {
        this->nextLogger->log(type, message);
    }
}        
