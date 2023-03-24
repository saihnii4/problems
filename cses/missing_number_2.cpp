#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int b = 0;
    for (int i = 0; i < n - 1; i++) {
        int t;
        scanf("%d", &t);
        b ^= ((i + 1) ^ t);
    }

    b ^= n;

    printf("%d\n", b);
}
