#include <stdio.h>
#include <set>
 
using namespace std;
 
int main() {
    int n;
    scanf("%d", &n);
    multiset<long long> towers;
 
    for (int i = 0; i < n; i++) {
        long long x;
        scanf("%lld", &x);
 
        auto tower = towers.upper_bound(x);
        long long number = *tower;
 
        if (tower == towers.end()) {
            towers.insert(x);
            continue;
        }
 
        towers.erase(towers.find(number));
        towers.insert(x);
    }
 
    printf("%ld\n", towers.size());
    return 0;
}
