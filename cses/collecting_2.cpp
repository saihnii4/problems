#include <math.h>
#include <stdio.h>
 
int max(int a, int b) { return a > b ? a : b; }
int n, m;
 
int correcting_factor(int x, int y, int arr[], int inv_arr[]) {
    int cf = 0;
    if (inv_arr[x] < n && x > arr[inv_arr[x]+1] && y <= arr[inv_arr[x]+1]) --cf;
    if (inv_arr[x] > 1 && x < arr[inv_arr[x]-1] && y >= arr[inv_arr[x]-1]) --cf;
    if (inv_arr[y] < n && y > arr[inv_arr[y]+1] && x < arr[inv_arr[y]+1]) --cf;
    if (inv_arr[y] > 1 && y < arr[inv_arr[y]-1] && x > arr[inv_arr[y]-1]) --cf;
 
    if (inv_arr[x] < n && x < arr[inv_arr[x]+1] && y >= arr[inv_arr[x]+1]) ++cf;
    if (inv_arr[x] > 1 && x > arr[inv_arr[x]-1] && y <= arr[inv_arr[x]-1]) ++cf;
    if (inv_arr[y] < n && y < arr[inv_arr[y]+1] && x > arr[inv_arr[y]+1]) ++cf;
    if (inv_arr[y] > 1 && y > arr[inv_arr[y]-1] && x < arr[inv_arr[y]-1]) ++cf;
 
    return cf;
}
 
int main() {
  long long rounds = 1;
  scanf("%d %d", &n, &m);
 
  int arr[n + 1];
  int inv_arr[n + 1];
 
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    arr[t] = i+1;
    inv_arr[i + 1] = t;
  }
 
  for (int i = 1; i <= n; i++) {
    if (i == n)
      break;
    if (arr[i] > arr[i + 1])
      ++rounds;
  }
 
  for (int i = 0; i < m; i++) {
    int _x, y_pos;
    scanf("%d %d", &_x, &y_pos);
 
    int x_pos = max(_x, y_pos);
    y_pos = x_pos ^ _x ^ y_pos;
 
    int cf = correcting_factor(x_pos, y_pos, arr, inv_arr);
    rounds += cf;
 
    int copy = arr[inv_arr[x_pos]];
    arr[inv_arr[x_pos]] = arr[inv_arr[y_pos]];
    arr[inv_arr[y_pos]] = copy;
 
    copy = inv_arr[x_pos];
    inv_arr[x_pos] = inv_arr[y_pos];
    inv_arr[y_pos] = copy;
 
    printf("%lld\n", rounds);
  }
}
