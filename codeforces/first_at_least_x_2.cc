#include <iostream>
#include <algorithm>
#include <utility>
#define HEAD_NODE 0
using namespace std;
typedef long long ll;
// max - index
typedef pair<ll, ll> node;
ll arr[100000], op, a, b, n, q;
node seg[400000];
node merge(node a, node b) { return {max(a.first, b.first), max(a.second, b.second)}; }
void build(ll id,ll L,ll R) {
  if (L==R) {
    seg[id]=node(arr[L],L);
    return;
  }
  ll M=(L+R)/2;
  build(2*id+1,L,M);
  build(2*id+2,M+1,R);
  seg[id]=merge(seg[2*id+1],seg[2*id+2]);
}
void update(ll id, ll L, ll R, ll i, ll v) {
  if (L==R) {
    seg[id]=node(v, i);
    return;
  }
  ll M=(L+R)/2;
  if (i <= M) update(2*id+1,L,M,i,v);
  else update(2*id+2,M+1,R,i,v);
  seg[id]=merge(seg[2*id+1],seg[2*id+2]);
}
node query(ll id, ll L, ll R, ll x, ll l) {
  if (L==R) return (x <= seg[id].first) ? seg[id] : node(0, -1);
  ll M=(L+R)/2;
  node res = node(0, -1);
  if (seg[2*id+1].first >= x && seg[2*id+1].second >= l)
    res = query(2*id+1,L,M,x,l);
  if (res.second == -1) res = query(2*id+2,M+1,R,x,l);
  return res;
}
int main() {
  cin >> n >> q;
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build(HEAD_NODE,0,n-1);
  for (ll i = 0; i < q; i++) {
    cin >> op >> a >> b;
    if (op == 1)
      update(HEAD_NODE,0,n-1,a,b);
    else
      printf("%lld\n", query(HEAD_NODE,0,n-1,a,b).second);
  }

  return 0;
}
