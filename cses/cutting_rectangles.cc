#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <vector>
using ll = long long;
typedef ll Key;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
int a, b;
ll solve(ll x, ll y) {
  if (x == y)
    return 1;

  int tmp = x;
  x = max(x, y);
  y = x ^ y ^ tmp;

  return 1 + solve(x - y, y);
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> a >> b;
  cout << solve(a, b) - 1 << endl;
  return 0;
}
