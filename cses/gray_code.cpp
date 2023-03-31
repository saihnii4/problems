#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

vector<string> root = {"0", "1"};

vector<string> generate(vector<string> base, int n) {
    if (n == 1) return base;

    vector<string> subset;
    vector<string> copy(base.begin(), base.end());

    reverse(copy.begin(), copy.end());

    vector<string> hybrid;
    hybrid.insert(hybrid.end(), base.begin(), base.end());
    hybrid.insert(hybrid.end(), copy.begin(), copy.end());

    for (int i = 0; i < 2; i++)  {
        for (int j = 0; j < copy.size(); j++) {
            subset.push_back(hybrid[j+copy.size()*i] + root[i]);
        }
    }

    return generate(subset, n - 1);
}

int main() {
    int n;
    cin >> n;

    vector<string> result = generate(root, n);

    for (string code : result) {
        cout << code << endl;
    }
}
