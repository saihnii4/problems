#include <stdio.h>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int n, k, ans;

typedef pair<long long, long long> movie;

bool cmp(movie a, movie b) {
  return (a.second < b.second);
}

multiset<long long> tips;

int main() {
  scanf("%d %d", &n, &k);

  vector<movie> movies;

  for (int i = 0; i < n; i++) {
    long long start, end;
    scanf("%lld %lld", &start, &end);

    movies.push_back(movie(start, end));
  }

  sort(movies.begin(), movies.end(), cmp);

  for (int i = 0; i < k; i++) tips.insert(0);

  for (int i = 0; i < n; i++) {
    auto it = tips.upper_bound(movies[i].first);
    if (it == tips.begin()) continue;
    tips.erase(--it);
    tips.insert(movies[i].second);
    ++ans;
  }

  printf("%d\n", ans);
}
