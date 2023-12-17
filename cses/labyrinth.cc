#include <iostream>
#include <string>
using namespace std;
string str;
int n, m;
int arr[1000][1000];
int main() {
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    getline(cin, str);
    for (int j=0;j<m;j++) {
      switch (str.c_str()[j]) {
        case '#':
          arr[i][j] = -1;
          break;
        case '.':
          arr[i][j] = 0;
          break;
        case 'A':
          arr[i][j] = 1;
          break;
        case 'B':
          arr[i][j] = 2;
          break;
      }
    }
  }
  return 0;
}
