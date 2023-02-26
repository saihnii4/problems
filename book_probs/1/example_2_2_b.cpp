#include <stdio.h>

int main() {
    int T;

    scanf("%d", &T);

    int arr[7] = {1, 2, 3, 4, 5, 0, 100000};
    bool exists;
    int m;

    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        m |= (1 << arr[i]);
    }

    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        if (m & (1 << (T-arr[i]))) {
            exists = true;
            break;
        }
    }

    printf("%d\n", exists);
    return 0;
}
