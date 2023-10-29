#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
typedef pair<ll, ll> point;
struct ConvexHull {
  int n;
  vector<point> elements;
  vector<point> stack; 
  point P0;

  float _orientation(point a, point b) {
    float val = a.first*(b.second-a.second)+b.first*(a.second-b.second);
    return val;
  }

  float _orientation(point a, point b, point c) {
    float val = a.first*(b.second-c.second)+b.first*(c.second-a.second)+c.first*(a.second-b.second);
    return val;
  }

  // -1 -- clockwise
  // 1 -- anticlockwise 
  // 0 -- colinear
  int orientation(point a, point b, point c) {
    float val = _orientation(a, b, c);
    return (val == 0) ? 0 : ((val > 0) ? 1 : -1);
  }

  ConvexHull(int n, vector<point> el) {
    this->n = n;
    for (point e : el) {
      this->elements.push_back(e);
    }
    this->P0 = *min_element(this->elements.begin(), this->elements.end(), [&, this](auto prev, auto next) {
      return (make_pair(prev.second, prev.first) < make_pair(next.second, next.first)); // idk expose the possibility for a custom comparator in case of smth idfkkkk
    });

    sort(this->elements.begin(), this->elements.end(), [&, this](auto prev, auto next) {
      int v = this->orientation(this->P0, prev, next);
      if (v == 0) 
        return (this->P0.first-prev.first)*(this->P0.first-prev.first)+(this->P0.second-prev.second)*(this->P0.second-prev.second) <
               (this->P0.first-next.first)*(this->P0.first-next.first)+(this->P0.second-next.second)*(this->P0.second-next.second);
      return (v < 0);
    });

    int i = this->elements.size()-1;
    while (i>=0&&this->orientation(this->P0,this->elements[i],this->elements.back()) == 0) i--;
    reverse(this->elements.begin()+i+1, this->elements.end());

    for (int i=0;i<this->elements.size();i++) {
      // if stack is large enough (at least 2 points present to compare against)
      // AND if the orientation between the current point, the previous point and the previous PREVIOUS point
      while (this->stack.size() >= 2 && (this->orientation(this->stack[this->stack.size()-2], this->stack.back(), this->elements[i]) > 0))
        this->stack.pop_back();
      this->stack.push_back(this->elements[i]);
    }
  }

  // TODO: allow for addition of elements to the stack
  ConvexHull(int n) {
    if (n <= 0) 
      throw runtime_error("dumbass you're trying to initialize a convex hull of non-existant length");
    this->n = n;
    cout << "WARNING: initialized empty convex hull" << endl;
    for (int i=0;i<n;i++)
      this->elements.assign(i, point(0, 0));
  }
};
vector<point> points;
float x, y;
int n;
int main() {
  /* freopen("sample","r",stdin); */
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> x >> y;
    points.push_back({x,y});
  }
  auto c = ConvexHull(n, points);
  /* cout << c.orientation({0, 0}, {1, 1}, {1, 0}) << endl; */
  /* for (point p : c.elements) { */
  /*   cout << p.first << ' ' << p.second << endl; */
  /* } */
  /* cout << endl; */
  cout << c.stack.size() << endl;
  for (point p : c.stack) {
    cout << p.first << ' ' << p.second << endl;
  }
  return 0;
}
