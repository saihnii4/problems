// gray code time

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> generate(int n) {
    if (n <= 1) return vector<string>{"0", "1"};

    vector<string> mini_poss;

    vector<string> p = generate(n - 1);
    for (string l : p) {
        mini_poss.push_back('0' + l);
        mini_poss.push_back('1' + l);
    }

    return mini_poss;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<string> fuckme = generate(n);

    sort(fuckme.begin(), fuckme.end());

    for (string s : fuckme) {
        cout << s << endl;
    }
}
