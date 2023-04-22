#include <stdio.h>
#include <set>

using namespace std;

set<int> s;

int n;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        s.insert(x);
    }

    printf("%d\n", n - s.size());
}
