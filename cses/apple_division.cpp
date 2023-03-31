#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

long long sum;
int T;
long long mid;
long long minima = 1e9;

vector<long long> arr;

long long solve(int i, long long s, vector<long long> tmp)
{
    if (minima == 0) return minima;

    if (i == T)
        return 0;

    if (abs(sum - 2 * s) < minima)
        minima = abs(sum - 2 * s);

    solve(i + 1, s, tmp);
    solve(i + 1, s - tmp[i], tmp);

    return minima;
}

int main()
{
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        long long t;
        scanf("%lld", &t);
        arr.push_back(t);
        sum += t;
    }

    solve(0, sum, arr);

    printf("%lld\n", minima);
    return 0;
}