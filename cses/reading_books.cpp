// verrry convoluted
// luckily, an O(n) simulation will suffice :)

#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n;
long long time, turnabout;

int main() {
    scanf("%d", &n);
    long long books[n];
    int i = 0, j = n -1;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &books[i]);
    }

    sort(books, books + n);

    // degenerate case
    if (n == 1) {
        printf("%lld\n", books[0] * 2);
        return 0;
    }

    while (j >= 0) {
        if (i == j) {
            if (time < books[i]) time += books[i] - time;
            turnabout = time;
            --j;
            continue;
        }

        if (j == 0) {
            time += books[i] - (time - turnabout);
            break;
        }
    
        if (i < n && time < books[j]) {
            time += books[i];
            ++i;
            continue;
        } else {
            time += books[j];
            --j;
        }
    }

    printf("%lld\n", time);

    return 0;
}
