#include <iostream>
#include <math.h>
using namespace std;
using ll = long long;
#define MOD (int)(1e9 + 7)
int expo(ll a, ll b) {
  if (a == 0)
    return b == 0;
  int ans = 1;
  while (b) {
    if (b & 1)
      ans = (ans * a) % MOD;
    b >>= 1LL;
    a = (a * a) % MOD;
  }
  return ans;
}
int main() {
  int n, m;
  cin >> n >> m;
  ll k = expo(2, m) - 1 % MOD;
  cout << expo(k, n) << endl;
  return 0;
}
