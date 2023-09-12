#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<long long> medians;

int main() {
  scanf("%d %d", &n, &k);
  long long arr[n];
  multiset<long long> window;

  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }
}
