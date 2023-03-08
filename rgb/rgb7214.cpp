#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += i*(n-i+1);
    }

    printf("%d\n", sum);
}
