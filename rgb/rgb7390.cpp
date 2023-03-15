#include <iostream>
#include <string>

using namespace std;

int factorial(int a) {
    if (a == 0) return 1;
    return a*factorial(a - 1);
}

int main() {
    string a;
    cin >> a;

    printf("%d\n", (int)(factorial((int)(a.size()/2))/2));
}
