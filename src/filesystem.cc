// Standard Headers
#include <iostream>

// 3rd Party Headers

// Project Headers
#include "filesystem.h"
#include "logging.h"

string documentsDestination;

// Return the users Documents folder for their respective platform.
FileSystem::getDocuments()
{
    MAIN_PRINT("[FileSystem] getDocuments");
#ifdef _WIN32 // Windows specific code
    
#elseif __APPLE__ // macOS specific code
    
#else // Linux specific code
    
#endif
}