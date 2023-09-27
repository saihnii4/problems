#include <stdio.h>
#include <utility>

#define ll long long
#define HEAD_NODE 0

using namespace std;

typedef pair<ll, ll> node;

const int N = 100000;
int n, m;
ll arr[N];
node seg[4*N];

node merge(node a, node b) {
    return node(a.first+b.first,b.second);
}

void build(ll id, ll L, ll R) {
    if (L == R) {
        seg[id] = node(arr[L], L);
        return;
    }

    ll M = (L+R)/2;
    build(2*id+1,L,M);
    build(2*id+2,M+1,R);
    seg[id] = merge(seg[2*id+1], seg[2*id+2]);
}

void update(ll id, ll L, ll R, ll i) {
    if (L == R) {
        seg[id] = node(seg[id].first^1, L);
        return;
    }

    ll M=(L+R)/2;
    if (i <= M) update(2*id+1,L,M,i);
    else update(2*id+2,M+1,R,i);
    seg[id] = merge(seg[2*id+1], seg[2*id+2]);
}

ll query(ll id, ll L, ll R, ll k) {
    if (L == R) {
        return seg[id].second;
    }

    ll M = (L+R)/2;
    if (k >= seg[2*id+1].first) return query(2*id+2,M+1,R,k-seg[2*id+1].first);
    else return query(2*id+1,L,M,k);
}

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    build(HEAD_NODE, 0, n - 1);

    for (int i = 0; i < m; i++) {
        int op;
        ll k;
    
        scanf("%d %lld", &op, &k);

        if (op == 1) update(HEAD_NODE,0,n-1,k);
        else printf("%lld\n", query(HEAD_NODE,0,n-1,k));
    }

    return 0;
}
