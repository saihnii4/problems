#include <iostream>
#include <utility>
#define HEAD_NODE 0
using namespace std;
typedef long long ll;
typedef pair<ll, ll> node;
ll arr[200000];
int n,m,a,b;
node seg[800000];
node merge(node a, node b)
{
    if (a.first % 2 == 0)
    {
        return {a.first + 1, a.second | b.second};
    }
    else
    {
        return {a.first + 1, a.second ^ b.second};
    }
}
void build(ll id, ll L, ll R)
{
    if (L == R)
    {
        seg[id] = node(0, arr[L]);
        return;
    }
    ll M=(L+R)/2;
    build(2 * id + 1, L, M);
    build(2 * id + 2, M + 1, R);
    seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
}
node query(ll id, ll L, ll R, ll l, ll r) {
    if (L == l && r == R) return seg[id];
    ll M = (L+R)/2;
    if (r <= M) return query(2*id+1, L, M, l, r);
    else if (l >= M+1) return query(2*id+2,M+1,R,l,r);
    else return merge(query(2*id+1,L,M,l,M),query(2*id+2,M+1,R,M+1,r));
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < (1 << n); i++)
    {
        cin >> arr[i];
    }
    build(HEAD_NODE,0,n-1);
    for (int i=0;i<m;i++) {
        cin>>a>>b;
        printf("%lld\n", query(HEAD_NODE,0,n-1,a-1,b-1).second);
    }
    return 0;
}