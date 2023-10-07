#include <iostream>
#define HEAD_NODE 0
using namespace std;
typedef long long ll;
int n, q, op;
ll arr[200000], a, b;
ll max(ll a, ll b) { return (a > b) ? a : b; }
ll max(ll a, ll b, ll c)
{
    ll d = (a > b) ? a : b;
    ll e = (b > c) ? b : c;
    return (d > e) ? d : e;
}
struct node
{
    ll sol;
    ll pref;
    ll suf;
    ll sum;
};
node merge(node a, node b)
{
    ll pref = max(0, max(a.pref, a.sum + b.pref));
    ll suf = max(0, max(b.suf, b.sum + a.suf));
    ll sum = a.sum + b.sum;
    ll sol = max(0, max(a.sol, b.sol, a.suf + b.pref));
    return {sol, pref, suf, sum};
}
node seg[800000];
void build(ll id, ll L, ll R)
{
    if (L == R)
    {
        seg[id] = {arr[L], max(0, arr[L]), max(0, arr[L]), max(0, arr[L])};
        return;
    }
    ll M = (L + R) / 2;
    build(2 * id + 1, L, M);
    build(2 * id + 2, M + 1, R);
    seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
}
void update(ll id, ll L, ll R, ll a, ll b)
{
    if (L == R)
    {
        seg[id] = {b, max(0, b), max(0, b), max(0, b)};
        return;
    }
    ll M = (L + R) / 2;
    if (a <= M)
        update(2 * id + 1, L, M, a, b);
    else
        update(2 * id + 2, M + 1, R, a, b);
    seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
}
node query(ll id, ll L, ll R, ll a, ll b)
{
    if (L == R)
        return seg[id];
    ll M = (L + R) / 2;
    if (b <= M)
        return query(2 * id + 1, L, M, a, b);
    else if (a >= M + 1)
        return query(2 * id + 2, M + 1, R, a, b);
    else
        return merge(query(2 * id + 1, L, M, a, M), query(2 * id + 2, M + 1, R, M + 1, b));
}
int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(HEAD_NODE, 0, n - 1);
    for (int i = 0; i < q; i++)
    {
        cin >> op >> a >> b;
        if (op == 1)
            update(HEAD_NODE, 0, n - 1, a, b);
        else
            printf("%lld\n", query(HEAD_NODE, 0, n - 1, a - 1, b - 1).pref);
    }
}