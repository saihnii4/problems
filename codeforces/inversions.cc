#include <iostream>
#define HEAD_NODE 0
using namespace std;
typedef long long ll;
int n;
ll seg[400000];
void build(ll id, ll L, ll R)
{
    if (L == R)
    {
        seg[id] = 0;
        return;
    }
    ll M = (L + R) / 2;
    build(2 * id + 1, L, M);
    build(2 * id + 2, M + 1, R);
}
ll query(ll id, ll L, ll R, ll l, ll r)
{
    if (L == l && r == R)
        return seg[id];
    ll M = (L + R) / 2;
    if (l >= M + 1)
        return query(2 * id + 2, M+ 1, R, l, r);
    else
        return query(2 * id + 1, L, M, l, M) + query(2 * id + 2, M + 1, R, M + 1, r);
}
void update(ll id, ll L, ll R, ll k)
{
    if (L == R)
    {
        seg[id] = 1;
        return;
    }

    ll M = (L + R) / 2;
    if (k <= M)
        update(2 * id + 1, L, M, k);
    else
        update(2 * id + 2, M + 1, R, k);
    seg[id]=seg[2*id+1]+seg[2*id+2];
}
int main()
{
    cin >> n;
    build(HEAD_NODE, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t < n) cout << query(HEAD_NODE, 0, n - 1, t-1, n-1) << endl;
        else cout << 0 << endl;
        update(HEAD_NODE, 0, n - 1, t);
    }
    return 0;
}