#include "common.h"

// free memory safely
void _safeFree(void** p) {
    if (p != NULL && *p != NULL) {
        free(*p);
        *p = NULL;
    }
}

char* getLine(void) {
     // max character one line can have, if exceed, exit with error
    const int MAX_LINE_LEN = 1000;
    const int step = 10; // add step every time when buffer is full
    int defaultLineLen = 100; // 默认一行的长度
    char* buffer = malloc(defaultLineLen * sizeof(char) + 1);

    if (buffer == NULL) {
        printf("getLine() malloc() err\n");
        return NULL;
    }

    char *currPos = buffer;

    int len = 0;
    int ch;

    while (1) {
        ch = fgetc(stdin);
        if (ch == '\n') {
            break;
        }

        len++;
        if (len > MAX_LINE_LEN) {
            printf("getLine() err: line too long\n");
            return NULL;
        }

        if (len > defaultLineLen) {
            char* newBuffer = realloc(buffer, defaultLineLen += step);
            if (newBuffer == NULL) {
                printf("getLine() realloc() err\n");
                return NULL;
            }

            // 指向新申请的内存, 偏移之前读入的所有字符的长度
            currPos = newBuffer + (currPos - buffer);
            buffer = newBuffer;
        }
        *currPos++ = ch;
    }

    *currPos = '\0';
    return buffer;
}

int getTimeLocal(char* timeBuf) {
    time_t t;
    struct tm* lt;
    time(&t); // get UNIX timestamp
    lt = localtime(&t); // to time struct
    // strftime (timeBuf, 32, "%Y-%m-%d %H:%M:%S", lt);
    sprintf(timeBuf, "%4d-%2d-%2d %2d:%2d:%02d",
               lt->tm_year+1900,
               lt->tm_mon,
               lt->tm_mday,
               lt->tm_hour,
               lt->tm_min,
               lt->tm_sec);

    return 0;
}
