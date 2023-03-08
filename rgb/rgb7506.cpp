#include <stdio.h>

int main() {
    int t, c = 0;
    scanf("%d\n", &t);

    int d[t];

    for (int i = 0; i < t; i++) scanf("%d", &d[i]);

    int l;
    scanf("%d", &l);

    for (int i = 0; i < t; i++) if (d[i] == l) 
        ++c;

    printf("%d %d\n", l, c);
}
