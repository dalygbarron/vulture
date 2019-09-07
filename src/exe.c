#include "src/exe.h"

#define STACK_SIZE 64

char *exe_runString(char const *string) {
    void *stack[STACK_SIZE];
    struct Dict dict;
    util_initDict(&dict, 30);
    int tokenStart = util_skipWhitespace(string);
    int tokenEnd = util_findWhitspace(string + tokenStart);
    while (tokenEnd > tokenStart) {
        
    }
}
