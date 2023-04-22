#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

set<long long> s;
long long x;

int main()
{
    int n;
    scanf("%d %lld", &n, &x);
    long long arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        s.insert(arr[i]);
    }

    for (int i = 0; i < n; i++)
        if (n > 1)
        {
            long long se = x - arr[i];

            if (s.find(se) == s.end())
                continue;

            int j = find(arr, arr + n, se) - arr;
            if (i == j) continue;

            printf("%d %d\n", i + 1, j + 1);
            return 0;
        }

    printf("IMPOSSIBLE\n");
}
