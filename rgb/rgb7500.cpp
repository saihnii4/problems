#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (t>0) count += t;
    }
    printf("%d\n", count);
}
