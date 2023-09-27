#include <stdio.h>
#include <utility>

using namespace std;

typedef pair<long long, long long> node;

long long n, m;
long long arr[1 << 17];
node st[4*(1<<17)];

void build(long long id, long long L, long long R, long long floor) {
    if (L == R) {
        st[id] = node(arr[L], floor);
        return;
    }

    long long M = (L + R) / 2;

    build(2*id+1, L, M, floor+1);
    build(2*id+2, M + 1, R, floor+1);

    st[id] = node(((floor ^ 1) == floor+1) ? (st[2*id+1].first | st[2*id+2].first) : (st[2*id+1].first ^ st[2*id+2].first), floor);
}

void update(long long id, long long L, long long R, long long el, long long val, long long floor) {
    if (L == R) {
        st[id] = (val, floor);
        return;
    }
    
    long long M = (L+R)/2;
    if (el <= M) update(2*id+1, L, M, el, val, floor+1);
    else update(2*id+2, M+1,R, el, val, floor+1);

    st[id] = node(((floor ^ 1) == floor+1) ? (st[2*id+1].first | st[2*id+2].first) : (st[2*id+1].first ^ st[2*id+2].first), floor);
}

node query(long long id, long long L, long long R, long long l, long long r) {
}

int main() {
    scanf("%d %lld", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    build(0, 0, n - 1);

    for(int i = 0; i < m; i++) {
        long long p, b;
        scanf("%lld %lld", &p, &b);
    }
}
