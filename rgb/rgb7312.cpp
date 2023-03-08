#include <stdio.h>

int main() {
    int n;
    int k = 2;
    scanf("%d", &n);

    while (n % k == 0 && n > 1) {
        n /= k;
        ++k;
    }

    if (n == 1) printf("%d\n", k-1);
    else printf("No\n");

    return 0;
}
