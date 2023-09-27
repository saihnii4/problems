#include <stdio.h>
#include <tuple>

#define ll long long
#define HEAD_NODE 0

using namespace std;

// max   index   extra value maybe??
typedef tuple<ll, ll, ll> node;

ll arr[100000], b;
node seg[400000];
int n, m, op, a;

void build(ll id, ll L, ll R) {
    if (L == R) {
        seg[id] = node(arr[L], L, 0);
        return;
    }

    ll M = (L+R)/2;

    build(2*id+1,L,M);
    build(2*id+1,M+1,R);
    seg[id]=merge(seg[2*id+1],seg[2*id+2]);
}

// TODO: implement
void update(ll id, ll L, ll R, ll i, ll v);
node merge(node l, node r);
node query(ll id, ll L, ll R, ll x);

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    build(HEAD_NODE, 0, n - 1);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %lld", &op, &a, &b);

        if (op == 1) return;
        else return;
    }

    return 0;
}