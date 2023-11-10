#include <iostream>
#include <vector>
using namespace std;
struct FenwickTree {
  int n;
  vector<int> bit;
  FenwickTree(vector<int> arr) : n(arr.size()), bit(arr.size(), 0) {
    for (int i=0;i<n;i++) {
      bit[i] = arr[i];
      int r = i | (i + 1);
      if (r < n) bit[r] += bit[i];
    }
  }

  int query(int l, int r) {
    return query(r) - query(l - 1);
  }

  int query(int i) {
  }

  void add_
};
int main() {
  int n, q;
  cin >> n >> q;
  vector<int> arr(n);
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }
  for (int i=0;i<q;i++) {
    int op, a, b;
    cin >> op >> a >> b;

    switch (op) {
      case 1:
      case 2:
      case 3:
      default:
      return -1;
    }
  }
  return 0;
}
