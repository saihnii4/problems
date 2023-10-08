#include <iostream>
#include <utility>
#define HEAD_NODE 0
using namespace std;
using ll = long long;
typedef pair<ll,ll> node;
int n,q,o,a;
ll arr[200000],b;
node seg[800000];
node merge(node a, node b) {
  if (a.first % 2 == 0) return {a.first+1, a.second | b.second};
  else return {a.first+1, a.second^b.second};
}
void build(ll id, ll L, ll R) {
  if (L==R) {
    seg[id]={0,arr[L]};
    return;
  }
  ll M=(L+R)/2;
  build(2*id+1,L,M);
  build(2*id+2,M+1,R);
  seg[id]=merge(seg[2*id+1],seg[2*id+2]);
}
void update(ll id, ll L, ll R, ll i, ll val) {
  if (L == R) {
    seg[id] = {0,val};
    return;
  }
  ll M = (L+R)/2;
  if (i <= M)
    update(2*id+1,L,M,i,val);
  else
    update(2*id+2,M+1,R,i,val);
  seg[id]=merge(seg[2*id+1],seg[2*id+2]);
}
int main() {
  cin>>n>>q;
  for (int i=0;i<(1<<n);i++) {
    cin >> arr[i];
  }
  build(HEAD_NODE,0,(1<<n)-1);
  for (int i=0;i<q;i++) {
    cin>>a>>b;
    update(HEAD_NODE,0,(1<<n)-1,a-1,b);
    cout << seg[HEAD_NODE].second << endl;
  }
}
