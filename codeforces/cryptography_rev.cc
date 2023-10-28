#include <iostream>
#include <stdio.h>
#include <cstdio>
#define HEAD_NODE 0
using namespace std;
using ll = long long;
int n,q,r,i,j;
struct M {
  ll ul;
  ll ur;
  ll bl;
  ll br;
};
M seg[400004];
M arr[100001];
M merge(M a, M b) {
  M inter = {a.ul*b.ul+a.ur*b.bl, a.ul*b.ur+a.ur*b.br,
          a.bl*b.ul+a.br*b.bl, a.bl*b.ur+a.br*b.br}; // c++11 only
  inter.ul %= r;
  inter.ur %= r;
  inter.bl %= r;
  inter.br %= r;
  return inter;
}
void build(ll id, ll L, ll R) {
  if (L==R) {
    seg[id] = arr[L];
    return;
  }
  ll M=(L+R)/2;
  build(2*id+1,L,M);
  build(2*id+2,M+1,R);
  seg[id] = merge(seg[2*id+1],seg[2*id+2]);
}
M query(ll id, ll L, ll R, ll l, ll r) {
  cout << "query(" << id << ' ' << L << ' ' << R << ' ' << l << ' ' << r << ')' << endl;
  if (L == l && r == R) {
    return seg[id];
  }
  ll M=(L+R)/2;
  if (r <= M) return query(2*id+1,L,M,l,r);
  else if (l >= M+1) return query(2*id+2,M+1,R,l,r);
  else return merge(query(2*id+1,L,M,l,M), query(2*id+2,M+1,R,M+1,r));
}
int main() {
  freopen("test.in","r",stdin);
  freopen("test.out","w",stdout);
  cin >> n >> q >> r;
  for (int i=0;i<n;i++) {
    int ul, ur, bl, br;
    cin >> ul >> ur;
    cin >> bl >> br;
    arr[i] = {ul, ur, bl, br};
  }
  build(HEAD_NODE,0,n-1);
  for (int i=0;i<q;i++) {
    cin >> i >> j;
    M res = query(HEAD_NODE,0,n-1,i-1,j-1);
    cout << res.ul << ' ' << res.ur << endl;
    cout << res.bl << ' ' << res.br << endl;
    cout << endl;
  }
  return 0;
}
