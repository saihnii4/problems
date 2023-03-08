#include <stdio.h>

int main() {
    int arr[12] = {0, 2, 3, 4, 2, 8, 1, 2, 1, 4, 5, 6};
    int max = 0;
    int len = 0;

    // O(n)
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        if (len > max) max = len;

        if (i+1 == sizeof(arr)/sizeof(int)) break;

        if (arr[i] < arr[i+1])
            len++;
        else {
            len = 0;
        }
    }

    printf("%d\n", max+1);

    return 0;
}
