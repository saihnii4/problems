#include <iostream>
#include <math.h>
using namespace std;
int t, arr[20];
void solve() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    for (int i=1;i<=n;i*=2) {
        while (arr[i] < arr[i-1]) {
            cout << arr[i] << ' ' << arr[i-1] << endl;
            for (int j=0;j<i;j++) {
                arr[j]--;
            }
        }
    }

    for (int i=0;i<n;i++) {
        cout << arr[i] << endl;
    }

    for (int i=0;i<n;i++) {
        if (arr[i] <= 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main() {
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
