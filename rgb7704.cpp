#include <stdio.h>
#include <string.h>

// i don't quite understand how the example works

int main() {
    int T;
    scanf("%d", &T);

    int arr[T];
    int group = 0;

    for (int i = 0; i < T; i++) scanf("%d", &arr[i]);
    int g_ = 0;

    for (int i = 1; i <= T; i++) if (((g_ & (1 << (i-1))) == 0)) {
        // d is in charge of verifying that the cursor is not on a value equal to the root
        int d = 0, g = 0;

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
        }

        ++group;
    }

    printf("%d\n", group);

    return 0;
}
