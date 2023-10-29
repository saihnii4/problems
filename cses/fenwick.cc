#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
struct Fenwick {
  vector<ll> bit;
  int n;
  
  Fenwick(int n) {
    this->n = n;
    bit.assign(n, 0);
  }

  Fenwick(vector<ll> const &a) : Fenwick(a.size()) {
    for (size_t i=0;i<a.size();i++) {
      add(i, a[i]);
    }
  }

  void add(int id, int delta) {
    for (; id < n; id = id | (id + 1)) {
      bit[id] += delta;
    }
  }
  int sum(int r) {
    int ret=0;
    for (; r>=0;r=(r & (r + 1)) - 1)
      ret += bit[r];
    return ret;
  }

  int sum(int l, int r) {
    return sum(r)-sum(l-1);
  }
};
int main() {
  int n, op;
  ll a;
  freopen("sample","r",stdin);
  auto tree = Fenwick({1, 2, 3, 4});
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> op >> a;
    if (op == 1) {
      cout << a.ssum()
    }
  }
  return 0;
}
