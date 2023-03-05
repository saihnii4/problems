#include <iostream>
#include <math.h>

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);

    printf("%.1lf\n", pow(pow(a, 2) + pow(b, 2), 0.5));
    return 0;
}
