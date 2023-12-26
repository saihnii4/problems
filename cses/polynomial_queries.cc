#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <limits>
#define HEAD 0
using namespace std;
using ll = long long;
vector<ll> arr;
struct st
{
    int n;
    vector<pair<ll, pair<ll, ll>>> seg;
    st() : n(arr.size()), seg(4 * n + 1, {0, {0, 0}}) { build(HEAD, 0, n - 1); }
    void build(ll id, ll L, ll R)
    {
        if (L == R)
        {
            seg[id].first = arr[L];
            return;
        }
        ll M = (L + R) / 2;
        build(2 * id + 1, L, M);
        build(2 * id + 2, M + 1, R);
        seg[id].first = seg[2 * id + 1].first + seg[2 * id + 2].first;
    }
    void apply(ll id, ll sz, ll freq)
    {
        seg[id].second.first = freq * sz * (sz + 1) >> 1;
        seg[id].second.second += freq;
    }
    void push(ll id, ll L, ll R)
    {
        ll M = (L + R) / 2;
        apply(2 * id + 1, M - L + 1, seg[id].second.second);
        apply(2 * id + 2, R - M, seg[id].second.second);
        seg[id].second.second = 0;
    }
    void update(ll l, ll r)
    {
        update(HEAD, 0, n - 1, l, r);
    }
    void update(ll id, ll L, ll R, ll l, ll r)
    {
        if (l > r)
            return;
        if (L == l && r == R)
        {
            seg[id].second.second++;
            seg[id].second.first = seg[id].second.second * (r - l + 1) * (r - l + 2) >> 1;
            return;
        }
        push(id, L, R);
        ll M = (L + R) / 2;
        update(2 * id + 1, L, M, l, min(r, M));
        update(2 * id + 2, M + 1, R, max(l, M + 1), r);
        seg[id].first = seg[2 * id + 1].first + seg[2 * id + 2].first;
        seg[id].second.first = seg[2*id+1].second.first + seg[2*id+2].second.first;
    }
    ll query(ll l, ll r) { return query(HEAD, 0, n - 1, l, r); }
    ll query(ll id, ll L, ll R, ll l, ll r)
    {
        if (l > r)
            return 0;
        if (L == l && r == R)
            return seg[id].first + seg[id].second.first;
        push(id, L, R);
        ll M = (L + R) / 2;
        return query(2 * id + 1, L, M, l, min(M, r)) + query(2 * id + 2, M + 1, R, max(l, M + 1), r);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sample", "r", stdin);
    int n, q;
    cin >> n >> q;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    auto tree = st();
    int op, a, b;
    for (int i = 0; i < q; i++)
    {
        cin >> op >> a >> b;
        if (op == 1)
        {
            tree.update(a - 1, b - 1);
        }
        else
        {
            cout << tree.query(a - 1, b - 1) << endl;
        }
    }
    return 0;
}