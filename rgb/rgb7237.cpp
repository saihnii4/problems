#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    double sum = 0;

    for (int i = 0; i< n; i++) {
        double t;
        scanf("%lf", &t);
        sum += t;
    }

    printf("%.2lf\n", sum / n);
}
