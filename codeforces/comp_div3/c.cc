#include <iostream>
#include <cstring>
#include <string>
using namespace std;
using ll = long long;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        char ns[n];
        strcpy(ns, s.c_str());
        for (int i = 0; i < s.size(); i++)
        {
            if (i == s.size()-1 && ns[i] == 'a') {
                ns[i] = (k % 2 == 0) ? 'a' : 'b';
                continue;
            }
        
            ll val = min(ns[i] - 'a', 'z' - ns[i] + 1);
            k -= val;
        
            if (k <= 0)
            {
                ns[i] = 'a' - k;
                break;
            }

            if (ns[i] - 'a' < 'z' - ns[i] + 1)
            {
                ns[i] -= val;
            }
            else
            {
                ns[i] = 'a';
            }
        }
        cout << ns << endl;
    }
    return 0;
}