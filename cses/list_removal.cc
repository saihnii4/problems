#include <iostream>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
int n, q;
ll arr[200000];
int main() {
  ordered_set x;
  cin >> n;
  for (int i=0;i<n;i++) {
    ll t;
    cin >> t;
    arr[i] = t;
    x.insert(i);
  }
  for (int i=0;i<n;i++) {
    ll t;
    cin >> t;
    ll loc = *x.find_by_order(t-1);
    x.erase(loc);
    cout << arr[loc] << ' ';
  }
  cout << endl;
  return 0;
}
