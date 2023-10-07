#include <iostream>
#include <utility>
#define HEAD_NODE 0
using namespace std;
typedef long long ll;
typedef pair<ll, ll> node;
int n, q;
ll arr[200000];
node seg[800000];
node merge(node a, node b)
{
    if (a.first >= b.first)
        return a;
    return b;
}
void build(ll id, ll L, ll R)
{
    if (L == R)
    {
        seg[id] = {arr[L], L};
        return;
    }
    ll M = (L + R) / 2;
    build(2 * id + 1, L, M);
    build(2 * id + 2, M + 1, R);
    seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
}
node query(ll id, ll L, ll R, ll k)
{
    if (L == R)
        return seg[id];
    ll M = (L + R) / 2;
    if (seg[2 * id + 1].first >= k)
        return query(2 * id + 1, L, M, k);
    else
        return query(2 * id + 2, M + 1, R, k);
}
void update(ll id, ll L, ll R, ll k)
{
    if (L == R)
    {
        seg[id].first -= k;
        return;
    }
    ll M = (L + R) / 2;
    if (seg[2 * id + 1].first >= k)
        update(2 * id + 1, L, M, k);
    else
        update(2 * id + 2, M + 1, R, k);
    seg[id] = merge(seg[2 * id + 1], seg[2 * id + 2]);
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
        ll t;
        cin >> t;
        if (seg[HEAD_NODE].first < t)
            printf("0 ");
        else
        {
            printf("%lld ", query(HEAD_NODE, 0, n - 1, t).second + 1);
            update(HEAD_NODE, 0, n - 1, t);
        }
    }
    printf("\n");
    return 0;
}