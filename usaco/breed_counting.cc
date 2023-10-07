#include <iostream>
#include <tuple>
using namespace std;
int n, q;
typedef long long ll;
typedef tuple<ll, ll, ll> node;
void setIO(string name = "")
{
    cin.tie(0)->sync_with_stdio(0);
    if (name.size())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
node p[100001];

int main()
{
    p[0] = node(0, 0, 0);
    setIO("bcount");
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        p[i + 1] = p[i];
        int a;
        cin >> a;
        if (a == 1)
            get<0>(p[i + 1])++;
        else if (a == 2)
            get<1>(p[i + 1])++;
        else
            get<2>(p[i + 1])++;
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << get<0>(p[b]) - get<0>(p[a - 1]) << ' ' << get<1>(p[b]) - get<1>(p[a - 1]) << ' ' << get<2>(p[b]) - get<2>(p[a - 1]) << endl;
    }
}