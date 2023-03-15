#include <stdio.h>
#include <vector>

int main() {
    long long k, n;
    scanf("%lld %lld", &k, &n);

    std::vector<int> a;

    if ((int)(k / n) > 0) a.push_back(k - n);
    if ((k % n) != 0) a.push_back(k + 1);
    if ((int)((k + n) < n*n)) a.push_back(k + n);
    if ((k - 1) % n != 0) a.push_back(k - 1);

    for (int i = 0; i < a.size(); i++) {
        printf("%d", a[i]);
        if (i != a.size() - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
