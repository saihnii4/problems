#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int r = 0;
    // meh code
    int l = 1;

    for (int i = 0; i < n; i++) {
        r += l*n;
        l *= 10;
    }

    printf("%d\n", r);
}
