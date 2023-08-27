#include <stdio.h>
#include <string.h>

#define MAXLEN 10000

void ToString(int n, char s[]);
void Reverse(char s1[]);
int ToBaseString(
    int n,
    char s[],
    int base
);
void ToBinaryString(int n, char s[]);
void TestSimpleString();
void ToHexString(int n, char s[]);
int TestBaseString();

int main() {
    return TestBaseString();
}

void TestSimpleString() {
    char s1[MAXLEN];
    char s2[MAXLEN];

    ToString(12345, s1);
    ToString(-12345, s2);

    printf("%s\n", s1);
    printf("%s", s2);
}

int TestBaseString() {
    int retcode;
    char s1[MAXLEN];
    char s2[MAXLEN];

    retcode = ToBaseString(1234, s1, 2);
    if (retcode != 0) {
        return retcode;
    }

    retcode = ToBaseString(1234, s2, 16);
    if (retcode != 0) {
        return retcode;
    }

    printf("%s\n", s1);
    printf("%s\n", s2);

    return 0;
}

/**
 * Converts a number to a character string (the inverse of `atoi` function).
*/
void ToString(int n, char s[]) {
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
 * Converts the integer `n` into a base `b` representation of the string `s`.
 *
 * For example: if n = 12345, base = 2, then s = "11000000111001"
*/
int ToBaseString(
    int n,
    char s[],
    int base
) {
    if (base != 2 && base != 10 && base != 16) {
        return 1;
    }

    if (base == 2) {
        ToBinaryString(n, s);
    } else if (base == 10) {
        ToString(n, s);
    } else {
        ToHexString(n, s);
    }

    return 0;
}

/**
 * Converts integer to binary string.
*/
void ToBinaryString(int n, char s[]) {
    int i = 0;

    while (n > 0) {
        s[i++] = n % 2 + '0';
        n /= 2;
    }

    Reverse(s);
}

/**
 * Converts integer to hex string.
*/
void ToHexString(int n, char s[]) {
    int i = 0;
    int remainder;
    char finalSymbol;

    while (n > 0) {
        remainder = n % 16;

        switch (remainder) {
            case 10:
                finalSymbol = 'A';
                break;
            case 11:
                finalSymbol = 'B';
                break;
            case 12:
                finalSymbol = 'C';
                break;
            case 13:
                finalSymbol = 'D';
                break;
            case 14:
                finalSymbol = 'E';
                break;
            case 15:
                finalSymbol = 'F';
                break;
            default:
                finalSymbol = remainder + '0';
        }

        s[i++] = finalSymbol;
        n /= 16;
    }

    Reverse(s);
}

/**
 * Reverses a string.
 *
 * @param s1 string to reverse
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
