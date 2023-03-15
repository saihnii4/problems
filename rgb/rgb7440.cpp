#include <stdio.h>

int main() {
    char a;
    scanf("%c", &a);

    for (int i = 0; i <= 'Z' - a; i++) {
        for (int j = a; j <= a + i; j++) {
            printf("%c", j);
        }
        printf("\n");
    }
}
