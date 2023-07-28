#include <stdio.h>
#include <string.h>

#define MAXLEN 10000

void ConvertNumberToString(int n, char s[]);
void Reverse(char s1[]);

void main() {
    char s1[MAXLEN];
    char s2[MAXLEN];

    ConvertNumberToString(12345, s1);
    ConvertNumberToString(-12345, s2);

    printf("%s\n", s1);
    printf("%s", s2);
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
        // get the last digit of n and convert it to ASCII table number value
        // by adding '0'. It just a backwards operation of e.g. '9' - '0' = 9.
        s[i++] = n % 10 + '0';
    // n /= 10 would be treated as floor division, since n has an integer type
    // so for example if n = 123, then n / 10 = 12 (not 12.3 since int n
    // cannot hold floats by it's declared type)
    //
    // so every iteration the last number of n is deleted by n /= 10 operation
    } while ((n /= 10) > 0);

    // return sign in form of hyphen
    if (sign < 0) {
        s[i++] = '-';
    }

    // terminate the string
    s[i] = '\0';

    // since we've put all characters in reverse, we need to invert the
    // string to the desired state
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

        // if slen is even, the i will become larger than iright at the
        // meeting point, if slen is odd, they will be equal at the meeting
        // point
        if (i >= iright) {
            break;
        } else {
            s1[i] = s1[iright];
            s1[iright] = tmp;
        }
    }
}
