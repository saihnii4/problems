#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int n, k;
int main() {
  /* freopen("stacking.in", "r", stdin); */
  /* freopen("stacking.out", "w", stdout); */
  cin >> n >> k;
  vector<ll> arr(n+1);
  for (int i=0;i<k;i++) {
    ll x, y;
    cin >> x >> y;
    arr[x-1]++;
    arr[y]--;
  }
  ll tot = 0;
  int sol[1000000];
  for (int i=0;i<n;i++) {
    tot += arr[i];
    sol[i] = tot;
  }
  sort(sol, sol + n);
  cout << sol[n/2] << endl;
  return 0;
}
