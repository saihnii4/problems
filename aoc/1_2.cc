#include <iostream>
#include <string>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("in1", "r", stdin);
  string line;
  while (cin >> line) {
    for (int i=0;i<line.length();i++) {
      for (int j=i;j<line.length();j++) {
        &line.c_str()[i];
      }
    }
  }
}
