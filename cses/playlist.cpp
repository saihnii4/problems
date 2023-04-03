#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    int n, max = 0;
    scanf("%d", &n);
    long long arr[n];

    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    vector<long long> sub;

    for (int i = 0; i < n; i++)
    {
        sort(sub.begin(), sub.end());
        if (find(sub.begin(), sub.end(), arr[i]) != sub.end())
            sub.erase(sub.begin(), find(sub.begin(), sub.end(), arr[i]) + 1);

        sub.push_back(arr[i]);

        if (sub.size() > max)
            max = sub.size();
    }

    printf("%d\n", max);
}