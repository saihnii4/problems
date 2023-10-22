#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ll = long long;
typedef ll Key;
using namespace std;
using namespace __gnu_pbds;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
int n;
bool arr[100000];
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> t;
  }
  for (int i=0;i<100000;i++) {
    for (int j=0;j<n;j++) {
      if (i - coins[j] >= 0) dp[i] = dp[i-coins[j]]
    }
  }
  return 0;
}
