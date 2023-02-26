// TODO: no <vector>
#include <vector>
#include <stdio.h>
using namespace std;

vector<int> arr;

long long factorial(int n) {
    if (n == 1) return 1;
    long long v=factorial(n-1);
    arr.push_back(v);
    return v*n;
}

int main() {
    int n;
    scanf("%d", &n);

    long long v = factorial(n);
    for (int i = 0; i < arr.size(); i++)
        printf("%d!=%d\n", i+1, arr[i]);

    printf("%d!=%d\n", n, v);
}
