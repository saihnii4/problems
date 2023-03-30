#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    long long arr[T];

    for (int i = 0; i < T; i++)
        scanf("%lld", &arr[i]);

    sort(arr, arr + T);

    long long mid = arr[(long long)(T / 2)];
    long long cost = 0;

    for (int i = 0; i < T; i++)
    {
        cost += abs(arr[i] - mid);
    }

    printf("%lld\n", cost);
    return 0;
}