#include <stdio.h>
#include <math.h>

// TODO: BAD CODE! Doesn't consider sets of 3

int main() {
    long long T, max, sum = 0;
    scanf("%lld", &T);

    long long a[T];

    for (long long i = 0; i < T; i++) {
        scanf("%lld", &a[i]);
        if (i == 0) max = a[0];
        if (a[i] > max) max = a[i];
        sum += a[i];
    }

    long long diff = sum - 2*max;

    if (diff < 0) printf("%d\n", diff);
    else {
        long long j, b;
        for (long long i = 0; i < n; i++) {
            j = abs(max - a[i]*2);
            b = a[i];
        }
    }
}
