#include <stdio.h>
#include <unordered_map>
#include <math.h>
#include <algorithm>

using namespace std;

int n;
int ct = 0;
unordered_map<long long, int> m;

int mod(int a, int b) {
  return (a < 0) ? b-abs(a)% b : (a % b);
}

int main() {
  scanf("%d", &n);
  long long arr[n];
  int mrq[n + 1];

  mrq[0] = 0;

  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
    mrq[i + 1] = mod((arr[i] + mrq[i]), n); 
  }

  for (int i = 0; i <= n; i++) {
    m[mrq[i]]++;
  }

  for (auto& it : m) {
    ct += ((it.second)*(it.second-1)) >> 1;
  }

  printf("%d\n", ct);
}
