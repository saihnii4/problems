#include <stdio.h>

int main() {
    int arr[5] = {8, 1, 2, 3, 0};
    int a = 0, b = 9;
    int m = 0;

    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        m |= (1 << arr[i]);
    }

    for (int i = a; i < (b+1); i++) {
        if (m & (1 << i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
