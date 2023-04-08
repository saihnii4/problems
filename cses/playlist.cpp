// TOOO:

#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    int n, max = 0;
    scanf("%d", &n);
    long long arr[n];
    set<long long> songs;

    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    vector<long long> sub;

    for (int i = 0; i < n; i++)
    {
        if (songs.find(arr[i]) != songs.end())
            sub.erase(sub.begin(), find(sub.begin(), sub.end(), arr[i]) + 1);

        songs.insert(arr[i]);
        sub.push_back(arr[i]);

        if (sub.size() > max)
            max = sub.size();
    }

    printf("%d\n", max);
}
