#include <iostream>
#include <string>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    string str, a, b;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
      if (stoi(&str.c_str()[i]) < stoi(a.c_str())) {
        break;
      }
      if (str.c_str()[i] - '0' == 0) {
        while (str.c_str()[i] - '0' == 0) {
          ++i;
          a += '0';
        }
        break;
      }
    }
    for (int i = 0; i < str.size(); i++) {

    }
  }
}
