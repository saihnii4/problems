#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int n, m;
vector<ll> seg(400000);
void build() {
  for (int i = n - 1; i > 0; i--) seg[i]=seg[i<<1]+seg[i<<1|1];
}
int main() {
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    cin >> seg[n+i];
  }
  for (int i=0;i<m;i++) {
    ll k;
    cin >> k;
    cout << tree.query(k) << endl;
  }
}
