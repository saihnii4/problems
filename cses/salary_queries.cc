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
int n, q, op;
ll arr[200000], a, b;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ordered_set set;
  cin >> n >> q;
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }
  for (int i=0;i<q;i++) {
    cin >> op >> a >> b;
  }
  return 0;
}
