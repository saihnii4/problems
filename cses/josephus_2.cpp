// TODO:

#include <stdio.h>
#include <queue>

using namespace std;

int n;
long long k, i = 1;

queue<int> q;

int main() {
    scanf("%d %lld", &n, &k);
    long long z = k;
    
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        z = (k % n);
        if (z == 0) z = 1;
        if (i % z == 0) {
            printf("%d ", q.front());
            q.pop();
            --n;
        } else {
            q.push(q.front());
            q.pop();
        }

        ++i;
    }

    printf("\n");
    return 0;
}
