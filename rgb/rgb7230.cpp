#include <stdio.h>
#include <math.h>

int main() {
    double x;
    int n;
    scanf("%lf %d", &x, &n);
    double sum = 0;

    for (int i = 1; i <= n; i++) sum += sin(pow(x, i));

    printf("%.3lf\n", sum);

}
