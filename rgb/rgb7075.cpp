#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a = (int)(n*(n+1)/2);

    printf("%d\n", a*a);
}
