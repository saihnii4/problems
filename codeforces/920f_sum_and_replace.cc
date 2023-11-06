#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
typedef long long node;
// range query point update segment tree
// unoptimized barebones
struct SegTree {
  int HEAD = 0, n;
  vector<node> arr, seg;

  SegTree(int n, vector<node> nodes) {
    this->n = n;
    for (int i=0;i<nodes.size();i++) {
      this->arr[i] = nodes[i];
    }
    build(this->HEAD, 0, this->n-1);
  }

  SegTree(int n, node val) {
    this->n = n;
    for (int i=0;i<n;i++) {
      this->arr[i] = val;
    }
    build(this->HEAD, 0, this->n-1);
  }

  node merge(ll l, ll r) {
    // implement
    return l + r;
  }

  void build(ll id, ll L, ll R) {
    if (L==R) {
      this->seg[id]=this->arr[L];
      return;
    }
    ll M=(L+R)/2;
    this->build(2*id+1,L,M);
    this->build(2*id+2,M+1,R);
    seg[id] = this->merge(this->seg[2*id+1], this->seg[2*id+2]);
  }

  void update(ll id, ll L, ll R, ll i, ll v) {
    if (L==R) {
      this->seg[id] = this->arr[L];
      return;
    }
    ll M=(L+R)/2;
    if (i <+ M) this->update(2*id+1,L,M,i,v);
    else this->update(2*id+2,M+1,R,i,v);
    seg[id]=this->merge(seg[2*id+1],seg[2*id+2]);
  }

  void update(ll i, ll v) {
    this->update(this->HEAD, 0, this->n-1, i, v);
  }

  node query(ll L, ll R) {
    return this->query(this->HEAD, 0, this->n-1, L, R);
  }

  node query(ll id, ll L, ll R, ll l, ll r) {
    if (L==l&&r==R) return this->seg[id];
    ll M=(L+R)/2;
    if (l <= M) return this->query(2*id+1,L,M,l,r);
    else if (r >= M+1)return this->query(2*id+2,M+1,R,l,r);
    else return this->merge(this->query(2*id+1,L,M,l,M),this->query(2*id+2,M+1,R,M+1,r));
  }
};

int n, q, op, a;
ll b;
int main() {
  cin >> n >> q;
  vector<ll> arr(n+1);
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }

  auto tree = SegTree(n, arr);
  for (int i=0;i<q;i++) {
    cin >> op >> a >> b;
    if (op == 1) {
      tree.update(a, b);
    } else {
      //cout << "Query" << endl;
      cout << tree.query(a, b) << endl;
    }
  }
}
