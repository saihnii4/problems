#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
struct FenwickTree {
  int n;
  vector<ll> bit;
  FenwickTree(vector<ll> arr) : n(arr.size()), bit(arr.size(), 0) {
    for (int i=0;i<n;i++) {
      bit[i] += arr[i];
      int r = i | (i + 1);
      if (r < n) bit[r] += bit[i];
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<ll> arr(n);
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }
  auto tree = FenwickTree(arr);
  while ()
}
