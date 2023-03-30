// TODO:

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, N = 2e5, price;
long long INF = 10e10;
long long MAX = 10e4;

int main()
{
    long long customers[N], traversed[MAX];
    vector<long long> prices;

    scanf("%d %d", &n, &m);

    int j = n;
    for (int i = 0; i < n; i++) {
        long long t;
        scanf("%lld", &t);
        prices.push_back(t);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%lld", &customers[i]);
    }

    for (int i = 0; i < m; i++) {
        int max = -1;
        int k = -1;
        for (int j = 0; j < n; j++) {
            if (customers[i] < prices[j]) continue;
            if (prices[j] > max) {
                max = prices[j];
                k = j;
            }
        }
        if (k == -1) printf("-1\n");
        else {
            prices[k] = -1;
            printf("%d\n", max);
        }
    }
}