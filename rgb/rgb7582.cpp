#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> m;

bool sorted() {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > arr[i-1]) return false;
    }

    return true;
}

int main() {
    int n;
    int i = 0;

    while (scanf("%d", &n) != EOF)
        arr.push_back(n);

    for (int i = 0; i < arr.size(); i++) m.push_back(i+1);

    while (not sorted()) {
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i-1]) {
                std::swap(arr[i], arr[i-1]);
                std::swap(m[i], m[i-1]);
            }
        }
    }

    for (int i = 0; i < m.size(); i++) {
        printf("%d\n", m[i]);
    }

    return 0;
}
