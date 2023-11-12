#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
typedef pair<ll, ll> pr;
unordered_map<ll, pr> map;
int t, n;
int arr[200000];
vector<pr> dig;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    string s = to_string(arr[i]);
    cout << s << endl;
    ll ans=0;
    for (int j=0;j<(s.size());j++) {
      ans += s.c_str()[j]-'0';
    }
    dig.push_back({ans, s.size() % 2 == 0});
  }
  for (pr p : dig) {
    if (!p.second)
      map[p.first].first++;
    else
      map[p.first].second++;
  }
  ll ans = 0;
  cout << map.size() << endl;
  for (auto val : map) {
    cout << val.first << ' ' << val.second.first << ' ' << val.second.second << endl;
    ans += val.second.first * (val.second.first - 1);
    ans += val.second.second * (val.second.second - 1);
  }
  cout << ans+n << endl;
  return 0;
}
