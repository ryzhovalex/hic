#include <stdio.h>
#include <string.h>
#include "Utils.h"
#include "CharPointers.h"

void TestCopyStr();
void TestCompareStr();
void TestConcatenateStr();
void TestIsEndingWith();
void TestCopyNStr();
void TestConcatenateNStr();
void TestCompareNStr();

int main()
{
    TestCopyNStr();
    TestCompareNStr();
    return 0;
}

void TestCopyNStr()
{
    char s1[] = "hello";
    char s2[5];

    CopyNStr(s1, s2, 3);

    char errmsg[] = "s2 should be equal to \"hel\", got ";
    strcat(errmsg, s2);
    Assert(
        strcmp(s2, "hel") == 0,
        errmsg
    );
}

void TestConcatenateNStr()
{
    char s[100] = "This is the first string";
    char *t = ", this second string!";
    size_t nr_chars = 5;

    ConcatenateNStr(s, t, nr_chars);

    puts(s);

    return;

    char s1[100] = "hel";
    char* s2 = "los";

    ConcatenateNStr(s1, s2, 1);

    char errmsg[] = "s1 should be equal to \"hell\", got ";
    strcat(errmsg, s1);
    Assert(
        strcmp(s1, "hell") == 0,
        errmsg
    );
}

void TestCompareNStr()
{
    char s1[] = "hello";
    char s2[] = "hella";

    int result = CompareNStr(s1, s2, 4);

    char errmsg[] = "result should be equal to 0";
    Assert(
        result == 0,
        errmsg
    );
}

void TestIsEndingWith()
{
    char target[] = "boomkin";
    char endsStr_1[] = "kin";
    char endsStr_2[] = "rap";

    printf("%d\n", IsEndingWith(target, endsStr_1));
    printf("%d\n", IsEndingWith(target, endsStr_2));
}

void TestCopyStr()
{
    char f[] = "hello";
    char t[5];

    CopyStr3(f, t);
    printf(t);
    printf("\n");

    CopyStr("hello", f);
    t[0] = '\0';
    CopyStr2(f, t);
    printf(t);
    printf("\n");
}

void TestCompareStr()
{
    char s1[] = "hello";
    char s2[] = "hella";

    int result = CompareStr(s1, s2);

    printf("%d", result);
}

void TestConcatenateStr()
{
    char target[] = "hello";
    char concatenateStr[] = ", world!";

    ConcatenateStr(target, concatenateStr);

    printf(target);
}

/**
 * Copies string from `from` to `to`.
 *
 * Note that this operation clears `from` array.
*/
void CopyStr(char* from, char* to)
{
    int i = 0;

    // it would be nice just to say `t = f`, but this copies the pointer, not
    // the characters. To copy the characters, we need a loop.
    while ((to[i] = from[i]) != '\0')
    {
        i++;
    }
}

/**
 * Copies string from `from` to `to`.
 *
 * Note that this operation clears `from` array.
*/
void CopyStr2(char* from, char* to)
{
    // pointer arithmetic is involved: we increment each pointer by 1 byte,
    // since the compiler knows that these are char pointers
    while ((*to = *from) != '\0')
    {
        from++;
        to++;
    }
}

/**
 * Copies string from `from` to `to`.
 *
 * Note that this operation clears `from` array.
*/
void CopyStr3(char* from, char* to)
{
    while ((*to++ = *from++) != '\0');
}

/**
 * Compares the first occured different characters in two strings.
 *
 * @returns <0 if s1<s2, =0 if s1==s2, >0 if s1>s2
*/
int CompareStr(char* s1, char* s2)
{
    for (; *s1 == *s2; s1++, s2++)
    {
        if (*s1 == '\0')
        {
            return 0;
        }
    }

    return *s1 - *s2;
}

/**
 * Concatenates string to the end of target.
 *
 * Target must be big enough.
*/
void ConcatenateStr(char* target, char* concatenateStr)
{
    // set target to it's end
    // use pre-increment since we do not want to access wrong memory zones
    while (*++target != '\0');

    while ((*target++ = *concatenateStr++) != '\0');
}


int IsEndingWith(char* target, char* endsStr)
{
    size_t targetLen = strlen(target);
    size_t endsStrLen = strlen(endsStr);

    // move pointers to the end of strings
    target += targetLen;
    endsStr += endsStrLen;

    // compare from the end
    while (endsStrLen && (*--target == *--endsStr))
    {
        --endsStrLen;
    }

    if (endsStrLen > 0)
    {
        // not all values from the ends str are matched
        return 0;
    }

    return 1;
}

void CopyNStr(char* from, char* to, int n)
{
    int i = 0;

    while (i < n && (*to = *from) != '\0')
    {
        from++;
        to++;
        i++;
    }
}

int CompareNStr(char* s1, char* s2, int n)
{
    for (int i = 1; i < n && *s1 == *s2; s1++, s2++)
    {
        if (*s1 == '\0')
        {
            return 0;
        }
        i++;
    }

    return *s1 - *s2;
}

void ConcatenateNStr(char* target, char* concatenateStr, size_t n)
{
    // TODO(ryzhovalex): does strange stuff, i.e. is not working!
    size_t targetLen = strlen(target);
    *target += targetLen;

    while ((*target++ = *concatenateStr++) != '\0' && n--);
}
