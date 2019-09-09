#include "src/exe.h"

#define STACK_SIZE 64

enum StackType {
    StackType_NUMBER,
    StackType_STRING
};

struct StackItem {
    enum StackType type;
    union {
        struct {
            char *value;
        } string;
        struct {
            float value;
        } number;
    } content;
};

char *exe_runString(char const *string) {
    struct StackItem stack[STACK_SIZE];
    struct Dict variables;
    util_initDict(&dict, 30);
    int tokenStart = util_skipWhitespace(string);
    int tokenEnd = util_findWhitspace(string + tokenStart);
    while (tokenEnd > tokenStart) {
        
    }
}
