#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;
int t;
string str;
int main() {
  cin >> t;
  while (t--) {
    ll ans = 0, a, s = 0;
    cin >> a;
    cin >> str;
    unordered_map<ll, ll> freq;
    freq[0] = 1;
    for (int i = 0; i < a; i++) {
      s += str.c_str()[i] - '0';
      ll x = s - i - 1;
      /* cout << x << ' ' << i << ' ' << prefix[i] << endl; */
      if (!freq[x])
        freq[x] = 0;
      freq[x]++;
      ans += freq[x] - 1;
    }
    cout << ans << endl;
  }
}
