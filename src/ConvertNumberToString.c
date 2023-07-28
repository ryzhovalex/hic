#include <stdio.h>
#include <string.h>

#define MAXLEN 10000

void ConvertNumberToString(int n, char s[]);
void Reverse(char s1[]);

void main() {
    char s[MAXLEN];

    ConvertNumberToString(12345, s);

    printf("%s", s);
}

/**
 * Converts a number to a character string (the inverse of `atoi` function).
*/
void ConvertNumberToString(int n, char s[]) {
    int i, sign;

    // make n positive in case if it's negative
    if ((sign = n) < 0) {
        n = -n;
    }

    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    // return sign in form of hyphen
    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';
    Reverse(s);
}

/**
 * Reverses a string.
 *
 * @param s1 String to reverse.
*/
void Reverse(char s1[]) {
    int iright;
    int slen = strlen(s1);
    char tmp;

    for (int i = 0; i < slen - 1; i++) {
        tmp = s1[i];
        iright = slen - 1 - i;

        if (i == iright) {
            break;
        } else {
            s1[i] = s1[iright];
            s1[iright] = tmp;
        }
    }
}
