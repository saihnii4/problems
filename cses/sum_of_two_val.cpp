#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
int T, l, r;
long long x;
 
int main() {
    scanf("%d %lld", &T, &x);
    long long arr[T];
 
    for (int i = 0; i < T; i++) scanf("%lld", &arr[i]);
 
    for (int i = 0; i < T; i++) {
        auto res = find(arr, arr+T, x - arr[i]);
        if (res != arr+T && res != arr+i) {
            printf("%d %ld\n", i+1, res - arr + 1);
            return 0;
        }
    }
 
    printf("IMPOSSIBLE\n");
 
    return 0;
}