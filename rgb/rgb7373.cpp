#include <stdio.h>

int main() {
    int n, c = 0;
    scanf("%d", &n);

    while (n != 1) {
        if ((n & 1) == 0) {
            n /= 2;
        } else {
            n = 3*n + 1;
        }
        ++c;
    }

    printf("%d\n", c);
}
