#include <stdio.h>
#include <ctype.h>

#define MAXLEN 10000

int TakeInput(char str[], int limit);
void Expand(char s1[], char s2[]);

int main() {
  char s1[MAXLEN];
  char s2[MAXLEN];

  TakeInput(s1, MAXLEN);
  Expand(s1, s2);
  printf("%s", s2);

  return 0;
}

/**
 * Takes a string input and writes the result to given array.
 *
 * @param str Array to write to.
 * @param limit How man input chars will be taken.
 * @returns Length of written input.
*/
int TakeInput(char str[], int limit) {
  int c, i = 0;

  while (i < limit - 1 && (c = getchar()) != EOF) {
    str[i++] = c;
  }
  str[i] = "\0";

  return i;
}

/**
 * Expands shorthand notations like a-z in the string `s1` into the equivalent
 * complete list `abc...xyz` in `s2`.
 *
 * Allows letter of either case and digits. Prepared to handle cases like
 * `a-b-c` and `a-x0-9` and `-a-z`. Arranges that a leading or trailing `-` is
 * taken literally.
*/
void Expand(char s1[], char s2[]) {
  int i, j = 0;

  // iterate until MAXLEN limit or the end of s1
  // `i` signifies index of s1 array, `j` index of s2 array
  for (i = 0; i < MAXLEN - 1 && j < MAXLEN - 1 && s1[i] != EOF; i++) {

    // if an alphanumeric range is encountered, like 0-9 or a-z
    if (isalnum(s1[i]) && s1[i+1] == '-' && s1[i] < s1[i+2]) {

      do {
        int k;

        // iterate through the difference of two numbers (or character's
        // values) in the range
        for (k = 0; k <= (s1[i+2] - s1[i]); k++) {
          int tmp = s1[i] + k;

          if (s2[j-1] != tmp && (isdigit(tmp) || isalpha(tmp))) {
            s2[j] = tmp;
            j++;
          }
        }

        i += 2;
      // do the same check to ensure whether to continue the same work with
      // the next range. I think it can be refactored for sure.
      } while (isalnum(s1[i]) && s1[i+1] == '-' && s1[i] < s1[i+2]);

    } else {
      // for all other cases, just assign a symbol to it's place
      s2[j] = s1[i];
      j++;
    }
  }

  s2[j] = '\0';
}
