// TODO:

#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, m, N = 2e5, price;
long long INF = 10e10;
long long MAX = 10e4;
bool traversed[10000];

int main()
{
    long long customers[N];
    vector<long long> prices;

    scanf("%d %d", &n, &m);

    int j = n;
    for (int i = 0; i < n; i++)
    {
        long long t;
        scanf("%lld", &t);
        prices.push_back(t);
    }

    sort(prices.begin(), prices.end());

    for (int i = 0; i < m; i++)
    {
        scanf("%lld", &customers[i]);
    }

    for (int i = 0; i < m; i++)
    {
        int l = 0, r = n - 1, mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            printf("%lld %lld %lld %d\n", l, r, prices[mid], mid);

            if (prices[mid] < customers[i] && prices[mid + 1] > customers[i])
            {
                l = mid;
                r = mid;
                break;
            }

            if (prices[mid] >= customers[i])
                r = mid - 1;
            else
                l = mid + 1;
        }
        if (traversed[l])
            while (traversed[l])
                --l;

        if (l == -1) {
            printf("-1\n");
            continue;
        } else {
            printf("%d\n", prices[l]);
        }
        traversed[l] = true;
    }
}