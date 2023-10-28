// math problem TODO:
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <set>
using ll = long long;
typedef ll Key;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
int t;
int main() {
  /* cin.tie(NULL); */
  /* ios_base::sync_with_stdio(false); */
  scanf("%d", &t);
  while (t--) {
    bool compos = false;
    multiset<int> s; // overkill for an easy problem but idgaf
    int n, k;
    scanf("%d %d", &n, &k);
    if (k == 4) {
      k = 2;
      compos = true;
    }
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      if (t % k == 0) {
        s.insert(0);
      } else if (compos) {
        s.insert(abs(k - (t % k)));
      } else {
        s.insert(abs(k - (t % k)));
      }
    }
    auto begin = s.begin();
    if (compos) {
      int val = *begin;
      ++begin;
      val += *begin;
      printf("%d\n", val);
    } else
      printf("%d\n", *begin);
  }
  return 0;
}
