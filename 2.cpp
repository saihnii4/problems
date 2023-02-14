#include <stdio.h>
#include <string.h>

int main() {
    int T = 0;
    scanf("%d", &T);

    int data[T];
    int w[200000];

    for (int i = 0; i < T; i++) {
        int a, b; // a - home, b - visitor
        scanf("%d %d", &a, &b);
        w[a]++;
        data[i] = b;
    }

    for (int i = 0; i < T; i++) {
        int X, Y;
        X = Y = T-1;
        X += w[data[i]];
        Y -= w[data[i]];

        printf("%d %d\n", X, Y);
    }

    return 0;
}
