#include <stdio.h>
#include <vector>

using namespace std;

long long n, x, count = 0;

void generate(long long arr[], long long i, long long sum, bool traversed[]) {
    if (sum == x) {
        if (traversed[i]) return;
        traversed[i] = true;
        ++count;
        return;
    }
    if (i == n - 1) return; 
    generate(arr, i+1, sum + arr[i + 1], traversed);
    generate(arr, i+1, arr[i + 1], traversed);
}

int main() {
    scanf("%lld %lld", &n, &x);
    bool traversed[n];
    long long arr[n];

    for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);

    generate(arr, 0, arr[0], traversed);

    printf("%lld\n", count);
    return 0;
}
