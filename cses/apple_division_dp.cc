#include <iostream>
using namespace std;
using ll = long long;
ll arr[20];
ll total;
ll ans = -1e9;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    total += arr[i];
  }
  for (int i = 0; i < (1 << n); i++) {
    int z = i;
    ll sum = 0;
    for (int j = 0; j < n; j++)
      if (i & (1 << j)) {
        sum += arr[j];
      }
    if (sum <= (total >> 1)) {
      ans = max(ans, sum);
    }
  }
  cout << abs(ans - total + ans) << endl;
  return 0;
}
