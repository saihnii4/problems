#include <stdio.h>
#include <math.h>

int i = 0;

double f(int n) {
    if (i == n) return 0;
    ++i;
    double a = pow(2 + f(n), 0.5);
    return a;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%.9lf\n", f(n));
}
