#include <stdio.h>
#include <math.h>

int main() {
    long long n, m = 0;
    scanf("%lld", &n);

    int sum = 0;
    long long a = (long long)(n*(n+1)/2);

    for(int i = 0; i < n - 1; i++) {
        long long t;
        scanf("%lld", &t);
        sum += t;
    } 

    printf("%lld\n", a - sum);
}
