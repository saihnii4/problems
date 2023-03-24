#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>

int main() {
  int T;
  int b = 0;
  scanf("%d", &T);

  std::cin.ignore();

  while (T--) {
    std::string test;
    std::cin >> test;

    int sum = 0;
    for (int i = 0; i < strlen(test.c_str()); i++)
      sum += (i+1)*int(test.c_str()[i]);

    printf("%d\n", sum);

    if (b & (1 << sum)) {
      int t = 1;
      while (b & (1 << (sum + t)))
        t++;

      b |= (1 << (sum + t));
      printf("%s%d\n", test.c_str(), t);
    } else {
      printf("%s\n", "OK");
      b |= (1 << sum);
    };
  }
}
