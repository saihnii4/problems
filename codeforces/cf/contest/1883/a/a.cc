#include <iostream>
#include <string>
using namespace std;
int t, cur = 1, ct;
int main() {
  cin >> t;
  /* cin.tie(NULL); */
  /* ios_base::sync_with_stdio(false); */
  while (t--) {
    ct = 0;
    cur = 1;
    string str;
    cin >> str;
    for (char c : str) {
      int intr = stoi(c + string());
      if (intr == 0) intr = 10;
      if (cur == intr) {
        ++ct;
        continue;
      }
      ct += abs(intr - cur) + 1;
      cur = intr;
    }
    cout << ct << endl;
  }
  return 0;
}
