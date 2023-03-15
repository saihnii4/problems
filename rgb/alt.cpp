#include <stdio.h>

int main() {
    int N;
    scanf("%d\n", &N);

    int arr[N];

    int S = 0;

    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < N; i++) {
        if (arr[i] < 0) S = 0;
        else S += arr[i];
    }

    printf("%d\n", S);
     
    return 0;
}
