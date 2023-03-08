#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
using namespace std;

int main() {
    string a;
    cin >> a;
    char b[a.size()];
    for (int i = 0; i < a.size(); i++) b[a.size()-i] = a[i];
    printf("%s %s\n", a.c_str(), b);
    printf("%s\n", (strcmp(a.c_str(), b) == 0) ? "YES" : "NO");
}
