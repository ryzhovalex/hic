#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>

void HelloWorld() {
  printf("Hello, world!\n");

  // This block returns Unknown escape sequence error
  // printf("Now i have some magic operators here: \c, wow!");
}

/**
 * Prints Fahrenheit-Celsius table.
 *
 * For fahr = 0, 20, ..., 300; floating-point version
 *
 * @see PrintFahrenheitCelsiusTable for inverted analog
*/
void PrintFahrenheitCelsiusTable() {
  float fahr, celsius;
  int lower, upper, step;

  // Go from lower to upper limit making conversion print each step
  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;

  // Heading
  printf("Fahrenheit-Celsius table\n");
  printf("========================\n");
  printf("Fahrenheit\t | \tCelsius\n");
  printf("----------\t | \t-------\n");

  while (fahr <= upper) {
    // Conversion to celsius formula implementation
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("\t%3.0f\t | \t%6.2f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

/**
 * Prints Celsius-Fahrenheit table.
 *
 * For celsius = 0, 20, ..., 300
 *
 * @see PrintFahrenheitCelsiusTable for inverted analog
*/
void PrintCelsiusFahrenheitTable() {
  float fahr, celsius;
  int lower, upper, step;

  // Go from lower to upper limit making conversion print each step
  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;

  // Heading
  printf("Celsius-Fahrenheit table\n");
  printf("========================\n");
  printf("Celsius\t | \tFahrenheit\n");
  printf("----------\t | \t-------\n");

  while (celsius <= upper) {
    // Conversion to celsius formula implementation
    fahr = ((9.0 * celsius) / 5.0) + 32.0;
    printf("\t%3.0f\t | \t%6.2f\n", celsius, fahr);
    celsius = celsius + step;
  }
}

/**
 * Prints Fahrenheit-Celsius table in reverse order.
*/
void PrintFahrenheitCelsiusTableReversed() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = upper;

  // Heading
  printf("Fahrenheit-Celsius table\n");
  printf("========================\n");
  printf("Fahrenheit\t | \tCelsius\n");
  printf("----------\t | \t-------\n");

  while (fahr >= lower) {
    // Conversion to celsius formula implementation
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("\t%3.0f\t | \t%6.2f\n", fahr, celsius);
    fahr = fahr - step;
  }
}

/**
 *
 * Exercise 2.1
 *
 * Program to print maximum, minimum limits of char, int, long using
 * calculation
 *
 * The logic used is
 * ~0 will give bits in 1s.
 * (unsigned <type>) will cast it unsigned.
 * >> 1 right shifts 1 bit to remove the sign bit.
 * (<type>) casting it the required type again
 *
 * @see https://www.learntosolveit.com/cprogramming/ex_2.1_cal_limits
 *
*/
void CountTheRanges() {
    printf("Ranges of various floating-point types through calculation:\n");

    printf("Minimum Signed Char %d\n",-(char)((unsigned char) ~0 >> 1) - 1);
    printf("Maximum Signed Char %d\n",(char) ((unsigned char) ~0 >> 1));

    printf("Minimum Signed Short %d\n",-(short)((unsigned short)~0 >>1) -1);
    printf("Maximum Signed Short %d\n",(short)((unsigned short)~0 >> 1));

    printf("Minimum Signed Int %d\n",-(int)((unsigned int)~0 >> 1) -1);
    printf("Maximum Signed Int %d\n",(int)((unsigned int)~0 >> 1));

    printf("Minimum Signed Long %ld\n",-(long)((unsigned long)~0 >>1) -1);
    printf("Maximum signed Long %ld\n",(long)((unsigned long)~0 >> 1));

    /* Unsigned Maximum Values */
    printf("Maximum Unsigned Char %d\n",(unsigned char)~0);
    printf("Maximum Unsigned Short %d\n",(unsigned short)~0);
    printf("Maximum Unsigned Int %u\n",(unsigned int)~0);
    printf("Maximum Unsigned Long %lu\n\n",(unsigned long)~0);

    printf("Ranges of various floating-point types from standard headers:\n");
    printf("Minimum Signed Char %d\n", SCHAR_MIN);
    printf("Maximum Signed Char %d\n", SCHAR_MAX);

    printf("Minimum Signed Short %d\n", SHRT_MIN);
    printf("Maximum Signed Short %d\n", SHRT_MAX);

    printf("Minimum Signed Int %d\n", INT_MIN);
    printf("Maximum Signed Int %d\n", INT_MAX);

    printf("Minimum Signed Long %ld\n", LONG_MIN);
    printf("Maximum signed Long %ld\n", LONG_MAX);

    /* Unsigned Maximum Values */
    printf("Maximum Unsigned Char %d\n", UCHAR_MAX);
    printf("Maximum Unsigned Short %d\n", USHRT_MAX);
    printf("Maximum Unsigned Int %u\n", UINT_MAX);
    printf("Maximum Unsigned Long %lu\n", ULONG_MAX);
}

void CopyInputToOutput() {
  int c = getchar();

  while (c != EOF) {
    putchar(c);
    c = getchar();
  }

  // In UNIX message appears only after Ctrl+D combination
  printf("EOF detected");
}

/**
 * Verify that the expression getchar() != EOF is 0 or 1
*/
void VerifyEofValue() {
    int c;

    while ((c = getchar()) != EOF) {
        if (!isspace(c)) {
          printf("getchar() != EOF ? %d\n", c != EOF);
          printf("Your input: %c\n", c);
        } else {
          printf("Whitespace occured\n");
        }
    }

    printf("\ngetchar() != EOF ? %d\n", c != EOF);
    if (c == EOF) {
      printf("EOF occured");
    }
}

void CountInputLines() {
  int c, lines_amount;

  // After EOF occured, counting is over and amount is calculated
  lines_amount = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      lines_amount++;
    }
  }

  printf("Amount of lines inputted: %d\n", lines_amount);
}

