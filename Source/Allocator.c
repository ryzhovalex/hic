/**
 * Allocator
 *
 * Rudimentary storage allocator.
*/

#include <stdio.h>

/**
 * Size of available space.
*/
#define AllocationSize 10000

/**
 * Storage for allocator.
*/
static char allocationBuffer[AllocationSize];

/**
 * Pointer to next free position for the allocation.
 *
 * Initialized to the start of the allocation buffer.
*/
static char *allocationFreePtr = allocationBuffer;

/**
 * Returns pointer to `n` characters.
*/
char *Allocate(int n)
{
    // check if n fits to free space available
    // allocationBuffer = [
    //      allocationBuffer[0], x1, x2, x3,
    //      allocationFreePtr, ..., AllocationSize
    // ]
    if (allocationBuffer + AllocationSize - allocationFreePtr >= n) {
        // free space for n positions - i.e. move free pointer further right
        allocationFreePtr += n;
        // return pointer to the start of freed up space
        return allocationFreePtr - n;
    }

    // else - not enough space
    //
    // `return NULL` is equivalent to `return 0`
    //
    // C guarantees that zero is never a valid address for data, so a return
    // value of zero can be used to signal an abnormal event, in this case,
    // an event of no space left
    return NULL;
}

/**
 * Free storage pointed to by `p`.
*/
void FreeAllocation(char *p) {
    // check if p in limits of the allocation buffer
    if (p >= allocationBuffer && p < allocationBuffer + AllocationSize) {
        // set free pointer to given address
        allocationFreePtr = p;
    }
}
