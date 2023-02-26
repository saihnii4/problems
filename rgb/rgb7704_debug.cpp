#include <stdio.h>
#include <string.h>

// 
// -1
// 1
// 1
// 2
// 4
// 3
// -1
//
// 1,1,4   -1, 2, 3, -1

int main() {
    int T;
    scanf("%d", &T);

    int arr[T];
    int group = 0;

    for (int i = 0; i < T; i++) scanf("%d", &arr[i]);
    int g_ = 0;

    for (int i = 1; i <= T; i++) if (((g_ & (1 << (i-1))) == 0)) {
        int bruh[T];
        int l = 0;
        int d = 0;
        int g = 0;

        for (int j = 0; j < T; j++) if (
            i != arr[j] &&
            (g & (1 << arr[j])) == 0 &&
            (g_ & (1 << j)) == 0 &&
            arr[i-1] != j+1 &&
            (d & (1 << j)) == 0
        ) {
            g |= (1 << j) << 1;
            g_ |= (1 << j);
            d |= (1 << arr[j]) >> 1;
            bruh[l] = arr[j];
            ++l;
        }

        for (int i = 0; i < l; i++) {
            if (bruh[i]) printf("%d\n", bruh[i]);
        }
        ++group;
    }

    printf("%d\n", group);

    return 0;
}
