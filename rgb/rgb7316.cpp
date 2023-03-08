#include <stdio.h>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (a == 0 || b == 0) return std::max(a, b);

    return gcd(min(a, b), max(a, b) % min(a, b));
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int ma = max(max(a, b), c);
    int mi = min(min(a, b), c);
    int m = a+b+c - (ma + mi);
    int gc = gcd(ma, mi);
    int lc = (int)(ma*mi/gc);
    printf("%d\n", (int)(lc*m/gcd(lc, m)));
}
