#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
struct FenwickTree {
  int n;
  vector<ll> bit;
  FenwickTree(vector<ll> arr) : n(arr.size()), bit(arr.size(), 0) {
    for (int i = 0; i < n; i++) {
      bit[i] += arr[i];
      int r = i | (i + 1);
      if (r < n)
        bit[r] += bit[i];
    }
  }

  void update(ll i, ll v) {
    for (; i < n; i |= (i + 1))
      bit[i] += v;
  }

  ll query(ll l, ll r) { return query(r) - query(l - 1); }

  ll query(ll i) {
    ll sum = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
      sum += bit[i];
    }
    return sum;
  }
};
char op;
int n, a, cs = 1;
ll b;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  /* freopen("sample", "r", stdin); */
  for (;;) {
    cin >> n;
    if (n == 0)
      break;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    auto tree = FenwickTree(arr);
    string line;
    cin.get();
    getline(cin, line);
    if (cs > 1) cout << endl;
    cout << "Case " << cs << ":" << endl;
    for (;;) {
      stringstream ss(line);
      if (line == "END")
        break;
      ss >> op >> a >> b;
      if (op - 'M' == 0) {
        cout << tree.query(a - 1, b - 1) << endl;
      } else {
        ll val = tree.query(a - 1, a - 1);
        tree.update(a - 1, b - val);
      }
      getline(cin, line);
    }
    ++cs;
  }
  return 0;
}
