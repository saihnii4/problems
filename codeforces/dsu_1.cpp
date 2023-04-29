#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string op;
int n, q, p[100001], a, b;

int find(int i) {
    if ( p[i] == i ) 
        return i;
    int x = find(p[i]);
    p[i] = x;
    return x;
}

void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x == y) return;
    p[x] = y;
}

bool get(int a, int b) {
    int x = find(a);
    int y = find(b);
    return x == y;
}

int main() {
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++) {
        p[i + 1] = i + 1;
    }
    
    for (int i = 0; i < q; i++) {
        cin >> op >> a >> b;

        if (op == "union") {
            merge(a, b);
        } else {
            printf("%s\n", get(a, b) ? "YES" : "NO");
        }
    }

    return 0;
}
