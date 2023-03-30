#include <utility>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

typedef pair<long long, long long> movie;

bool cmp(movie a1, movie a2)
{
    return (a1.second < a2.second);
}

int main()
{
    int T;
    scanf("%d", &T);

    vector<movie> movies;

    for (int i = 0; i < T; i++)
    {
        long long a, b;
        scanf("%lld %lld", &a, &b);

        movies.push_back(pair<long long, long long>(a, b));
    }

    sort(movies.begin(), movies.end(), cmp);

    long long time = 0, count = 0;

    for (movie mov : movies) {
        if (time > mov.first) continue;
        ++count;
        time = mov.second;
    }

    printf("%lld\n", count);
}