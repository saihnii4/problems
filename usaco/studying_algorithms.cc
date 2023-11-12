#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, x, ans, ct;
int main() {
  cin >> n >> x;
  vector<int> arr(n,0);
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  for (int i=0;(i<n && ct < x);i++) {
    ct += arr[i];
    if (ct <= x) ans++;
  }
  cout << ans << endl;
  return 0;
}
