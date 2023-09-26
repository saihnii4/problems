#include <algorithm>
#include <stdio.h>

#define ll long long
#define HEAD_NODE 0

struct node {
  ll sum;
  ll pref;
  ll suf;
  ll sol;
};

ll max(ll a, ll b) { return (a > b) ? a : b; }
ll max(ll a, ll b, ll c) { 
  ll d = (a > b) ? a : b;
  ll e = (b > c) ? b : c;
  return (d > e) ? d : e;
}

ll arr[100000], n, m;
node seg[400000];

node merge(node a, node b) {
  ll pref = max(0, max(a.pref, a.sum+b.pref));
  ll suf = max(0, max(b.suf, b.sum+a.suf));
  ll max_sum = max(0, max(a.suf + b.pref, a.sol, b.sol));
  ll sum = a.sum + b.sum;

  return {sum, pref, suf, max_sum};
}

void build(ll id, ll L, ll R) { 
  if (L == R) {
    seg[id] = {arr[L], max(0, arr[L]), max(0, arr[L]), max(0, arr[L])};
    return;
  }
  
  ll M = (L + R) / 2;

  build(2*id+1, L, M);
  build(2*id+2, M+1, R);

  seg[id] = merge(seg[2*id+1], seg[2*id+2]);
}

void update(ll id, ll L, ll R, ll el, ll val) {
  if (L == R) {
    seg[id] = {val, max(0, val), max(0, val), max(0, val)};
    return;
  }

  long long M = (L + R) / 2;
  if (el <= M) update(2*id+1, L, M, el, val);
  else update(2*id+2, M+1, R, el, val);

  seg[id] = merge(seg[2*id+1], seg[2*id+2]);
}

int main() {
  scanf("%lld %lld", &n, &m);

  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }

  build(HEAD_NODE,0,n-1);

  printf("%lld\n", max(0, seg[HEAD_NODE].sum));
  
  for (int i = 0; i < m; i++) {
    ll index, val;
    scanf("%lld %lld", &index, &val);
    update(HEAD_NODE,0,n-1,index,val);
    printf("%lld\n", max(0, seg[HEAD_NODE].sol));
  }

  return 0;
}

