#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) { 
        if ((i & 1) == 0) for (int j = 1; j <= N; j++) {
            printf("%d", N*i + j);
            if (j != N) printf(" ");
        } else for (int j = N*(i+1); j > N*i; j--) {
            printf("%d", j);
            if (j != N*(i-2)-1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
