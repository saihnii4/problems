#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
using ll = long long;
typedef ll Key;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
int n;
bool dp[101][100001];
ll coins[100];
set<ll> poss;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> coins[i];
  }
  dp[0][0] = true;
  for (int i=1;i<=n;i++) {
    for (int j=0;j<=n*1000;j++) {
      dp[i][j] = dp[i-1][j] || (j - coins[i-1] >= 0 ? dp[i-1][j-coins[i-1]] : false);
    }
  }
  for (int i=1;i<=n*1000;i++) {
    if (dp[n][i]) {
      poss.insert(i);
    }
  }
  cout << poss.size() << endl;
  for (ll pos: poss) {
    cout << pos << ' ';
  }
  cout << endl;
  return 0;
}
