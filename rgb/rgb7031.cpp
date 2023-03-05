#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double s = (a + b + c)/2;

    printf("%.2lf\n", pow(s*(s-a)*(s-b)*(s-c), 0.5));
    return 0;
}
