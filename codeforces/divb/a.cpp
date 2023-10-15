#include <iostream>
using namespace std;
using ll = long long;
ll t,efficiency,n;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    efficiency = 0;
    for (int i=0;i<n;i++) {
      ll t;
      cin >> t;
      efficiency += t;
    }
    cout << -efficiency << endl;
  }
  return 0;
}
