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
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;
    int g = 7;
    int h = 8;
    int i = 9;
    int j = 10;
    struct Dict dict;
    util_initDict(&dict, 20);
    util_addDict(&dict, "key A", &a);
    util_addDict(&dict, "BBB", &b);
    util_addDict(&dict, "THIRD key", &c);
    util_addDict(&dict, "4", &d);
    util_addDict(&dict, "Fifthe keyu", &e);
    util_addDict(&dict, "6 KEY", &f);
    util_addDict(&dict, "77777", &g);
    util_addDict(&dict, "eighth key", &h);
    util_addDict(&dict, "Key I", &i);
    util_addDict(&dict, "key J", &j);
    unit_ASSERT("key is found", util_findDict(&dict, "BBB") == &b);
    unit_ASSERT("key is found", util_findDict(&dict, "eighth key") == &h);
    unit_ASSERT("key is found", util_findDict(&dict, "Fifthe keyu") == &e);
    unit_ASSERT("key is found", util_findDict(&dict, "key J") == &j);
    unit_ASSERT("key is found", util_findDict(&dict, "key A") == &a);
    unit_ASSERT("key is found", util_findDict(&dict, "THIRD key") == &c);
    unit_ASSERT("key is found", util_findDict(&dict, "77777") == &g);
    unit_ASSERT("key is found", util_findDict(&dict, "6 KEY") == &f);
    unit_ASSERT("key is found", util_findDict(&dict, "Key I") == &i);
    unit_ASSERT("key is found", util_findDict(&dict, "4") == &d);
    unit_ASSERT("fake key is not found", util_findDict(&dict, "junk") == 0);
    util_freeDict(&dict, 0);
}

static char const *testTinyDict() {
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;
    int g = 7;
    int h = 8;
    int i = 9;
    int j = 10;
    struct Dict dict;
    util_initDict(&dict, 1);
    util_addDict(&dict, "key A", &a);
    util_addDict(&dict, "BBB", &b);
    util_addDict(&dict, "THIRD key", &c);
    util_addDict(&dict, "4", &d);
    util_addDict(&dict, "Fifthe keyu", &e);
    util_addDict(&dict, "6 KEY", &f);
    util_addDict(&dict, "77777", &g);
    util_addDict(&dict, "eighth key", &h);
    util_addDict(&dict, "Key I", &i);
    util_addDict(&dict, "key J", &j);
    unit_ASSERT("key is found", util_findDict(&dict, "BBB") == &b);
    unit_ASSERT("key is found", util_findDict(&dict, "eighth key") == &h);
    unit_ASSERT("key is found", util_findDict(&dict, "Fifthe keyu") == &e);
    unit_ASSERT("key is found", util_findDict(&dict, "key J") == &j);
    unit_ASSERT("key is found", util_findDict(&dict, "key A") == &a);
    unit_ASSERT("key is found", util_findDict(&dict, "THIRD key") == &c);
    unit_ASSERT("key is found", util_findDict(&dict, "77777") == &g);
    unit_ASSERT("key is found", util_findDict(&dict, "6 KEY") == &f);
    unit_ASSERT("key is found", util_findDict(&dict, "Key I") == &i);
    unit_ASSERT("key is found", util_findDict(&dict, "4") == &d);
    unit_ASSERT("fake key is not found", util_findDict(&dict, "junk") == 0);
    util_freeDict(&dict, 0);
}

static char const *runTests() {
    unit_RUN(testWhitespace);
    unit_RUN(testHash);
    unit_RUN(testDict);
    unit_RUN(testTinyDict);
    return 0;
}

int main(int argc, char const **argv) {
    char const *result = runTests();
    if (result) printf("FAILURE: %s\n", result);
    else printf("SUCCESS\n");
    printf("%d tests executed\n", unit_testsRun);
}
