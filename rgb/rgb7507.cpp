#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int m, x;

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);

        if (i == 0) {
            m = t;
            x = 1;
        } else if (t > m) {
            m = t;
            x = i + 1;
        }
    }
    
    printf("%d %d\n", m, x);
}
