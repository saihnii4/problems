#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", (int)(n*(n+1)*(2*n+1)/2 + n*(n+1) + n*n*(n+1)*(n+1)/4));
}
