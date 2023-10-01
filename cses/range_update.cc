#include <iostream>
#include <utility>
#define HEAD_NODE 0
typedef long long ll;
using namespace std;
struct node {
  ll val;
  ll min_i;
  ll max_i;
};
ll n,q,arr[200000],op,a,b,u;
node seg[800000];
node merge(node a, node b) {
  return { a.val+b.val, a.min_i, b.max_i };
}
void build(ll id,ll L,ll R) {
  if (L==R) {
    seg[id]={arr[L],L,R};
    return;
  }
  ll M=(L+R)/2;
  build(2*id+1,L,M);
  build(2*id+2,M+1,R);
  seg[id]=merge(seg[2*id+1],seg[2*id+2]);
}
void update(ll id,ll L,ll R,ll l, ll r, ll v) {
  if (seg[id].min_i > l || r > seg[id].max_i) return;
  if (L==R) {
    printf("bruh %lld\n",id);
    seg[id].val+=v;
    return;
  }
  ll M=(L+R)/2;
  update(2*id+1,L,M,l,r,v);
  update(2*id+2,M+1,R,l,r,v);
  seg[id]=merge(seg[2*id+1],seg[2*id+2]);
}
node query(ll id,ll L,ll R,ll i) {
  if (L==R) return seg[id];
  ll M=(L+R)/2;
  if (i <= M) return query(2*id+1,L,M,i);
  else return query(2*id+2,M+1,R,i);
}
int main() {
  cin>>n>>q;
  for (ll i=0;i<n;i++) cin>>arr[i];
  build(HEAD_NODE,0,n-1);
  for (ll i=0;i<q;i++){
    cin>>op>>a;
    if(op==1) {
      cin>>b>>u;
      update_l(HEAD_NODE,0,n-1,a-1,b-1,u);
      update(HEAD_NODE,0,n-1,a-1,b-1,u);
    } else {
      cout<<query(HEAD_NODE,0,n-1,a-1).val<<endl;
    }
  }
}
