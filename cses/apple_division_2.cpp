#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>

using namespace std;

long long sum(vector<long long> a) {
    long long sum = 0;
    for (long long i : a) {
        sum += i;
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<long long> arr;
    vector<long long> g1;
    vector<long long> g2;

    for (int i = 0; i < n; i++) {
        long long t;
        cin >> t;
        arr.push_back(t);
    }

    long long orig = sum(arr);

    sort(arr.begin(), arr.end());

    long long max = arr[arr.size() - 1];
    g1.push_back(max);
    arr.pop_back();
    orig -= max;

    while (true) {
        bool altered = false;
        long long diff = sum(g1) - sum(arr);
        cout << diff << " " << arr.size() << endl;
        long long min;
        long long min_diff;
        int min_i = -1;

        if (diff > 0) {
            for (int i = 0; i < arr.size(); i++) {
                if (i == 0) min = arr[i];
                if (abs(diff - 2*arr[i]) < abs(diff)) {
                    min_diff = diff - 2*arr[i];
                    min = arr[i];
                    min_i = i;

                    altered = true;
                }
            }

            arr.push_back(min);
        } else {
            for (int i = 0; i < arr.size(); i++) {
                if (i == 0) min = arr[i];
                if (abs(diff + 2*arr[i]) < abs(diff)) {
                    min_diff = diff + 2*arr[i];
                    min = arr[i];
                    min_i = i;

                    altered = true;
                }
            }

            g1.push_back(min);
        }

        if (min_i != -1) arr.erase(arr.begin()+min_i);
        if (not altered) break;
    }

    for (long long i : g1) {
        cout << i << endl;
    }

    for (long long i : g2) {
        cout << i << endl;
    }
}
