#include <stdio.h>
#include <math.h>

int sum(int* num) {
    if (*num < 10) return (*num);

    int copy = *num;
    int digits = 0;

    while ((copy / 10) >= 0.1) {
        ++digits;
        copy /= 10;
    }

    int r = 0;

    for (int i = digits; i >= 0; i--) {
        int digit = (int)(*num / pow(10,i)) % 10;
        printf("%d\n", digit);
        r+=digit;
    }

    printf("%d\n", r);

    return sum(&r);
}

int main() {
    int N = -1;
    while (!false) {
        scanf("%d", &N);
        if (N == 0) break;
        printf("%d\n", sum(&N));
    }

    return 0;
}
