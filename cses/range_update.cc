// TODO: fix
#include <iostream>
#include <utility>
#define HEAD_NODE 0
using namespace std;
using ll = long long;
struct node {
  ll val;
  ll min_i;
  ll max_i;
};
ll arr[200000], op, a, b, u;
int n, q;
node seg[800000];
node merge(node a, node b) {
  /* cout << a.min_i << ' ' << b.max_i << ": " << a.val << ' ' << b.val << endl; */
  return { a.val+b.val, a.min_i, b.max_i };
}
void build(ll id, ll L, ll R) {
  if (L == R) {
    seg[id] = {arr[L],L,L};
    return;
  }
  ll M=(L+R)/2;
  build(2*id+1,L,M);
  build(2*id+2,M+1,R);
  seg[id]=merge(seg[2*id+1],seg[2*id+2]);
}
void update(ll id, ll L, ll R, ll l, ll r, ll k) {
  cout << seg[id].min_i << ' ' << seg[id].max_i << endl;
  if (seg[id].max_i < l || seg[id].min_i > r) return;
  if (L == R) {
    cout << id << endl;
    seg[id].val += k;
    return;
  }
  ll M=(L+R)/2;
  if (r <= M) update(2*id+1,L,M,l,r,k);
  else if (l >= M + 1) update(2*id+1,M+1,R,l,r,k);
  else {
    update(2*id+1,L,M,l,M,k);
    update(2*id+2,M+1,R,M+1,r,k);
  }
  seg[id]=merge(seg[2*id+1],seg[2*id+2]);
}
node query(ll id, ll L, ll R, ll i) {
  if (L==R) return seg[id];
  ll M=(L+R)/2;
  if (i <= M) return query(2*id+1,L,M,i);
  else return query(2*id+2,M+1,R,i);
}
int main() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build(HEAD_NODE,0,n-1);
  for (int i = 0; i < q; i++) {
    cin >> op >> a;
    if (op == 1) {
      cin >> b >> u;
      update(HEAD_NODE,0,n-1,a-1,b-1,u);
      for (int i = 0; i < 4*n; i++) cout << seg[i].val << ' ';
      cout <<endl;
    } else {
      cout << query(HEAD_NODE,0,n-1,a-1).val << endl;
    }
  }
}
