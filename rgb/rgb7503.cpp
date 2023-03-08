#include <stdio.h>

int main() {
    int n, m = 0, e = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);

        if (t & 1 == 0) ++e;
        else ++m;
    }

    printf("%s\n", (m > e) ? "YES": "NO");
}

