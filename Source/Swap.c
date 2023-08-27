#include <stdio.h>

/**
 * Swaps x with y.
*/
#define Swap(t, x, y) { \
    t temp; \
    temp = x; \
    x = y; \
    y = temp; \
}


int main() {
    int x = 2;
    int y = 3;

    Swap(int, x, y);

    printf("x=<%d> y=<%d>", x, y);

    return 0;
}
