#include <stdio.h>

int main() {
    int a, b, steps = 0;
    scanf("%d %d", &a, &b);

    if (a > b) printf("%d\n", a-b);
    else {
        do {
            if (a > b) {
                steps += a-b;
                break;
            }

            if ((b & 1) == 0) {
                b/=2;
                steps++;
            } else {
                ++b;
                steps++;
            }
        } while (a != b);
        printf("%d\n", steps);
    }

    return 0;
}
