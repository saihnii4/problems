#include <stdio.h>
#include <vector>

using namespace std;

vector<int> cycle;

int main() {
    int n;
    int i = 1;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        cycle.push_back(i);
    }

    while (cycle.size() != 0) {
        if (i >= cycle.size()) i %= cycle.size();
        printf("%d", cycle[i]);
        cycle.erase(cycle.begin() + i);
        i += 1;
        if (cycle.size() > 0) printf(" ");
    }

    printf("\n");

    return 0;
}
