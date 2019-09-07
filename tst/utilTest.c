#include "tst/unit.h"
#include "src/util.h"
#include <stdio.h>

int unit_testsRun = 0;

static char const *testWhitespace() {
    unit_ASSERT("h is not whitespace", !util_whitespace('h'));
    unit_ASSERT("5 is not whitespace", !util_whitespace('5'));
    unit_ASSERT("' ' is whitespace", util_whitespace(' '));
    unit_ASSERT("\\n is whitespace", util_whitespace('\n'));
    unit_ASSERT("\\t is whitespace", util_whitespace('\t'));
    return 0;
}

static char const *testHash() {
    unit_ASSERT(
        "hashes do not collide",
        util_hash("bongo", 5) != util_hash("bingol", 6)
    );
    unit_ASSERT("hashes are not just all 0", util_hash("bongo", 5) != 0);
    return 0;
}

static char const *testDict() {
    struct Dict dict;
    util_initDict(&dict, 40);
    util_addDict(&dict, "key A", 1);
    util_addDict(&dict, "BBB", 2);
    util_addDict(&dict, "THIRD key", 3);
    util_addDict(&dict, "4", 4);
    util_addDict(&dict, "Fifthe keyu", 5);
    util_addDict(&dict, "6 KEY", 6);
    util_addDict(&dict, "77777", 7);
    util_addDict(&dict, "eighth key", 8);
    util_addDict(&dict, "Key I", 9);
    util_addDict(&dict, "key J", 10);
    unit_ASSERT("key is found", util_findDict(&dict, "key A") == (size_t)1);
    unit_ASSERT("key is found", util_findDict(&dict, "BBB") == (size_t)2);
    unit_ASSERT("key is found", util_findDict(&dict, "THIRD key") == (size_t)3);
    unit_ASSERT("key is found", util_findDict(&dict, "4") == (size_t)4);
    unit_ASSERT("key is found", util_findDict(&dict, "Fifthe keyu") == (size_t)5);
    unit_ASSERT("key is found", util_findDict(&dict, "6 KEY") == (size_t)6);
    unit_ASSERT("key is found", util_findDict(&dict, "77777") == (size_t)7);
    unit_ASSERT("key is found", util_findDict(&dict, "eighth key") == (size_t)8);
    unit_ASSERT("key is found", util_findDict(&dict, "Key I") == (size_t)9);
    unit_ASSERT("key is found", util_findDict(&dict, "key J") == (size_t)10);
    unit_ASSERT("nonexistent key is not found", util_findDict(&dict, "junk") == (size_t)0);
    util_freeDict(&dict, 0);
}

static char const *testTinyDict() {
    struct Dict dict;
    util_initDict(&dict, 1);
}

static char const *runTests() {
    unit_RUN(testWhitespace);
    unit_RUN(testHash);
    unit_RUN(testDict);
    return 0;
}

int main(int argc, char const **argv) {
    char const *result = runTests();
    if (result) printf("FAILURE: %s\n", result);
    else printf("SUCCESS\n");
    printf("%d tests executed\n", unit_testsRun);
}
