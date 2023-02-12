#include <stdio.h>

int main() {
    int T = 9;
    int arr[4] = {1, 2, 3, 4};
    int bit = 0;
    bool exist = false;

    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        bit |= (1 << arr[i]);
    }

    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        if (bit & (1 << (T-arr[i]))) {
            exist = true;
            break;
        }
    }

    printf("%d\n", exist);
    return 0;
}