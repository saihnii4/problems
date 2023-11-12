#include <iostream>
using namespace std;
using ll = long long;
int n, k, t;
ll arr[10000];
int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        for (int i=1;i<=k;i++) {
            for (int i=0;i<n;i++) {
                if (arr[i] & i != 0) break;
            }
        }
    }
    return 0;
}