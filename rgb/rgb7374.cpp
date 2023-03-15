#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    int a = (int)(pow(pow(10, n - 1), 0.5)), b = (int)(pow(pow(10, n), 0.5));

    for (int i = a; i <= b; i++) {
        printf("%d\n", i*i);
    }
    return 0;
}
