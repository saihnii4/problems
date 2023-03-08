#include <stdio.h>
#include <math.h>

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);

    double c, d, e, f;
    scanf("%lf %lf %lf %lf", &c, &d, &e, &f);

    double g, h, i, j, k, l;
    scanf("%lf %lf %lf %lf %lf %lf", &g, &h, &i, &j, &k, &l);

    printf("%.3lf\n", abs(a-b));
    printf("%.3lf\n", pow(pow(abs(e-c), 2) + pow(abs(f-d), 2), 0.5));
    printf("%.3lf\n", pow(pow(abs(g-j), 2) + pow(abs(h-k), 2) + pow(abs(i-l), 2), 0.5));
    return 0;
}
