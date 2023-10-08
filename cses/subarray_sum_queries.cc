#include <iostream>
#define HEAD_NODE 0
using namespace std;
using ll = long long;
struct node {
  ll sol;
  ll pref;
  ll suf;
  ll sum;
};
node seg[800000];
ll arr[200000];
ll max(ll a, ll b) { return (a>b)?(a):(b); }
ll max(ll a, ll b, ll c) {
  ll d = (a > b) ? a : b;
  ll e = (c > d) ? c : d;
  return (d > e) ? d : e;
}
node merge(node a, node b) {
  ll sum = a.sum + b.sum;
  ll pref = max(a.pref, a.sum + b.pref);
  ll suf = max(b.suf, b.sum + a.suf);
  ll sol = max(0, max(a.sol, b.sol, a.suf + b.pref));
  return {sol, pref, suf, sum};
}
void build(ll id, ll L, ll R) {
  if (L==R){
    seg[id]={max(0,arr[L]),max(0,arr[L]),max(0,arr[L]),arr[L]};
    return;
  }
  ll M=(L+R)/2;
  build(2*id+1,L,M);
  build(2*id+2,M+1,R);
  seg[id]=merge(seg[2*id+1],seg[2*id+2]);
}
void update(ll id, ll L, ll R, ll i, ll val) {
  if (L==R) {
    seg[id] = {max(0,val), max(0,val), max(0,val), val};
    return;
  }
  ll M=(L+R)/2;
  if (i <= M) update(2*id+1,L,M,i,val);
  else update(2*id+2,M+1,R,i,val);
  seg[id]=merge(seg[2*id+1],seg[2*id+2]);
}
int n,q,a,b;
int main() {
  cin>>n>>q;
  for (int i=0;i<n;i++) {
    cin>>arr[i];
  }
  build(HEAD_NODE,0,n-1);
  for (int i=0;i<q;i++){
    cin>>a>>b;
    update(HEAD_NODE,0,n-1,a-1,b);
    cout << seg[HEAD_NODE].sol << endl;
  }
  return 0;
}
