#include <iostream>
#define HEAD_NODE 0
using namespace std;
using ll = int;
struct node {
  ll ll_;
  ll lr_;
  ll bl_;
  ll br_;
};
ll ll_, lr_, bl_, br_;
int r, n, q, a, b;
node arr[200000];
node seg[800000];
node merge(node a, node b) {
  node inter = {a.ll_*b.ll_ + a.lr_*b.bl_, a.ll_*b.lr_+a.lr_*b.br_, a.bl_*b.ll_+a.br_*b.bl_, a.bl_*b.lr_ + a.br_*b.br_};
  inter.ll_ %= r;
  inter.lr_ %= r;
  inter.bl_ %= r;
  inter.br_ %= r;
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
  seg[id]=merge(seg[2*id+1],seg[2*id+2]);
}
node query(ll id, ll L, ll R, ll l, ll r) {
  if (L==l&&r==R) return seg[id];
  ll M=(L+R)/2;
  if (r <= M) return query(2*id+1,L,M,l,r);
  else if (l >= M+1) return query(2*id+2,M+1,R,l,r);
  else return merge(query(2*id+1,L,M,l,M),query(2*id+2,M+1,R,M+1,r));
}
int main() {
  /* node res = merge({1, 1, 1, 0}, {1, 1, 1, 0}); */
  /* cout << res.ll_ << ' ' << res.lr_ << endl; */
  /* cout << res.bl_ << ' ' << res.br_ << endl; */
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> r >> n >> q;
  for (int i=0;i<n;i++) {
    cin >> ll_;
    cin >> lr_;
    cin >> bl_;
    cin >> br_;
    arr[i] = {ll_, lr_, bl_, br_};
  }
  build(HEAD_NODE,0,n-1);
  for (int i=0;i<q;i++) {
    cin >> a >> b;
    node res =query(HEAD_NODE,0,n-1,a-1,b-1);
    cout << res.ll_ << ' ' << res.lr_ << endl;
    cout << res.bl_ << ' ' << res.br_ << endl;
    cout << endl;
  }
  return 0;
}
