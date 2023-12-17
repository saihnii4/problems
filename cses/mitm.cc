#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll x, ans;
int n;
vector<ll> l, r;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> x;
  if (n == 1) {
    cout << n << endl;
    return 0;
  }
  ll arr[n];
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }
  ll* right = &arr[(n + 1) >> 1];
  int rlen = n - ((n + 1) >> 1);
  for (int i=0;i<(1 << ((n + 1) >> 1));i++) {
    ll sum = 0;
    for (int j=0;j<((n + 1) >> 1);j++) {
      if (i & (1 << j)) {
        sum += arr[j];
      }
    }
    l.push_back(sum);
  }
  for (int i=0;i<(1 << rlen);i++) {
    ll sum = 0;
    for (int j=0;j<rlen;j++) {
      if (i & (1 << j)) {
        sum += right[j];
      }
    }
    r.push_back(sum);
  }
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  for (ll i : l) {
    int lw = lower_bound(r.begin(), r.end(), x - i) - r.begin();
    int up = upper_bound(r.begin(), r.end(), x - i) - r.begin();
    ans += up - lw;
  }
  cout << ans << endl;
  return 0;
}
