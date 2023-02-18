#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", N*i + j + 1);
            if (j != N-1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
