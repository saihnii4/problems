#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    string a;
    cin >> a;

    reverse(a.begin(), a.end());
    cout << a[1] << endl;
}
