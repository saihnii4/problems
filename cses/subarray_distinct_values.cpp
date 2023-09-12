/* #include <set> */
/* #include <stdio.h> */
/*  */
/* using namespace std; */
/*  */
/* long long n, k, ct; */
/*  */
/* long long main() { */
/*   scanf("%d %d", &n, &k); */
/*   long long arr[n]; */
/*  */
/*   for (long long i = 0; i < n; i++) { */
/*     scanf("%lld", &arr[i]); */
/*   } */
/*  */
/*   set<long long> rr; */
/*  */
/*   long long j = 0; */
/*   long long r = 0; */
/*  */
/*   for (long long i = 0; i < n; i++) { */
/*     j = i; */
/*     r = 0; */
/*  */
/*     rr.insert(arr[j]); */
/*     ++ct; */
/*     ++r; */
/*     ++j; */
/*  */
/*     while (j < n) { */
/*       if (rr.find(arr[j]) == rr.end()) ++r; */
/*       if (r > k) break; */
/*       rr.insert(arr[j]); */
/*       ++j; */
/*       ++ct; */
/*     } */
/*      */
/*     rr.clear(); */
/*   } */
/*  */
/*   prlong longf("%d\n", ct); */
/*  */
/*   return 0; */
/* } */

#include <map>
#include <stdio.h>
#include <vector>

using namespace std;

long long n, k;
long long ans;

map<long long, long long> frq;

int main() {
  scanf("%lld %lld", &n, &k);
  long long arr[n];

  for (long long i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }

  long long i = 0;
  long long j = 0;
  long long distinct = 0;

  while (i < n) {
    while (j < n) {
      if (frq.count(arr[j]) == 0 && distinct == k)
        break;
      if (frq.count(arr[j]) == 0) {
        frq[arr[j]] = 1;
        ++distinct;
      } else {
        ++frq[arr[j]];
      }

      ++j;
    }

    ans += (j - i);

    if (frq[arr[i]] == 1) {
      frq.erase(arr[i]);
      --distinct;
    } else {
      --frq[arr[i]];
    }

    ++i;
  }

  printf("%lld\n", ans);

  return 0;
}
