#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<string> poss;
vector<string> letters;

set<string> generate(int n, vector<string> avail) {
    if (n <= 1) return set<string>(avail.begin(), avail.end());

    set<string> poss;
    for (string i : avail) {
        vector<string> copy(avail.begin(), avail.end());
        copy.erase(find(copy.begin(), copy.end(), i));

        set<string> l = generate(n - 1, copy);

        for (string k : l) {
            poss.insert(i + k);
        }
    }

    return poss;
}

int main() {
    string a;
    cin >> a;

    for (char i : a) letters.push_back(std::string() + i);

    set<string> poss = generate(a.size(), vector<string>(letters.begin(), letters.end()));
    vector<string> po(poss.begin(), poss.end());
    sort(po.begin(), po.end());

    cout << po.size() << endl;
    for (string p : po) cout << p << endl;
}
