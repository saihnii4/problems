#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;
int n;
ll p[50001],dist;
ll max(ll a, ll b) { return (a > b) ? a : b; }
unordered_map<ll, int> map;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  freopen("div7.in", "r", stdin);
  freopen("div7.out", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll t;
    cin >> t;
    p[i + 1] = p[i] + t;
    p[i + 1] %= 7;
  }
  for (int i = 1; i <= n; i++) {
    if (map.find(p[i]) != map.end()) {
      dist = max(dist, i - map[p[i]]);
      continue;
    }
    map[p[i]] = i;
  }
  cout << dist << endl;
}
