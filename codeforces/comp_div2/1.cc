#include <iostream>
using namespace std;
using ll = long long;
int n,t;
        ll efficiency;
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        ll arr[n-1];
        efficiency = 0;
        for (int i=1;i<n;i++) {
            cin>>arr[i];
            efficiency+=arr[i];
        }
        cout << -efficiency << endl;
    }
    return 0;
}