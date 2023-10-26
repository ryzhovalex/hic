#include <stdio.h>

int QuickSort(int a[], int left, int right);
void Swap(int a[], int i, int j);

int main() {
    int a[] = {55, 30, 2, 23, 89, 6, 8, 19, 41};
    int alen = sizeof(a) / sizeof(a[0]);
    int retcode = QuickSort(a, 0, alen-1);

    for (int i = 0; i < alen; i++) {
        printf("%d\n", a[i]);
    }

    return retcode;
}

int QuickSort(int a[], int left, int right) {
    int i, last;

    // stop if array contains fewer than two elements
    if (left >= right) {
        return 0;
    }

    // move partition element to a[0] (to the start)
    Swap(a, left, (left + right) / 2);

    // last points to last moved element which was less than the
    // partition element
    last = left;

    // iterate everything else excluding the partition element
    for (i = left + 1; i <= right; i++) {
        // compare with the partition element
        if (a[i] < a[left]) {
            // move the lesser element before the partition element
            Swap(a, ++last, i);
        }
    }

    Swap(a, left, last);

    // start the same operation with two resulted subsets, we know for sure
    // that every number of subset A (from left to last-1) is less than every
    // number of subset B
    QuickSort(a, left, last-1);
    QuickSort(a, last+1, right);

    return 0;
}

/**
 * Interchanges a[i] and a[j].
*/
void Swap(int a[], int i, int j) {
    int tmp;

    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
