#include <stdio.h>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (a == 0 || b == 0) return std::max(a, b);

    return gcd(min(a, b), max(a, b) % min(a, b));
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int gc = gcd(a, b);
    printf("%d/%d\n", (int)(a/gc), (int)(b/gc));
}

