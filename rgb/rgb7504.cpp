#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (i == 0) m = t;
        if (t > m) m = t;
    }

    printf("%d\n", m);
}
