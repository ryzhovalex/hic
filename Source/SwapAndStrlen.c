#include <stdio.h>

void TestIntro();
void TestSwap();
void Swap(int *, int *);
void TestStrlen();
int Strlen(char *s);


int main() {
    TestStrlen();
    return 0;
}

void TestIntro() {
    int x = 1, y = 2, z[10];

    // ip is a pointer to int ??
    int *ip, *iq;

    // ip now points to x
    ip = &x;

    y = *ip;
    // y = 1

    *ip = 0;
    // x = 0

    // ip now points to z[0], i.e. to the start of an array
    ip = &z[0];

    // copies ip pointer to iq, making iq point to whatever ip pointed to
    iq = ip;

    printf("%d, %d", ip, iq);
}

void TestSwap() {
    int a = 2, b = 3;

    Swap(&a, &b);

    printf("a=<%d>, b=<%d>", a, b);
}

void TestStrlen() {
    char a[5] = {'1', '2', '3', '4', '5'};
    char *pa = a;

    printf("%d\n", Strlen("hello, world"));
    printf("%d\n", Strlen(a));
    printf("%d\n", Strlen(pa));
}

void Swap(int *px, int *py) {
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

int Strlen(char *s) {
    int n;

    for (n = 0; *s != '\0'; s++) {
        n++;
    }

    return n;
}

int Strlen2(char *s) {
    // set p to start of s
    char *p = s;

    // iterate p until the null terminator
    while (*p != '\0') {
        p++;
    }

    // finally calculate how many characters we iterated, we don't use `+1`
    // here, since on the last instruction of `p++` we reached '\0', but
    // we don't consider null termination in the final length calculation
    //
    // so `p - s` gives number of characters advanced over, that is, the
    // string length
    return p - s;
}
