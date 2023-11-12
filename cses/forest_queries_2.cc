#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int n, q, a, b, c, d, op;

struct Fenwickree {
  vector<vector<ll>> bit, arr;
  int n;

  Fenwickree(vector<vector<ll>> arr) : bit(arr), arr(arr), n(arr.size()) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int r = j | (j + 1); // adds self bucket value to parent bucket
        if (r < n)
          bit[i][r] += bit[i][j];
      }
    }
  };

  ll query(ll i, ll j) {
    ll sum = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
      for (; j >= 0; j = (j & (j + 1)) - 1) {
        sum += bit[i][j];
      }
    }
    return sum;
  }

  void update(ll i, ll j, ll v) {
    for (; i < n; i = (i | (i + 1)))
      for (; j < n; j = (j | j + 1))
        bit[i][j] += v;
  }
};

int main() {
  freopen("sample", "r", stdin);
  cin >> n >> q;
  vector<vector<ll>> arr(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      if (arr[i][j] - '.')
        arr[i][j] = 1;
      else
        arr[i][j] = 0;
    }
  }
  auto tree = Fenwickree(arr);
  cout << tree.query(3, 3) << endl;
  for (int i = 0; i < q; i++) {
    cin >> op >> a >> b;
    if (op == 1) {
      int val = arr[a - 1][b - 1];
      if (val - '.' == 0) {
        tree.update(a - 1, b - 1, -1);
        arr[a - 1][b - 1] = '*';
      } else {
        tree.update(a - 1, b - 1, 1);
        arr[a - 1][b - 1] = '.';
      }
    } else {
      cin >> c >> d;
      cout << tree.query(a - 1, b - 1) - tree.query(0, d - 1) -
                  tree.query(c - 1, 0) + tree.query(c - 1, d - 1)
           << endl;
    }
  }
}
