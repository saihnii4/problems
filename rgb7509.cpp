#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string _line;
    int temp;
    int i = 0;

    scanf("%d");
    cin.ignore();
    getline(cin, _line);

    istringstream ss(_line);

    while (ss >> temp)
        i |= (1 << temp);

    int n;
    cin >> n;

    printf("%s\n", i & (1 << n) ? "YES" : "NO");

    return 0;
}
