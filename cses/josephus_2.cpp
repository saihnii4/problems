#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
ordered_set s;
int j;
int main() {
  /* freopen("sample", "r", stdin); */
  int n, k;
  cin >> n >> k;
  for (int i=1;i<=n;i++) s.insert(i);
  while (s.size()) {
    j += k;
    if (j >= s.size()) {
      j %= s.size();
    }
    cout << *s.find_by_order(j) << ' ';
    s.erase(s.find_by_order(j));
  }
  cout << endl;
  return 0;
}
