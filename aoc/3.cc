#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
using ll = long long;
int i, k = -1, r;
ll sch[1000][1000], sum;
set<ll> nums;
int main() {
  freopen("in3", "r", stdin);
  string line;
  while (cin >> line) {
    r = max(r, (int)line.length());
    for (int j = 0; j < line.length(); j++) {
      char c = line.c_str()[j];
      if ((c - '0' > 9 || c - '0' < 0) && k >= 0) {
        if (k >= 0) {
          string total = "";
          for (int z = k; z <= j; z++) {
            total += (string() + (char)sch[i][z]);
          }
          for (int z = k; z < j; z++) {
            sch[i][z] = stoi(total);
          }
        }
        k = -1;
      }
      if ((c - '0' > 9 || c - '0' < 0) && c - '.' != 0) {
        sch[i][j] = -1;
        continue;
      }
      if (c - '.' != 0 && k < 0)
        k = j;
      sch[i][j] = c;
      if (c - '.' == 0) {
        sch[i][j] = 0;
      }
    }
    ++i;
  }
  int n = i;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < r; j++) {
      if (sch[i][j] == -1) {
        int flag = 0;
        if (i > 0)
          nums.insert(sch[i - 1][j]);
        if (j > 0)
          nums.insert(sch[i][j - 1]);
        if (i < n)
          nums.insert(sch[i + 1][j]);
        if (j < r)
          nums.insert(sch[i][j + 1]);
        if (i < n && j < r)
          nums.insert(sch[i + 1][j + 1]);
        if (i > 0 && j < r)
          nums.insert(sch[i - 1][j + 1]);
        if (j > 0 && i < r)
          nums.insert(sch[i + 1][j - 1]);
        if (i > 0 && j > 0)
          nums.insert(sch[i - 1][j - 1]);
      }
    }
  }
  for (const ll num : nums) {
    sum += num;
  }
  cout << sum << endl;
  return 0;
}
