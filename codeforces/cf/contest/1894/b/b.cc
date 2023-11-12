#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    unordered_map<int, int> map;
    cin >> n;
    if (n==1) {
      cout << -1 << endl;
      continue;
    }
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
      cin >> arr[i];
      map[arr[i]]++;
    }
    int dup = 0;
    for (auto& p : map) {
      dup = max(dup,p.second-1);
    }
    cout << dup << endl;
    if (dup > 2 || dup == 0) {
      cout << -1 << endl;
      continue;
    }
    vector<int> b(arr);
    bool op1 = false;
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) if (i != j) {
        if (arr[i] == arr[j]) {
          if (op1) {
            if (b[i] == 1) b[i] = 2;
              else b[i] = 1;
            if (b[j] == 2) b[j] = 1;
            else b[j] = 2;
          } else {
            if (b[i] == 2) b[i] = 3;
              else b[i] = 2;
            if (b[j] == 3) b[j] = 2;
            else b[j] = 3;
            op1 = true;
          }
        }
      }
    }
    for (int i=0;i<n;i++) {
      cout << b[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}
