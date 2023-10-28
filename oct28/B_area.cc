// definitely convex hull problem 
// too bad idfk how to solve convex hull problems :<
#include <iostream>
#include <utility>
using namespace std;
using ll = long long;
typedef pair<ll, ll> point;
ll area, x, y;
int n, p;
set<point> s;
int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> p;
    for (int i=0;i<p;i++) {
      cin >> x >> y;
      s.insert(point(x, y));
    }
  }
  cout << area << endl;
  return 0;
}
