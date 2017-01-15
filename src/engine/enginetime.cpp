#include "enginetime.h"

EngineTime::EngineTime()
{

}

EngineTime::~EngineTime()
{
    
}

// Get current date/time, format is DD-MM-YYYY.HH:mm:ss (15-1-2017.10:28:44)
const std::string EngineTime::currentDateTime() 
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%d-%m-%Y.%X", &tstruct);

    return buf;
}