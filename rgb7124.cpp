#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    if (N > 0) printf("%d\n", N);
    else {
        N = -N;
        int D = N % 100;
        printf("%d\n", D - N - (D % 10));
    }

    return 0;
}
