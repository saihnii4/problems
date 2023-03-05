#include <vector>
#include <algorithm>
#include <stdio.h>

int main() {
    int s, n;
    scanf("%d %d", &s, &n);

    std::vector<int> poss;
    std::vector<int> bon;


    for (int i = 0; i < n; i++) {
        int r, b;
        scanf("%d %d", &r, &b);
        poss.push_back(r);
        bon.push_back(b);
    }

    while (poss.size() > 0) {
        int change = 0;
        for (int i = 0; i < n; i++) if (poss[i] != -1 && s >= poss[i]) {
            s += bon[i];
            poss
            ++change;
        }

        if (change == 0) {
            printf("%d\n", s);
            printf("It ain't gonna work\n");
            break;
        }
    }

    return 0;
}
