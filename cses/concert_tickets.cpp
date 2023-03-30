// TODO:

#include <iostream>
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
    multiset<long long> prices;

    scanf("%d %d", &n, &m);

    int j = n;
    for (int i = 0; i < n; i++)
    {
        long long t;
        scanf("%lld", &t);
        prices.insert(t);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%lld", &customers[i]);
        auto result = prices.upper_bound(customers[i]);
        if (result == prices.begin()) {
            printf("-1\n");
        } else {
            --result;
            prices.erase(result);
            cout << *result << endl;
        }
    }
}