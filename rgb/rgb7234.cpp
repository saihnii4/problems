#include <stdio.h>
#include <math.h>

int i = 0;

double f(int n) {
    if (i == n) return 0;
    ++i;
    double a = cos(i + f(n));
    return a;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%.3lf\n", f(n));
}
