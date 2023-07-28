#include <stdio.h>

void Adder(int n);

void main() {
    Adder(1);
    Adder(2);
    Adder(3);
}

void Adder(int n) {
    // seems like initialized only once, which is expected
    static int value = 0;

    value += n;
}
