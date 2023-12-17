#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
ll m = 1e9;
int _n = 0, sets = 0, n;
void solve(vector<pair<ll, bool>> arr, ll w, ll i) {
  if (w < 0 || i > (n - 1))
    return;
  m = min(m, w);
  solve(arr, w, i + 1);
  if (!arr[i].second) {
    solve(arr, w - arr[i].first, i + 1);
    arr[i].second = true;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll x;
  vector<pair<ll, bool>> arr(20);
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    ll t;
    cin >> t;
    arr[i] = {t, false};
  }
  while (_n < n) {
    solve(arr, x, 0);
    ++sets;
  }
  cout << sets << endl;
  return 0;
}

