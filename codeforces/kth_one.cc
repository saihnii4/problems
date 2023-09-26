#include <stdio.h>
#include <utility>

using namespace std;

#define HEAD_NODE 0
#define ll long long

typedef pair<ll, ll> node;

void build(ll id, ll L, ll R);
node query(ll id, ll L, ll R, ll i);
void update(ll id, ll L, ll R, ll i);

ll n, m, arr[100000], seg[400000];

int main() {
  scanf("%lld %lld", &n, &m);

  for (int j = 0; j < n; j++) {
    int op, i;
    scanf("%d %d", &op, &i);

    if (op == 1) update(HEAD_NODE,0,n-1,i);
    else query(HEAD_NODE,0,n-1,i);
  }
}
