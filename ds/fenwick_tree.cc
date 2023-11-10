// initiating a fenwick tree in O(n) time is remarkably easy:
// consider an array of length n:
// for each element, add it to the corresponding "bucket"
// i.e arr[i] -> bit[i] for all i < n
// T[0b000] = arr[0b000]
// T[0b001] = arr[0b001]
// T[0b010] = arr[0b010]
// T[0b011] = arr[0b011]
// then, for each one find the parent bucket with i | (i + 1) and add the
// current bucket value to that bucket T[0b000 | (0b000 + 1)] => T[0b001]:
//   T[0b001] += T[0b000] (adds prev value to curr value)
// T[0b001 | (0b001 + 1)] => T[0b011]:
//   T[0b011] += T[0b001] (adds first 2 values to bucket corresponding to the
//   cumulative sum of the first 4 elements)
// and so on

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

// Dynamic Sum Range Fenwick Tree
template <typename T> struct FenwickTree {
  T DEFAULT_VALUE;
  vector<T> bit, arr;
  int n;

  FenwickTree(vector<T> arr, T def)
      : bit(arr.size(), 0), arr(arr), n(arr.size()), DEFAULT_VALUE(def) {
    for (int i = 0; i < n; i++) {
      bit[i] += arr[i];    // adds value to corresponding bucket
      int r = i | (i + 1); // adds self bucket value to parent bucket
      if (r < n)
        bit[r] += bit[i];
    }
  };

  T query(ll l, ll r) {
    return query(r) - query(l - 1); // similar to prefix sum logic
  }

  T query(ll i) {
    T sum = DEFAULT_VALUE;
    for (; i >= 0; i = (i & (i + 1)) - 1) {
      sum += bit[i];
    }
    return sum;
  }

  void update(ll i, T v) {
    for (; i < n; i = (i | (i + 1)))
      bit[i] += v;
  }

  T merge(T l, T r) { return l + r; }
};

// AC on Dynamic Range Sum Queries
// runs slightly faster than the standard Segment Tree implementation
int main() {
  int n, q;
  cin >> n >> q;
  vector<ll> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  auto tree = FenwickTree<ll>(arr, 0);
  for (int i = 0; i < q; i++) {
    int op, a;
    ll b;
    cin >> op >> a >> b;
    if (op == 1) {
      ll delta = b - tree.query(a - 1, a - 1);
      tree.update(a - 1, delta);
    } else {
      cout << tree.query(a - 1, b - 1) << endl;
    }
  }
  return 0;
}

