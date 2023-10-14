// TODO: wrong approach!
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
using ll = long long;
int t, n, arr[100000], ct;
ll sum, ans;
unordered_map<int, int> p;
int main()
{
    p[0] = 0;
    cin >> t;
    while (t--)
    {
        ct = 0;
        string str;
        cin >> n;
        cin >> str;
        for (int i = 0; i < n; i++) {
            p[i + 1] = p[i] + str.c_str()[i] - '0';

        for (int i = 0; i < n; i++)
        {
            sum += p[i + 1] - p[i];
            if (p.count(sum - n))
            {
                ans += p[sum - n];
            }
            ++p[sum];
        }
        cout << ans << endl;
    }
    return 0;
}