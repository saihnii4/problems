#include <iostream>
using namespace std;
int t, c, k, n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> c >> k >> n;
    if (c > k) {
      cout << c << endl;
      continue;
    }
    if (abs(k - c) <= n) {
      cout << k << endl;
      continue;
    }
    cout <<  2*k-c-n << endl;
  }
  return 0;
}
