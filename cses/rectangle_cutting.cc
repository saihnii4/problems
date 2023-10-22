#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
ll a, b;
ll solve(ll x, ll y) {
  if (x == y) return 0;
  ll a = min(x, y);
  ll b = x ^ y ^ a;
  return 1 + solve(a, b-a);
}
int main() {
  cin >> a >> b;
  cout << solve(a, b) << endl;
}
