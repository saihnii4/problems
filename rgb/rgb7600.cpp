#include <stdio.h>

int memo[88];

int fib(int n) {
    if (n <= 1) return n;
    if (memo[n]) return memo[n];

    int a = fib(n-1) + fib(n-2);
    memo[n] = a;
    return a;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", fib(n+1));
}
