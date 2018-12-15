#include "../secure/secure.h"
#include <stdarg.h>

int printfWithTime(const char* format, ...) {
    int result;
    va_list args;

    va_start(args, format);

    char timeBuf[32];
    getTimeLocal(timeBuf);

    // call printf indirectly
    int (*fptrInderect)(const char*, ...) = printf;
    fptrInderect("[LOG] %s:", timeBuf); // add time before user's printf
    result = vprintf(format, args);
    printf("\n");
    va_end(args);

    return result;
}
