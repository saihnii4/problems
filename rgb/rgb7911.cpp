#include <stdio.h>
#include <math.h>
#include <algorithm>

// bruh moment
using namespace std;

int main() {
    int n, l;
    scanf("%d %d", &n, &l);

    int d[n], rope = 0;

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        d[i] = t;
        rope |= (1 << t);
    }

    printf("%d\n", rope);

    for (int i = 0; i < n; i++) {
        if (d[i] == 0 || d[i] == l) continue;

        int c1 = min(l-d[i], d[i]);
        int c2 = max(l-d[i], d[i]);
        int offset = c2 - c1;

        int right = rope >> (d[i]+1);
        int left = rope ^ (right << (d[i]+1)); // leading zeroes are ignored

        printf("%d %d %d\n", left, d[i],right);
        for (int i = 0; i < (int)(pow(2, d[i]+1)/left); i++) {

            right = right >> 1;
            offset -= 1;
        }

        printf("%d\n", offset);

        if (l-d[i] > d[i]) {
            right = right >> offset;
        } else if (l-d[i] < d[i]) {
            left = left >> offset;
        }

        if (right == left) {
            printf("YAY\n");
        }

        printf("%d %d %d\n", left, d[i],right);
    }
}

