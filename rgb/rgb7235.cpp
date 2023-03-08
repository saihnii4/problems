#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    double prod = 1;

    for (int i = 1; i <= n; i++) {
        prod *= (1 + (1/(i*i)));
    }

    printf("%.3lf\n", prod);
}
