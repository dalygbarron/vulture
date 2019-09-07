#ifndef UNIT_H
#define UNIT_H

#define unit_ASSERT(message, test) do {\
    if (!(test)) return message;\
} while (0)

#define unit_RUN(test) do {\
    char const *message = test();\
    unit_testsRun++;\
    if (message) return message;\
} while (0)

extern int unit_testsRun;

#endif
