#include <iostream>
#include <string>
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
ll t, n, m;
string str, substr;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    bool found = false;
    cin >> n >> m;
    cin >> str;
    cin >> substr;
    for (int i=0;i<6;i++) {
      if (str.find(substr) != string::npos) {
        cout << i << endl;
        found = true;
        break;
      }
      str += str;
    }
    if (!found) cout << -1 << endl;
  }
  return 0;
}
