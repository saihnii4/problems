// knapsack
#include <utility>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
using ll = long long;
typedef pair<ll, ll> product;
int n, k, t = 0;
product cmp(product a, product b) {
  if (a.first == b.first) return (a.second > b.second) ? a : b;
  return (a.first > b.first) ? a : b;
}
set<product, cmp> s;

int main() {
  cin >> n >> k;
  for (int i=0;i<n;i++) {
    product p;
    cin >> p.second >> p.first;
    s[i] = p;
  }
  while (ptr != s.end()) {
    time += 
    s.upper_bound()
  }
  return 0;
}
