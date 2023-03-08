#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    char c;
    cin >> a >> c;
    int sum = 0;

    for (int i = 0; i < a.size(); i++) if (a.c_str()[i] == c) ++sum;

    printf("%d\n", sum);

    return 0;
}
