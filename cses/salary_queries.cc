// ordered set solution
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <utility>
#include <vector>
#include <limits.h>
using ll = long long;
typedef ll Key;
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
             tree_order_statistics_node_update>;
char op;
int n, q;
ll arr[200000], a, b;
int main() {
  /* freopen("test.in", "r", stdin); */
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ordered_set<pair<ll, ll>> set;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    set.insert({arr[i], i});
  }
  /* for (auto p : set) { */
  /*   cout << p.first << ' ' << p.second << endl; */
  /* } */
  for (int i = 0; i < q; i++) {
    cin >> op >> a >> b;
    if (op - '?' == 0) {
      cout << set.order_of_key({b, LLONG_MAX})-set.order_of_key({a-1,LLONG_MAX}) << endl;
    } else {
      set.erase(set.find({arr[a-1],a-1}));
      set.insert({b, a-1});
      arr[a-1] = b;
    }
  }
  return 0;
}
