// TODO:

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    long long arr[T];

    for (int i = 0; i < T; i++) scanf("%lld", &arr[i]);

    sort(arr, arr + T);

    long long sum = 1;

    for (int i = 0; i < T; i++) {
        if (arr[i] > sum) break;
        sum += arr[i];
    }

    printf("%lld\n", sum);
}
