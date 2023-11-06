#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ll = long long;
typedef ll Key;
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>;
int t,n,c;
ll arr[200000],p[200000];
bool merge(int x, int y) {
  if (p[x])
}
int main() {
  // uncomment for testing
  /* freopen("test.in", "r", stdin); */
  /* freopen("test.out", "w", stdout); */
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n >> c;
    for (int i=0;i<n;i++) {
      cin >> arr[i];
      p[i] = arr[i];
    }
    for (int i=0;i<n;i++) {

    }
  }
  return 0;
}
