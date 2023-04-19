#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

bool cmp(pair<long long, long long> a1, pair<long long, long long> a2)
{
    return a1.first < a2.first;
}

int main()
{
    long long n;
    scanf("%lld", &n);
    vector<pair<long long, long long> > tasks;

    for (long i = 0; i < n; i++)
    {
        long long a, b;
        scanf("%lld %lld", &a, &b);

        tasks.push_back(pair<long long, long long>(a, b));
    }

    std::sort(tasks.begin(), tasks.end(), cmp);

    long long agg = 0, sum = 0;

    for (long long i = 0; i < tasks.size(); i++)
    {
        pair<long long, long long> task = tasks[i];
        agg += task.first;
        sum += task.second - agg;
    }

    printf("%lld\n", sum);
}
