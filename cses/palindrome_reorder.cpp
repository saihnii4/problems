#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    bool c = false;

    cin.ignore();
    cin >> a;
    cout << a << endl;

    string b = a;
    string g = "";

    sort(b.begin(), b.end());

    char d, f = 'c';

    int e = 0;
    for (int i = 0; i < b.size(); i++) {
        if (i == 0) d = b[i];
        if (b[i] == d) ++e;
        if (b[i] != d) {
            printf("%c %d\n", d, e);
            if ((e & 1) != 0) {
                if (c) {
                    printf("NO SOLUTION\n");
                    return 0;
                }

                c = true;
                f = b[i];
                d = b[i];
                e = 0;

                continue;
            }

            for (int j = 0; j < (int)(e/2); j++) {
                g += d;
            }

            e = 0;
            d = b[i];
        }
    }

    g += f;

    cout << g << endl;
}
