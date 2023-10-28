#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int t;
unordered_map<char, int> freq;
int main() {
  cin >> t;
  while (t--) {
    int flags = 0x0000;
    int _s, k;
    string str;
    cin >> _s >> k;
    cin >> str;
    if (_s - k == 1) {
      cout << "YES" << endl;
      continue;
    }
    for (char c : str) {
      freq[c]++;
    }
    if (k % 2 != 0) flags |= (1 << 2);
    for (auto el : freq) {
      cout << el.first << ' ' << el.second << endl;
      if (el.second % 2 != 0) {
        flags |= (1 << 1);
      }
      if (el.second % 2 != 0 && (flags & (1 << 1))) {
        flags |= (1 << 3);
        break;
      }
    }
    if (flags & (1 << 1) && flags & (1 << 3)) {
      flags ^= (1 << 3);
    }
    if (flags & (1 << 3)) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
  }
}
