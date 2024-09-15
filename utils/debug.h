#ifndef __DEBUG_H__
#define __DEBUG_H__

#define STRINGIFY(x) #x

//black magic for the preprocessor to not just spit out main.c:__LINE__
#define TOSTRING(x) STRINGIFY(x)

#define __CUR_LOC (__FILE__ ":" TOSTRING(__LINE__))

#endif // __DEBUG_H__