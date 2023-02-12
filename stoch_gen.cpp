#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <cmath>

int main() {
    int N;
    scanf("%d", &N);

    int stoch[N][N];

    for (int i = 0; i < N; i++)
        memset(stoch[i], 0, N*sizeof(int));

    int T = pow(2, N)-1;
    int n = ceil(cbrt(T));

    printf("%d\n", n);

    
}
