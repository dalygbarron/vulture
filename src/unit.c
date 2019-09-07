#include "tst/unit.h"
#include <stdio.h>

static char const *runTests() {
    unit_RUN(testWhitespace);
}

int main(int argc, char const **argv) {
    char const *result = runTests();
    if (result) printf("FAILURE: %s\n", result);
    else printf("SUCCESS");
    printf("%d tests executed\n", unit_testsRun);
}
