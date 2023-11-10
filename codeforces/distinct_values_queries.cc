#include <iostream>
#include <set>
#define HEAD_NODE 0
using namespace std;
using ll = long long;
int n,q,i,j;
ll arr[200000];
set<ll> seg[400000];
set<ll> merge(set<ll> a, set<ll>b) {
  set<ll> c;
  c.merge(a);
  c.merge(b);
  return c;
}
void build(ll id, ll L, ll R) {
  if (L==R) {
    seg[id] = {arr[L]};
    return;
  }
  ll M=(L+R)/2;
  build(2*id+1,L,M);
  build(2*id+2,M+1,R);
  seg[id]=merge(seg[2*id+1],seg[2*id+2]);
}
set<ll> query(ll id, ll L, ll R, ll l, ll r) {
  if (L == l && r == R) return seg[id];
  ll M=(L+R)/2;
  if (r <= M) return query(2*id+1,L,M,l,r);
  else if (l >= M+1) return query(2*id+2,M+1,R,l,r);
  else return merge(query(2*id+1,L,M,l,M),query(2*id+2,M+1,R,M+1,r));
}
int main() {
  freopen("test.in","r",stdin);
  cin >> n >> q;
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }
  build(HEAD_NODE,0,n-1);
  for (int i=0;i<q;i++) {
    cin >> i >> j;
    set<ll> res = query(HEAD_NODE,0,n-1,i,j);
    cout << res.size() << endl;
  }
  return 0;
}