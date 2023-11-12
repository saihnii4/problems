// TODO: implement monotone chain algorithm instead of graham's scan 

#include <iostream>
#include <vector>
#include <math.h>
#include <utility>
#include <algorithm>
using namespace std;
using ll = long long;
struct Point {
  ll x;
  ll y;
};
int orientation(Point a, Point b, Point c) {
  float val = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
  if (val < 0) return -1;
  if (val > 0) return 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("sample", "r", stdin);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<Point> points;
    for (int i=0;i<n;i++) {
      ll x, y;
      char c;
      cin >> x >> y >> c;
      if (c - 'Y' == 0)
        points.push_back({ x, y });
    }

    Point P0 = *min_element(points.begin(), points.end(), [&](Point l, Point r) {
      return make_pair(l.x, l.y) < make_pair(r.x, r.y);
    });

    sort(points.begin(), points.end(), [&](Point l, Point r) {
      int o = orientation(P0, l, r);
      if (o == 0) 
        return pow(P0.x-l.x,2)+pow(P0.y-l.y,2) < pow(P0.x-r.x,2)+pow(P0.y-r.y,2);
      return (o > 0);
    });

    cout << points.size() << endl;

    for (Point p : points) {
      cout << p.x << ' ' << p.y << endl;
    }
  }
  return 0;
}
