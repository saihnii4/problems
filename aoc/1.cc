#include <iostream>
#include <string>
using namespace std;
using ll = long long;
ll sum;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("in1", "r", stdin);
  string line;
  while (cin >> line) {
    char first = ' ', last;
    for (const char &c : line) {
      switch (c) {
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        if (first - ' ' == 0)
          first = c;
        last = c;
      }
    }
    sum += stoi(string() + first + last);
  }
  cout << sum << endl;

  return 0;
}
