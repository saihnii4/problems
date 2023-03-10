#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    float prod = 1.0f;

    for (double i = 1; i <= n; i++) {
        prod = prod * (1 + (1/(i*i)));
    }

    printf("%.3lf\n", prod);
}
