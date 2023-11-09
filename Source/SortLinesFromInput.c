// TODO(ryzhovalex): not working, don't know why yet

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "SortLinesFromInput.h"

#define MaxLines 5000
#define MaxLen 1000

int _ReadLines(char* p_lines[], int linesNo);
void _WriteLines(char* p_lines[], int linesNo);
void _QuickSort(char* p_lines[], int left, int right);
void _Swap_QuickSort(char* v[], int i, int j);
int _GetLine(char*, int);

int main()
{
    SortLinesFromInput();
}

/**
 * Sorts input lines.
*/
int SortLinesFromInput()
{
    // say that p_lines is an array of MaxLines elements, each element of
    // which is a pointer to a char. That is p_line[i] is a char pointer, and
    // *p_line[i] is the character it points to, i.e the first character of
    // the i-th saved text line.
    //
    // Since p_line is itself the name of an array, it can be in turn treated
    // as a pointer.
    char* p_lines[MaxLines];
    int linesNo;

    if ((linesNo = _ReadLines(p_lines, MaxLines) >= 0))
    {
        _QuickSort(p_lines, 0, linesNo - 1);
        _WriteLines(p_lines, linesNo);
        return 0;
    }

    printf("ERROR: input too big to sort\n");
    return 1;
}

int _ReadLines(char* p_lines[], int maxlines)
{
    int len, linesNo;
    char* p;
    char lines[MaxLen];

    linesNo = 0;
    while ((len = _GetLine(lines, MaxLen)) > 0)
    {
        if (linesNo >= maxlines || (p = malloc(len)) == NULL)
        {
            return -1;
        }

        // delete newline
        lines[len-1] = '\0';
        strcpy(p, lines);
        p_lines[linesNo++] = p;
    }

    return linesNo;
}

void _WriteLines(char* p_lines[], int linesNo)
{
    for (int i = 0; i < linesNo; i++)
    {
        printf("%s\n", p_lines[i]);
    }
}

void _QuickSort(char* v[], int left, int right)
{
    // do nothing if array contains fewer than two elements
    if (left >= right)
    {
        return;
    }

    _Swap_QuickSort(v, left, (left + right) / 2);
    int last = left;

    for (int i = left + 1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0)
        {
            _Swap_QuickSort(v, ++last, i);
        }
    }

    _Swap_QuickSort(v, left, last);
    _QuickSort(v, left, last-1);
    _QuickSort(v, last+1, right);
}

void _Swap_QuickSort(char* v[], int i, int j)
{
    // temp should be also a char pointer in order to inter-copy it with `v`
    char* temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/**
 * Reads a line into s, return length
*/
int _GetLine(char* s, int limit)
{
    int i, c;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}
