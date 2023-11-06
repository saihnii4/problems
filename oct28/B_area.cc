#include <algorithm>
#include <iostream>
#include <math.h>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
typedef pair<ll, ll> point;
vector<point> points, stack;
int t, n;
int orientation(point a, point b, point c) {
  float val = a.first * (b.second - c.second) +
              b.first * (c.second - a.second) + c.first * (a.second - b.second);
  if (val > 0)
    return 1;
  if (val < 0)
    return -1;
  return 0;
}
int main() {
  freopen("sample", "r", stdin);
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      ll x, y;
      cin >> x >> y;
      cout << x << ' ' << y << endl;
      points.push_back({x, y});
    }
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
  while (i >= 0 && orientation(P0, points[i], points.back()) == 0)
    i--;
  reverse(points.begin() + i + 1, points.end());

  for (int i = 0; i < points.size(); i++) {
    while (stack.size() >= 2 &&
           orientation(stack[stack.size() - 2], stack.back(), points[i]) > 0)
      stack.pop_back();
    stack.push_back(points[i]);
  }

  float area = 0.f;
  stack.push_back(*stack.begin());

  for (int i = 0; i < stack.size(); i++) {
    if (i == stack.size() - 1) {
      area +=
          stack[i].first * stack[0].second - stack[i].second * stack[0].first;
      break;
    }
    area += (stack[i].first * stack[i + 1].second -
             stack[i].second * stack[i + 1].first);
  }

  cout << 0.5f*abs(area) << endl;
  return 0;
}
