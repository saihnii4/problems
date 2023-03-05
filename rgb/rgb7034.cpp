#include <stdio.h>
#include <math.h>

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%.2lf %.2lf\n", (a+b)/2, pow(a*b, 0.5));
}
