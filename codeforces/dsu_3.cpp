// barebones implementation of DSU
#include <iostream>
using namespace std;
int n,q,op,a,b,g[100001];
int find(int x) {
  if (g[x] == x) return x; // the representative of a tree will always point to itself 
  return find(g[x]);
}
void merge(int x, int y) {
  if (x == y) return; // already connected
  g[x] = find(y);
}
int main() {
  cin >> n >> q;
  for (int i=0;i<n;i++) {
    g[i+1]=i+1;
  }
  for (int i=0;i<q;i++) {
    cin >> op >> a;
    if (op == 1) {
      cout << find(a) << endl;
    } else {
      cin >> b;
      merge(a, b);
    }
  }
  return 0;
}
