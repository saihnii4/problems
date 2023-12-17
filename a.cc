#include <iostream>
using namespace std;
using ll = long long;
int num, x, y;
ll sum;
int perm[4][4] = {{1, 4, 6, 3}, {5, 5, 5, 5}, {6, 3, 1, 4}, {2, 2, 2, 2}};
void next() {}
int main() {
  int n, q;
  cin >> n >> q;
  while (x != n && y != q) {
    next();
  }
  cout << sum << endl;
}
