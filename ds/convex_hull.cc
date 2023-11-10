// Graham's Scan

#include <algorithm>
#include <iostream>
#include <math.h>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
typedef pair<ll, ll> point;
vector<point> points;
vector<point> stack;
int orientation(point a, point b, point c) {
  float val = a.first * (b.second - c.second) +
              b.first * (c.second - a.second) + c.first * (a.second - b.second);
  if (val < 0)
    return -1;
  if (val > 0)
    return 1;
  return 0;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    points.push_back({x, y});
  }
  point P0 = *min_element(points.begin(), points.end(), [&](point l, point r) {
    return make_pair(l.second, l.first) < make_pair(r.second, r.first);
  });

  sort(points.begin(), points.end(), [&](point l, point r) {
    int o = orientation(P0, l, r);
    if (o == 0)
      return pow(P0.first - l.first, 2) + pow(P0.second - l.second, 2) <
             pow(P0.first - r.first, 2) + pow(P0.second - r.second, 2);
    return (o < 0);
  });

  int i = points.size() - 1;
  while (i >= 0 && orientation(P0, points.back(), points[i]) == 0)
    --i;
  reverse(points.begin() + i + 1, points.end());

  for (int i = 0; i < n; i++) {
    while (stack.size() >= 2 &&
           orientation(stack[stack.size() - 2], stack.back(), points[i]) > 0) {
      stack.pop_back();
    }
    stack.push_back(points[i]);
  }

  cout << stack.size() << endl;

  for (point p : stack) {
    cout << p.first << ' ' << p.second << endl;
  }

  return 0;
}
