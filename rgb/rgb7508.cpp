#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int m, x = 0;

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);

        if (i == 0){
            x = 1;
            m = t;
        } else if (t > m) {
            m = t;
            x = 0;
        }

        if (i != 0 && t == m) ++x;
    }
    
    printf("%d %d\n", m, x);
}
