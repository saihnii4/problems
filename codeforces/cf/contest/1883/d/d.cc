#include <iostream>
#include <set>
using namespace std;
using ll = long long;
multiset<ll> bgn, nd;
int t;
int main() {
  cin >> t;
  while (t--) {
    char op;
    ll l, r;
    cin >> op >> l >> r;
    if (op == '+') {
      bgn.insert(l);
      nd.insert(r);
    } else {
      bgn.erase(bgn.find(l));
      nd.erase(nd.find(r));
    }
    if (bgn.size() <= 1) {
      cout << "NO" << endl;
      continue;
    }
    auto end = bgn.end();
    end--;
    if (*end <= *(nd.begin())) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
