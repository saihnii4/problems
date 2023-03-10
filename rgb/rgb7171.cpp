#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &d);

    int x, y, z;

    z = ((d - 1) % c) + 1;
    y = ((int)(d / c)  % b) + 1;
    x = ((int)(d / c) / a) + 1;
    printf("%d %d %d\n", x, y, z);
}
