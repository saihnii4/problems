#include <stdio.h>

int main() {
    int S, N;
    scanf("%d %d", &S, &N);

    // (a)
    printf("%d\n", S & (N - 1));

}
