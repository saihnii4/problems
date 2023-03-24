#include <stdio.h>
#include <math.h>

int main() {
    long long T;
    scanf("%lld", &T);

    long long a[T];

    if (T == 1) printf("1\n");
    else if (T == 4) printf("2 4 1 3\n");
    else if (T <= 3) printf("NO SOLUTION\n");
    else {
        for (long long j = T; j > 0; j -= 2) {
            a[(T - j)/2] = j;
            printf("%lld", j);
            printf(" ");
        }

        for (long long i = 0; i <= (int)ceil((T-1)/2); i++) {
            if (a[i] - 1 > 0) {
                printf("%lld", a[i] - 1);
            }
            if (i != T - 1) printf(" ");
        }

        printf("\n");
    }

    return 0;
}
