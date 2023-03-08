#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    while (n % 3 == 0)
        n /= 3;

    printf("%d\n", n);
}
