#include <stdio.h>
#include <string.h>

int Assert(int statement, char* errmsg)
{
    if (statement == 0)
    {
        printf("AssertionError: %s\n", errmsg);
        return 0;
    }
    return 1;
}