/**
 * Counts whitespaces from given input until EOF.
*/
void CountWhitespaces() {
  int c;
  int whitespaces_amount = 0;

  printf("Input some text:\n");
  while ((c = getchar()) != EOF) {
    if (isspace(c)) {
      whitespaces_amount++;
    }
  }

  printf("\nAmount of whitespaces inputted: %d\n", whitespaces_amount);
}

/**
 * Append given char to given string pointer.
 *
 * @see https://stackoverflow.com/questions/10279718/append-char-to-string-in-c
 * @return String with char appended
*/
char* AppendCharToStr(char* s, char c) {
  size_t len = strlen(s);

  // Allocate one more byte for a new char, and one for trailing zero,
  // but i don't understand why i need to allocate a new byte for trailing zero
  // since i already had one in original string.
  char* s2 = malloc(len + 1 + 1);

  // Finally change the last two bytes in the new buffer to add the character
  // and trailing zero
  strcpy(s2, s);
  s2[len] = c;
  s2[len + 1] = '\0';

  return s2;
}

/**
 * Copy input to output, replacing each string of one or more blanks by a
 * single blank.
*/
void CopyInputToOutputTruncatingRedundantBlanks() {
  int c;
  char* res = "";
  bool isPrevBlank = false;

  printf("Input some text:\n");

  // Add the characters one by one to result string. Yeah, i know nothing at
  // this point about memory optimizations, so i do it for all text inputted.
  // Maybe, it's slightly better to do it line-by-line.
  while ((c = getchar()) != EOF) {
    // Don't add several blanks in the row
    if (!isPrevBlank || !isspace(c)) {
      res = AppendCharToStr(res, c);
    }

    // Make decision for next chars according to the fact of receiving blank
    // character
    isPrevBlank = isspace(c) > 0;
  }

  printf("Result: %s\n", res);

  // I'm not sure if freeing memory here is required
  free(res);
}

/**
 * Copy input to output, replacing each string of one or more blanks by a
 * single blank.
 *
 * This is version 2 using putchar() which is maybe better solution than
 * playing with memory allocation.
 *
 * Also this version prints output line-by-line, instead of full text inputted.
*/
void CopyInputToOutputTruncatingRedundantBlanksV2() {
  int c;
  bool isPrevBlank = false;
  bool has_to_show_output_message = true;

  printf("Input:\n");
  while ((c = getchar()) != EOF) {
    if (has_to_show_output_message) {
      printf("-------\n");
      printf("Output:\n");
      has_to_show_output_message = false;
    }

    if (!isPrevBlank || !isspace(c)) {
      if (isspace(c)) {
        if (c == '\n') {
          // Preserve end of line char since we're reading line-by-line and
          // want to put user's cursor in the right place after hitting enter
          putchar('\n');

          // And after this newline, messages should be duplicated
          printf("\n");
          printf("======\n");
          printf("Input:\n");
          // Next iteration output message should be shown, since a newline
          // occured
          has_to_show_output_message = true; } else {
          // Put single space instead of tabulations etc.
          putchar(' ');
        }
      } else {
        putchar(c);
      }
    }

    isPrevBlank = isspace(c) > 0;
  }
}

int main() {
  return 0;
}
