#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<int> arr;
vector<int> merge_sort(ll l, ll r) {
  if (l == r) {
    return {arr[l]};
  }
  ll m = (l + r) / 2;
  auto arr1 = merge_sort(l, m);
  auto arr2 = merge_sort(m + 1, r);
  vector<int> merged;
  int i = 0, j = 0;
  while (i < arr1.size() || j < arr2.size()) {
    if (j >= arr2.size() && i < arr1.size()) {
      merged.push_back(arr1[i]);
      ++i;
    }
    if (i >= arr1.size() && j < arr2.size()) {
      merged.push_back(arr2[j]);
      ++j;
    }
    if (i < arr1.size() && arr1[i] < arr2[j]) {
      merged.push_back(arr1[i]);
      ++i;
    } else if (j < arr2.size()) {
      merged.push_back(arr2[j]);
      ++j;
    }
  }
  return merged;
}
int main() {
  freopen("sample", "r", stdin);
  freopen("output", "w", stdout);
  ll t;
  while (cin >> t) {
    arr.push_back(t);
  }
  auto sorted = merge_sort(0, arr.size() - 1);
  for (int i : sorted) {
    cout << i << endl;
  }
  return 0;
}
