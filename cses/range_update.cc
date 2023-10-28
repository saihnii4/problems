#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define HEAD_NODE 0
using ll = long long;
typedef ll Key;
using namespace std;
using namespace __gnu_pbds;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
int n,q,op,a,b;
ll arr[200001],c,seg[400004];
ll merge(ll L, ll R) {
  return L + R;
}
void update(ll id, ll L, ll R, ll i, ll v) {
  if (L == R) {
    seg[id] += v;
    return;
  }
  ll M=(L+R)/2;
  if (i <= M) update(2*id+1,L,M,i,v);
  else update(2*id+2,M+1,R,i,v);
  seg[id] = merge(seg[2*id+1],seg[2*id+2]);
}
ll query(ll id, ll L, ll R, ll l, ll r) {
  if (L == l && r == R) return seg[id];
  ll M=(L+R)/2;
  if (r <= M) return query(2*id+1,L,M,l,r);
  else if (l >= M+1) return query(2*id+2,M+1,R,l,r);
  else return merge(query(2*id+1,L,M,l,M),query(2*id+2,M+1,R,M+1,r));
}
int main() {
  freopen("test.in","r",stdin);
  /* freopen("test.out","w",stdout); */
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n >> q;
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }
  for (int i=0;i<q;i++) {
    cin >> op >> a;
    if (op == 1) {
      cin >> b >> c;
      update(HEAD_NODE,0,n,a-1,c);
      update(HEAD_NODE,0,n,b,-c);
    } else {
      cout << arr[a-1] + query(HEAD_NODE,0,n,0,a-1) << endl;
    }
  }
  return 0;
}
