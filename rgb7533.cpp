#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int T, a = 0, a_, b = 100, b_, temp = 0;
    scanf("%d", &T);

    int arr[T];

    cin.ignore();
    string line;
    getline(cin, line);

    istringstream ss(line);
    
    for (int i = 0; i < T; i++) {
        ss >> temp; arr[i] = temp; }

    for (int i = 0; i < T; i++) {
        if (arr[i] > a) { a = arr[i]; a_ = i; }
        if (arr[i] <= b) { b = arr[i]; b_ = i; }
    }

    if (a_ > b_) printf("%d\n", a_ + T - b_ - 2);
    else printf("%d\n", a_ + T - b_ - 1);

    return 0;
}
