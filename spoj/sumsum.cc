#include <iostream>
#include <functional>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> arr;
struct ft
{
    int n;
    vector<ll> bit;
    function<ll(ll, ll)> operation;
    ft(function<ll(ll, ll)> op) : n(arr.size()), bit(n, 0), operation(op)
    {
        for (int i = 0; i < n; i++)
        {
            bit[i] += arr[i];
            int r = i | (i + 1);
            if (r < n)
                bit[r] += bit[i];
        }
    }
    void update(ll i, ll v)
    {
        for (; i < n; i |= (i + 1))
        {
            bit[i] = operation(bit[i], v);
        }
    }
    ll query(ll l, ll r)
    {
        return query(r) - query(l - 1);
    }
    ll query(ll i)
    {
        ll ans = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
        {
            ans = operation(ans, bit[i]);
        }
        return ans;
    }
};
int main()
{
    freopen("sample", "r", stdin);
    int n, m;
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int q, a, b, c;
    string op;
    auto or_op = [](ll a, ll b)
    {
        return a | b;
    };
    auto and_op = [](ll a, ll b)
    {
        return a & b;
    };
    auto tree1 = ft(or_op);
    auto tree2 = ft(and_op);
    for (int i = 0; i < m; i++)
    {
        cin >> q;
        if (q == 1)
        {
            cin >> a >> b;
            tree1.update(a, b);
            tree2.update(a, b);
        }
        else
        {
            cin >> op >> a >> b;
            if (strcmp(op.c_str(), "OR") == 0)
            {
                cout << tree1.query(a, b) << endl;
            }
            else
            {
                cout << tree2.query(a, b) << endl;
            }
        }
    }
    return 0;
}