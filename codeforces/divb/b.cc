#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
ll t,p;
int n;
int res[100000][2];
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> p;
    for (int i=0;i<n;i++) {
      cin>>res[i][0];
    }
    for (int i=0;i<n;i++) {
      cin>>res[i][1];
    }
    sort(res,res+n);
    for (int i=0;i<n;i++) {
      if (p[i][1]>k) break;
    }
  }
}
