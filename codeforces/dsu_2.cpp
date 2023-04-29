#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string op;
int n, quer, a, b, p[300001], q[300001], r[300001], d[300001];

int find(int i) {
    if (i == p[i]) return i;
    int x = find(p[i]);
    p[i] = x;
    return x;
}

void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x == y) return;
    q[x] = q[y] = max(q[x], q[y]);
    r[x] = r[y] = min(r[x], r[y]);
    d[x] = d[y] = d[x] + d[y];
    p[x] = y;
}

int main() {
    scanf("%d %d", &n, &quer);

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        q[i] = i;
        r[i] = i;
        d[i] = 1;
    }

    for (int i = 0; i < quer; i++) {
        cin >> op >> a;

        if (op == "union") {
            cin >> b;
            merge(a, b);
        } else {
            int root = find(a);
            cout << r[root] << " " << q[root] << " " << d[root] << endl;
        }
    }
}