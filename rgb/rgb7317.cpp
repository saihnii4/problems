#include <stdio.h>
#include <map>
#include <set>

using namespace std;

long long x, y;

set< long long, greater<long long> > numbers;
map<long long, long long> freq;

long long min(long long a, long long b) { return a > b ? b : a; }
long long max(long long a, long long b) { return a > b ? a : b; }

void solve(long long x, long long y)
{
    if (x == y)
    {
        ++freq[x];
        numbers.insert(x);
        return;
    }

    long long a = min(x, y);
    long long b = max(x, y);

    numbers.insert(a);
    ++freq[a];

    return solve(b - a, a);
}

int main()
{
    scanf("%lld %lld", &x, &y);

    solve(x, y);

    for (long long number : numbers)
    {
        printf("%lld %lld\n", number, freq[number]);
    }
}