#include "tst/unit.h"
#include "src/util.h"

static char const *testWhitespace() {
    unit_ASSERT("h is not whitespace", !util_whitespace('h'));
    unit_ASSERT("5 is not whitespace", !util_whitespace('5'));
    unit_ASSERT("' ' is whitespace", util_whitespace(' '));
    unit_ASSERT("\\n is whitespace", util_whitespace('\n'));
    unit_ASSERT("\\t is whitespace", util_whitespace('\t'));
}



int main(int argc, char const **argv) {
    unit_RUN(testWhitespace);
}
