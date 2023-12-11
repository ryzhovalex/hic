#include <stdio.h>

int main()
{
    return 0;
}

struct Point
{
    int x;
    int y;
};

struct Rect
{
    struct Point point1;
    struct Point point2;
};

struct Point CreatePoint(int x, int y)
{
    struct Point p = { x, y };
    return p;
}

struct Rect CreateRect(struct Point p1, struct Point p2)
{
    struct Rect r = { p1, p2 };
    return r;
}
