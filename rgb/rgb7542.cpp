#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        for (int j = i*N; j > (i-1)*N; j--) {
            printf("%d", j);
            if (j != N*(i-1)-1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
