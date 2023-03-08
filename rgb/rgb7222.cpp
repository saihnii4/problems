#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 9; i >= n; i--) {
        printf("%d\n", i);
    }

    return 0;
}
