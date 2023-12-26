#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
struct st {
  int n;
  vector<pair<ll, ll>> seg;
  vector<bool> marked;
  st(int n) : n(n), seg(4 * n + 1, {0, 0}), marked(4 * n + 1, false) { return; }
  void push(ll id) {
    if (marked[id]) {
      marked[id] = false;
    }
  }
  void update(ll id, ll L, ll R) {

  }
};
int main() {
  int n, m;
  freopen("sample", "r", stdin);
  cin >> n >> m;
  int op, a, b;
  ll c;
  for (int i = 0; i < m; i++) {
    cin >> op >> a >> b;
  }
}
