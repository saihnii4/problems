#include <stdio.h>
#include <iostream>

int main() {
    int b;
    scanf("%d", &b);

    int d[10];
    int a;
    std::cin.ignore();

    for (int i = 0; i < b; i++) std::cin >> d[i];

    for (int i = 0; i < b; i++) {
        for (int j = 0; j < b; j++) {
            printf("%d", d[(i+j)%b]);
            if (j != b - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
