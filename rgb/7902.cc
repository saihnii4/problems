#include <bits/stdc++.h>
using namespace std;

long long btod(string s) {
    long long res = 0;
    for (int i = 0; i < s.size(); i++) {
        res = res * 2 + s[i] - '0';
    }
    return res;
}

bool check(long long a, string b) {
    string c = "";
    while (a > 0) {
        c.push_back(a % 3 + '0');
        a /= 3;
    }
    reverse(c.begin(), c.end());
    if (c.size() != b.size()) return 0;
    int err = 0;
    for (int i = 0; i < b.size(); i++) {
        err += (c[i] != b[i]);
    }
    return err == 1;
}

int main() {
    string a, b;
    cin >> a >> b;
    long long A = btod(a);
    for (int i = 0; i < a.size(); i++) {
        long long z = (1 << i);
        long long c = A ^ z;
        if (check(c, b)) {
            cout << c << endl;
            return 0;
        }
    }
    return 0;
}
