#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string a;
    cin >> a;

    int sum = 0;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] - '0' == 0) break;
        if (i == a.size() - 1) {
            printf("-1\n");
            return 0;
        }

        sum += a[i] - 48;
    }

    if (sum % 3 == 0) {
        printf("-1\n");
        return 0;
    }

    std::sort(a.begin(), a.end());

    for (int i = a.size() - 1; i >= 0; i--) {
        printf("%c", a[i]);
    }
    printf("\n");
    return 0;
}
