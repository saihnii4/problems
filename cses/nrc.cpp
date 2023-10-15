#include <iostream>
#include <utility>
#include <set>
using namespace std;
using ll = long long;
typedef pair<pair<ll, ll>, int> e;
int n;
int main() {
  cin>>n;
  set<e> s;
  for (int i=0;i<n;i++) {
    ll x,y;
    cin>>x>>y;
    s.insert({{x, y}, i});
  }
}
