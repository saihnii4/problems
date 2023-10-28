#include <iostream>
#include <string>
#include <utility>
using namespace std;
pair<int, int> expected(char l) {
  int dist = l - 'A';
  int col = dist%4;
  int row = dist/4;
  return {col, row};
}
int ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  /* freopen("test.in","r",stdin); */
  for (int i = 0; i < 4; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < 4; j++) if (str.c_str()[j] - '.' != 0) {
      /* cout << expected(str.c_str()[j]).first << ' ' << expected(str.c_str()[j]).second << endl; */
      pair<int, int> s = expected(str.c_str()[j]);
      ans += abs(j-s.first) + abs(i-s.second);
    }
  }
  cout << ans << endl;
  return 0;
}
