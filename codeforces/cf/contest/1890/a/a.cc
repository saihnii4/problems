#include <iostream>
#include <vector>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ll = long long;
typedef ll Key;
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>;
int t,n;
multiset<int> bruh;
set<int> nah;
int main() {
  // uncomment for testing
  /* freopen("test.in", "r", stdin); */
  /* freopen("test.out", "w", stdout); */
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> t;
      bruh.insert(t);
      nah.insert(t);
    }
    if (n <= 2) {
      cout << "YES" << endl;
      continue;
    }
    if (nah.size() > 2) {
      cout << "NO" << endl;
      continue;
    }
    cout << bruh.count(*nah.begin()) << endl;
    if (bruh.count(*nah.begin())-bruh.count(*(nah.end()--)) <= 1) {
      cout << "YES" << endl;
      continue;
    }

    cout << "NO" << endl;
  }
  return 0;
}
