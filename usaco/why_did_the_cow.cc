#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
ll n,k,b,arr[100000],ps[100001],ans;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  freopen("maxcross.in","r",stdin);
  freopen("maxcross.out","w",stdout);
  cin >> n >> k >> b;
  for (int i=0;i<n;i++) {
    arr[i]=1;
  }
  for (int i=0;i<b;i++) {
    int t;
    cin>>t;
    arr[t-1] = 0;
  }
  ps[0] = 0;
  for (int i=0;i<n;i++) {
    ps[i+1] = ps[i] + arr[i];
  }
  for (int i=0;i<=n-k;i++) {
    ans = max(ans, ps[i+k]-ps[i]);
  }
  cout << k-ans << endl;
}
