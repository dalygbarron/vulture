#include "io.h"
#include <stdio.h>

int body(struct Context const *context) {
    io_flush(context, io_RED);
    io_frame(context);
    return 69;
}

int main(int argc, char const **argv) {
    printf("hello\n");
    int response = io_execute(body);
    printf("goodbye %d\n", response);
    return 0;
}
