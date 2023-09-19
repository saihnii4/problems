#include <iostream>
#include <utility>
#include <string>

using namespace std;

string op;
int n, m, a, b, p[200001];
pair<int, int> q[200001];

void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x == y) return;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        q[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        cin >> op >> a;       

        if (op == "join") {
            cin >> b;
        } else if (op == "add") {
            cin >> b;

        } else {

        }
    }
}
