#include <iostream>
#include <utility>
#define HEAD_NODE 0
using namespace std;
using ll = long long;
typedef pair<ll, ll> node;
int n,q;
ll arr[200000],op,a,b;
node seg[800000];
ll max(ll a, ll b) { return (a>b)?a:b; }
node merge(node a, node b) {
  ll sum = a.first+b.first;
  ll pref = max(0,max(a.second, a.first+b.second));
  return {sum, pref};
}
void build(ll id, ll L, ll R) {
  if (L==R) {
    seg[id] = {arr[L], max(0,arr[L])};
    return;
  }
  ll M=(L+R)/2;
  build(2*id+1,L,M);
  build(2*id+2,M+1,R);
  seg[id]=merge(seg[2*id+1],seg[2*id+2]);
}
void update(ll id, ll L, ll R, ll i, ll val) {
  if (L==R) {
    seg[id]={val,max(0,val)};
    return;
  }
  ll M=(L+R)/2;
  if (i <= M) update(2*id+1,L,M,i,val);
  else update(2*id+2,M+1,R,i,val);
  seg[id]=merge(seg[2*id+1],seg[2*id+2]);
}
node query(ll id, ll L, ll R, ll l, ll r) {
  if (L == l && r == R) return seg[id];
  ll M=(L+R)/2;
  if (r <= M) return query(2*id+1, L, M, l, r);
  else if (l >= M+1) return query(2*id+2, M+1, R, l, r);
  else return merge(query(2*id+1,L,M,l,M),query(2*id+2,M+1,R,M+1,r));
}
int main() {
  cin>>n>>q;
  for (int i=0;i<n;i++) {
    cin>>arr[i];
  }
  build(HEAD_NODE,0,n-1);
  for (int i=0;i<q;i++) {
    cin>>op>>a>>b;
    if (op == 1) update(HEAD_NODE,0,n-1,a-1,b);
    else cout<<query(HEAD_NODE,0,n-1,a-1,b-1).second<<endl;
  }
  return 0;
}
