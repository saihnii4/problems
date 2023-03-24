#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    cin >> a;
    int l = 0;
    char temp = a[0];
    int d = 0;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == temp) ++d;
        else {
            if (d > l) l = d;
            d = 1;
            temp = a[i];
        }
    }

    if (d > l) l = d;

    printf("%d\n", l);
}
