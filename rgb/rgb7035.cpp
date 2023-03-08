#include <stdio.h>

#define PI 3.141592

int main() {
    double a;
    scanf("%lf", &a);

    printf("%.1lf %.1lf\n", PI*(a*a), 2*PI*a);
}
