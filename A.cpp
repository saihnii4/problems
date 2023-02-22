#include <iostream>

int main() {
  int T = 5;
  int in[5] = {3, 5, 2, 4, 1};

  int cop[5] = {3, 5, 2, 4, 1};

  for (int i = 0; i < sizeof(in) / sizeof(int); i++) {
    cop[i] += 2 * i;
  }

  for (int i = 0; i < sizeof(cop) / sizeof(int); i++) {
    if (i + 1 == 5)
      break;
    if (cop[i] > cop[i + 1]) {
      in[i + 1] ^= in[i];
      in[i] ^= in[i + 1];
      in[i + 1] ^= in[i];
    }
  }

  for (int i = 0; i < sizeof(cop) / sizeof(int); i++) {
    printf("%d\n", in[i]);
  }
}
