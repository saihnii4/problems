#include <stdio.h>

int main() {
    int n, m = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);

        if (t < 60) ++m;
    }

    printf("%d\n", m);
}
