#include <iostream>
#define MOD (int)1e9+7
using namespace std;
using ll = long long;
int t;
ll arr[1000000][2];
int main() {
  arr[0][0] = 1;
  arr[0][1] = 1;

  for (int i = 0; i < 1000000; i++) {
    arr[i+1][0] =4*arr[i][0]+arr[i][1];
    arr[i+1][1] =2*arr[i][1]+arr[i][0];
    arr[i+1][0] %= MOD;
    arr[i+1][1] %= MOD;
  }
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (arr[n-1][0]+arr[n-1][1])%(MOD) << endl;
  }
  return 0;
}
