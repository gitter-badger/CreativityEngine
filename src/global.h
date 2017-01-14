#ifndef GLOBAL_H
#define GLOBAL_H

extern bool gVerbose;
extern bool gWindowed;
extern bool gBorderless;
extern bool gGameRunning;
extern int gWindowWidth;
extern int gWindowHeight;

/* Change these variables if you decide to fork this engine for another project, otherwise leave these macros alone.

Also, note the following:
Both the org and app strings may become part of a directory name, so please follow these rules:

"Try to use the same org string (including case-sensitivity) for all your applications that use this function.
* Always use a unique app string for each one, and make sure it never changes for an app once you've decided on it.
* Unicode characters are legal, as long as it's UTF-8 encoded, but...
* ...only use letters, numbers, and spaces. Avoid punctuation like "Game Name 2: Bad Guy's Revenge!" ... "Game Name 2" is sufficient."
- SDL Documentation.

*/
#define ENGINE_NAME "Creativity Engine"
#define ENGINE_DEVELOPER "Creativity Engine Team"
#define ENGINE_YEARS "2017"
#define ENGINE_MAJOR "0"
#define ENGINE_MINOR "0"
#define ENGINE_BUILD "1"

#endif