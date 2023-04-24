// TODO: get a new brain

#include <math.h>
#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
  int n, m;
  long long rounds = 1;
  scanf("%d %d", &n, &m);

  int arr[n + 1];
  int sec_arr[n + 1];

  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    arr[t] = i;
    sec_arr[i + 1] = t;
  }

  for (int i = 1; i <= n; i++) {
    if (i == n)
      break;
    if (arr[i] > arr[i + 1])
      ++rounds;
  }

  printf("%lld\n", rounds);

  for (int i = 0; i < m; i++) {
    int _x, y;
    scanf("%d %d", &_x, &y);

    int x = max(_x, y);
    y = x ^ _x ^ y;

    if (x - y > 1) {
      if (sec_arr[x] > 1 && arr[sec_arr[x] - 1] < arr[sec_arr[x]] &&
          arr[sec_arr[y]] < arr[sec_arr[x] - 1])
        ++rounds;
      if (sec_arr[y] > 1 && arr[sec_arr[y] - 1] < arr[sec_arr[y]] &&
          arr[sec_arr[x]] < arr[sec_arr[y] - 1])
        ++rounds;
      if (sec_arr[y] <= n && arr[sec_arr[y]] < arr[sec_arr[y] + 1] &&
          arr[sec_arr[x]] > arr[sec_arr[y] + 1])
        ++rounds;
      if (sec_arr[x] <= n && arr[sec_arr[x]] < arr[sec_arr[x] + 1] &&
          arr[sec_arr[y]] > arr[sec_arr[x] + 1])
        ++rounds;

      if (sec_arr[x] > 1 && arr[sec_arr[x] - 1] > arr[sec_arr[x]] &&
          arr[sec_arr[y]] > arr[sec_arr[x] - 1])
        --rounds;
      if (sec_arr[y] > 1 && arr[sec_arr[y] - 1] > arr[sec_arr[y]] &&
          arr[sec_arr[x]] > arr[sec_arr[y] - 1])
        --rounds;
      if (sec_arr[y] <= n && arr[sec_arr[y]] > arr[sec_arr[y] + 1] &&
          arr[sec_arr[x]] < arr[sec_arr[y] + 1])
        --rounds;
      if (sec_arr[x] <= n && arr[sec_arr[x]] > arr[sec_arr[x] + 1] &&
          arr[sec_arr[y]] < arr[sec_arr[x] + 1])
        --rounds;
    } else {
      if (sec_arr[x] > sec_arr[y])
        ++rounds;
      else
        --rounds;
    }

    arr[sec_arr[x]] ^= arr[sec_arr[y]];
    arr[sec_arr[y]] ^= arr[sec_arr[x]];
    arr[sec_arr[x]] ^= arr[sec_arr[y]];

    sec_arr[x] ^= sec_arr[y];
    sec_arr[y] ^= sec_arr[x];
    sec_arr[x] ^= sec_arr[y];
    /* for (int i = 0; i < n; i++) { */
    /*   printf("%d ", sec_arr[i + 1]); */
    /* } */
    /* printf("\n"); */

    printf("%lld\n", rounds);
  }
}
