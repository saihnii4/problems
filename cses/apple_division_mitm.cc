#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll x, ans = 1e9, total;
int n;
vector<ll> l, r;
int main() {
  freopen("sample", "r", stdin);
  cin >> n;
  ll arr[n];
  for (int i=0;i<n;i++) {
    cin >> arr[i];
    total += arr[i];
  }
  ll* right = &arr[n >> 1];
  for (int i=0;i<(1 << (n >> 1));i++) {
    ll sum = 0;
    for (int j=0;j<(n >> 1);j++) {
      if (i & (1 << j)) {
        sum += arr[j];
      }
    }
    l.push_back(sum);
  }
  for (int i=0;i<(1 << (n >> 1));i++) {
    ll sum = 0;
    for (int j=0;j<(n >> 1);j++) {
      if (i & (1 << j)) {
        sum += right[j];
      }
    }
    r.push_back(sum);
  }
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  int i = 0, j = 0;
  while (i < l.size() && j < r.size()) {
    if ((total >> 1) > l[i]+r[j]) {
      ++i;
      ++j;
      continue;
    }
    ans = min(ans, (total >> 1)-r[j]-l[i]);

    ++i;
  }
  cout << ans << endl;
  return 0;
}
