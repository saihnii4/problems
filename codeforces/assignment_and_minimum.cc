#include <iostream>
#include <vector>
#include <utility>
using namespace std;
struct st {
  int n;
  vector<ll> seg;
  st(int n): n(n), seg(4*n+1, {0, 0}) {
    return;
  }
  void update(ll id, ll L, ll R, ll l, ll r, ll v) {
    if (L == l && r == R) {
      seg[id].first = v;
      seg[id].second = v;
      return;
    }
  }
};
int main() {
  freopen("sample", "r", stdin);
  int n, q;
  cin >> n >> q;
  auto tree = st(n);
  for (int i=0;i<q;i++ ){

  }
}
