#include <iostream>
#include <string>
using namespace std;
using ll = long long;
string sarr[1000001];
int main()
{
    ll n;
    cin >> n;
    while (n--)
    {
        ll t, k;
        string s;
        string sarr[k + 1];
        cin >> t >> k;
        cin >> s;
        sarr[0] = s;
        for (int i = 1; i <= k; i++)
        {
            string test = sarr[i - 1];
            reverse(sarr[i - 1].begin(), sarr[i - 1].end());
            if (test == sarr[i - 1])
            {
                reverse(sarr[i - 1].begin(), sarr[i - 1].end());
                sarr[i] = sarr[i - 1] + (*sarr[i - 1].rend());
            }
            else
            {
                reverse(sarr[i - 1].begin(), sarr[i - 1].end());
                sarr[i] = string(&sarr[i - 1].c_str()[n / 2]);
            }
        }
        cout << sarr[t];
    }
}