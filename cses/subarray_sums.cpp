#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

bool memo[200000];
long long n, x;
long long coun = 0;

void generate(long long arr[], long long i, long long sum) {
    if (i == n - 1) return;
    if (sum == x) {
        ++coun;
    }

    if (!memo[i]) {
        memo[i] = true;
        generate(arr, i + 1, arr[i + 1]);
    }

    generate(arr, i + 1, sum+arr[i + 1]);
}

int main() {
    memset(memo, false, sizeof(bool)*200000);

    scanf("%lld %lld", &n, &x);
    long long arr[n];

    for (long long i = 0; i < n; i++) scanf("%lld", &arr[i]);
    generate(arr, 0, arr[0]);

    printf("%lld\n", coun);
}
