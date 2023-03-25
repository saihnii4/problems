#include <iostream>
#include <string.h>
#include <string>
#include <set>

using namespace std;

int main() {
    string a;
    cin >> a;

    bool odd = false;
    string odd_appender = "";

    string f = "";

    set<char> letters;
    
    for (int i = 0; i < a.size(); i++) letters.insert(a[i]);

    for (char letter : letters) {
        long long times = 0;
        size_t pos = 0;

        while (a.find(letter, pos) != string::npos) {
            pos = a.find(letter, pos) + 1;
            ++times;
        }

        if ((times & 1) != 0) {
            if (odd) {
                printf("NO SOLUTION\n");
                return 0;
            }

            odd = true;
            for (int i = 0; i < times; i++) odd_appender += letter;
            continue;
        }

        for (long long i = 0; i < (long long)(times / 2); i++) f += letter;
    }

    string e = f + odd_appender;
    for (long long i = 0; i < f.size(); i++) e += f[f.size()-i-1];

    cout << e << endl;

    return 0;
}
