#include <stdio.h>
#include "CharPointers.h"


int main()
{
    char f[] = "hello";
    char t[5];

    CopyStr(f, t);
    printf(t);
    printf("\n");

    CopyStr("hello", f);
    t[0] = '\0';
    CopyStr2(f, t);
    printf(t);
    printf("\n");

    return 0;
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
