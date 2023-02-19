#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    int T;
    vector<int> arr;
    while (scanf("%d", &T) != EOF) {
        if (T == 42) break;
        arr.push_back(T);
    }

    for (int i : arr) printf("%d\n", i);
}
