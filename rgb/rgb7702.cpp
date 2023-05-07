#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int n, k, i, j, ct;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int m[n];
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }

    cin >> k;
    int w[k];
    for (int i = 0; i < k; i++)
    {
        cin >> w[i];
    }

    sort(m, m + n);
    sort(w, w + k);

    while (i < n)
    {
        if (abs(m[i] - w[j]) <= 1) {
            ++i;
            ++j;
            ++ct;
            continue;
        }

        if (m[i] - w[j] < 0) ++i;
        else ++j;
    }

    printf("%d\n", ct);
}