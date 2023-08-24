/* #include <stdio.h> */
/* #include <tuple> */
/* #include <stack> */
/*  */
/* using namespace std; */
/*  */
/* int n; */
/* typedef tuple<long long, int> e; */
/*  */
/* int main() { */
/*   scanf("%d", &n); */
/*   stack<e> s; */
/*   long long arr[n]; */
/*  */
/*   for (int i = 0; i < n; i++) { */
/*     long long t; */
/*     scanf("%lld", &t); */
/*  */
/*     arr[i] = t; */
/*   } */
/*  */
/*   for (int i = 0; i < n; i++) { */
/*     while (!s.empty() && get<0>(s.top()) >= arr[i]) { */
/*       s.pop(); */
/*     } */
/*  */
/*     if (s.empty()) { */
/*       printf("0"); */
/*     } else { */
/*       printf("%d", get<1>(s.top())); */
/*     } */
/*     if (i < n - 1) printf(" "); */
/*     s.push(e(arr[i], i + 1)); */
/*   } */
/*  */
/*   printf("\n"); */
/*  */
/*   return 0; */
/* } */

#include <stdio.h>
#include <tuple>

using namespace std;

typedef tuple<long long, int> e;
typedef tuple<long long, e> d;

int n;

int main() {
  scanf("%d", &n);
  long long arr[n];
  d minarr[n];

  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
    if (i == 0) {
      minarr[i] = d(arr[i], e(arr[i], 0));
      printf("0");
      continue;
    }
    minarr[i] = d(arr[i], get<1>(minarr[i-1]));

    if (get<0>(minarr[i]) < arr[i]) {
      printf("%d", i - 1);
    } else if (get<0>(get<1>(minarr[i])) < arr[i]) {
      printf("%d", get<1>(get<1>(minarr[i])));
    }
  }
}
