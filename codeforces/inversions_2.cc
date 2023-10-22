// completely broken lmfao imm so tired
#include <iostream>
#include <utility>
#define HEAD_NODE 0
using namespace std;
using ll = long long;
typedef pair<ll, ll> node;
int arr[100000], n;
node seg[400000];
node merge(node a, node b) {
  return {a.first+b.first, a.first};
}
void build(ll id, ll L, ll R) {
  if (L==R) {
    seg[id] = {1, L};
    return;
  }
  ll M=(L+R)/2;
  build(2*id+1,L,M);
  build(2*id+2,M+1,R);
  seg[id] = merge(seg[2*id+1],seg[2*id+2]);
}
void update(ll id, ll L, ll R, ll i, ll k) {
  if (L==R) {
    seg[id] = {k, L};
    return;
  }
  ll M=(L+R)/2;
  if (i <= M) update(2*id+1,L,M,i,k);
  else update(2*id+2,M+1,R,i,k);
  seg[id] = merge(seg[2*id+1],seg[2*id+2]);
}
node query(ll id, ll L, ll R, ll k) {
  if (L==R) return {seg[id].first, seg[id].second};
  ll M=(L+R)/2;
  if (seg[2*id+2].first >= k) return query(2*id+2,M+1,R,k);
  else return query(2*id+1,L,M,k);
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }
  build(HEAD_NODE,0,n-1);
  for (int i=n-1;i>=0;i--) {
    node q = query(HEAD_NODE,0,n-1,arr[i]-1);
    update(HEAD_NODE,0,n-1,q.second,0);
    cout << q.second << endl;
  }
  return 0;
}
