#include <stdio.h>
#include <iostream>
#include <cmath>

int main() {
    int H = -1, U, D;
    float F;

    while (H != 0) {
        scanf("%d %d %d %f", &H, &U, &D, &F);

        F /= 100;

        int day = 0;
        float a_n = ;

        while (a_n >= 0) {
            day++;
            a_n += (day)*(U*pow((1-F), day) - D);
            if (a_n >= H) break;
        }

        if (a_n <= 0) printf("failure on day %d\n", day);
        else printf("success on day %d\n", day);
    }

    return 0;
}