#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> arr1, arr2;
set<ll> ans;
int i, j;
int main() {
  int a, b;
  cin >> a >> b;
  arr1.resize(a);
  arr2.resize(b);
  for (int i = 0; i < a; i++) {
    cin >> arr1[i];
  }
  for (int i = 0; i < b; i++) {
    cin >> arr2[i];
  }
  for (int i = 0; i < b; i++) {
    while (i < a && arr1[i] < arr2[j])
      ++i;
    ans.insert(i);
  }
  for (ll i : ans) {
    cout << i << endl;
  }
  return 0;
}
