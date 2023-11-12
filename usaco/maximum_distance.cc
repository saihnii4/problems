#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
#include <limits.h>
using namespace std;
using ll = long long;
int n;
ll mn = LLONG_MIN;
ll max(ll a, ll b) { return (a > b) ? a : b; }
int main() {
  cin >> n;
  vector< pair<int, int> > v(n);
  for (int i=0;i<n;i++) {
    cin >> v[i].first;
  }
  for (int i=0;i<n;i++) {
    cin >> v[i].second;
  }
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) if (i!=j) {
      mn = max(mn, pow(v[i].first-v[j].first, 2)+pow(v[i].second-v[j].second,2));
    }
  }
  cout << mn << endl;
}
