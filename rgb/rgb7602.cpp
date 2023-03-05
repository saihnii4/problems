#include <stdio.h>

long long memo[99999];

// literally fibonacci
long long traverse(int n) {
    long long a = 0, b = 0, c = 0;
    if (memo[n]) return memo[n];
    if (n <= 1) return 1;

    a = traverse(n - 1);
    if (n >= 2) b = traverse(n - 2);
    if (n >= 3) c = traverse(n - 3);

    memo[n] = a + b + c;
    return memo[n];
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", traverse(n));
    return 0;
}
