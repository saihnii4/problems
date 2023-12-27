#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#define HEAD 0
using namespace std;
template <typename T>
using vec = vector<T>;
using ll = long long;
vec<ll> arr;
struct st
{
    int n;
    vec<pair<pair<ll, ll>, pair<ll, ll>>> seg;
    st() : n(arr.size()), seg(4 * n + 1, {{0, 0}, {0, 0}})
    {
        build(HEAD, 0, n - 1);
    }
    static ll progress(ll init, ll diff, ll sz)
    {
        return init * sz + (sz * (sz - 1) >> 1) * diff;
    }
    static ll calculate(ll offsetSum, ll updates, ll sz)
    {
        return (updates * (sz) * (sz + 1) >> 1) + (offsetSum)*sz;
    }
    void build(ll id, ll L, ll R)
    {
        if (L == R)
        {
            seg[id] = {{arr[L], 0}, {0, 0}};
            return;
        }
        ll M = (L + R) / 2;
        build(2 * id + 1, L, M);
        build(2 * id + 2, M + 1, R);
        seg[id].first.first = seg[2 * id + 1].first.first + seg[2 * id + 2].first.first;
    }
    void push(ll id, ll L, ll R, ll orl, ll orr)
    {
        if (!seg[id].second.second)
            return;
        ll M = (L + R) / 2;
        seg[2 * id + 1].second.first += seg[id].second.first;
        seg[2 * id + 1].second.second += seg[id].second.second;
        seg[2 * id + 1].first.second = calculate(seg[2 * id + 1].second.first, seg[2 * id + 1].second.second, M - L + 1);

        seg[2 * id + 2].second.first += seg[id].second.first + (M - L + 1);
        seg[2 * id + 2].second.second += seg[id].second.second;
        seg[2 * id + 2].first.second = calculate(seg[2 * id + 2].second.first, seg[2 * id + 2].second.second, R - M);

        seg[id].second = {0, 0};
    }
    // use context
    void update(ll l, ll r) { update(HEAD, 0, n - 1, l, r, l, r); }
    void update(ll id, ll L, ll R, ll l, ll r, ll orl, ll orr)
    {
        if (l > r)
            return;
        if (L == l && r == R)
        {
            seg[id].second.first += l - orl;
            seg[id].second.second++;
            seg[id].first.second = calculate(seg[id].second.first, seg[id].second.second, R - L + 1);
            return;
        }
        push(id, L, R, orl, orr);
        ll M = (L + R) / 2;
        update(2 * id + 1, L, M, l, min(M, r), orl, orr);
        update(2 * id + 2, M + 1, R, max(l, M + 1), r, orl, orr);
        seg[id].first.second = seg[2 * id + 1].first.second + seg[2 * id + 2].first.second;
    }
    ll query(ll l, ll r) { return query(HEAD, 0, n - 1, l, r, l, r); }
    ll query(ll id, ll L, ll R, ll l, ll r, ll orl, ll orr)
    {
        if (l > r)
            return 0;
        if (L == l && r == R)
            return seg[id].first.first + seg[id].first.second;
        push(id, L, R, orl, orr);
        ll M = (L + R) / 2;
        return query(2 * id + 1, L, M, l, min(M, r), orl, orr) + query(2 * id + 2, M + 1, R, max(l, M + 1), r, orl, orr);
    }
};
int main()
{
    // freopen("sample", "r", stdin);
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