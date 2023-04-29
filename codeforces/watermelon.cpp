#include <stdio.h>

int n;

int main() {
    scanf("%d", &n);
    if ((n & 1) != 0 || n < 3) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    return 0;
}