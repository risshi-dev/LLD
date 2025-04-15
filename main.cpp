#include<InfoLog.hpp>
#include<ErrorLog.hpp>
#include<DebugLog.hpp>

int main() {
    Logger* logObj = new DebugLog(new InfoLog(new ErrorLog(nullptr)));

    logObj->log("info", "Api Response Successfull");
    logObj->log("error", "Api Response Failed");
    logObj->log("debug", "Api Response Missing");

    return 0;
}