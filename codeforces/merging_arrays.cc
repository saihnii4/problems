#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> arr1, arr2, merged;
int a, b;
int main() {
  cin >> a >> b;
  arr1.resize(a);
  arr2.resize(b);
  for (int i=0;i<a;i++) {
    cin >> arr1[i];
  }
  for (int i=0;i<b;i++) {
    cin >> arr2[i];
  }
  int i = 0, j = 0;
  while (i < a && j < b) {
    if (arr1[i] < arr2[j]) {
      merged.push_back(arr1[i]);
      ++i;
    } else {
      merged.push_back(arr2[j]);
      ++j;
    }
  }
  while (i < arr1.size()) {
    merged.push_back(arr1[i]);
    ++i;
  }
  while (j < arr2.size()) {
    merged.push_back(arr2[j]);
    ++j;
  }
  for (ll i : merged) {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}
