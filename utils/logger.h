//KrnlAid Logger by Lolguy91 is marked with [CC0 1.0](https://creativecommons.org/publicdomain/zero/1.0/?ref=chooser-v1) 

//How to use:
//1, create an wrapper file file
//2, define __krnlaid_log_printf(const char *fmt, ...) and __krnlaid_log_cease()
//3, include utils/logger.h
//4, now you can use this wrapper in any file

#ifndef __KRNLAID_LOG_H__
#define __KRNLAID_LOG_H__

#define KRNLAID_LOG_TRACE 0
#define KRNLAID_LOG_DEBUG 1
#define KRNLAID_LOG_WARN  2
#define KRNLAID_LOG_ERROR 3

#ifndef __kprintf
#error "Please define __kprintf(const char *fmt, ...)"
#endif
#ifndef __kcease
#error "Please define __kcease()"
#endif

static char* krnlaid_log_log_levels[] = {
    "TRACE",
    "DEBUG",
    "WARN",
    "ERROR",
};

#define __krnlaid_log_log(level,fmt,...) __kprintf("[%s] " __FUNCTION__ ":" fmt, krnlaid_log_log_levels[level],##__VA_ARGS__)

#define __krnlaid_log_assert(cond,fmt,...) \
    if(!(cond)){ \
        __kprintf("Assert failed: \"" fmt "\" at " __FILE__ ":%d \n",__LINE__); \
        __kcease(); \
    }

#define log_trace(fmt, ...) __krnlaid_log_log(KRNLAID_LOG_TRACE, fmt, ##__VA_ARGS__)
#define log_debug(fmt, ...) __krnlaid_log_log(KRNLAID_LOG_DEBUG, fmt, ##__VA_ARGS__)
#define log_warn(fmt, ...)  __krnlaid_log_log(KRNLAID_LOG_WARN,  fmt, ##__VA_ARGS__)
#define log_error(fmt, ...) __krnlaid_log_log(KRNLAID_LOG_ERROR, fmt, ##__VA_ARGS__)

#define assert(cond,fmt,...) __krnlaid_log_assert(cond,fmt,##__VA_ARGS__)

#endif // __KRNLAID_LOG_H__
