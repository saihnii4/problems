#include <stdio.h>

int main() {
    int f, d, c;
    scanf("%d %d", &f, &d);
    scanf("%d", &c);

    printf("%d %d", ((int)((c-1) / d))+1, ((c-1) % d)+1);
}
