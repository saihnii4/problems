#include <iostream>
#include <algorithm>
#include <utility>

#define HEAD_NODE 0

typedef std::pair<long long, long long> node;

int n, m;
long long arr[100000];
node st[400000];

void build(long long id, long long L, long long R)
{
    if (L == R) {
        st[id] = node(arr[L], 1);
        return;
    }

    long long M = (L + R) / 2;
    build(2 * id + 1, L, M);
    build(2 * id + 2, M + 1, R);
    if (st[2 * id + 1].first == st[2 * id + 2].first)
        st[id] = node(st[2 * id + 1].first, st[2 * id + 1].second + st[2 * id + 2].second);
    else
        st[id] = std::min(st[2 * id + 1], st[2 * id + 2]);
}

void update(long long id, long long L, long long R, long long el, long long val)
{
    if (L == R)
    {
        st[id] = node(val, 1);
        return;
    }

    long long M = (L + R) / 2;
    if (el <= M)
        update(2 * id + 1, L, M, el, val);
    else
        update(2 * id + 2, M + 1, R, el, val);

    if (st[2 * id + 1].first == st[2 * id + 2].first)
        st[id] = node(st[2 * id + 1].first, st[2 * id + 1].second + st[2 * id + 2].second);
    else
        st[id] = std::min(st[2 * id + 1], st[2 * id + 2]);
}


node query(long long id, long long L, long long R, long long l, long long r)
{
    if (L == R) return st[id];

    long long M = (L + R) / 2;
    if (r <= M)
        return query(2 * id + 1, L, M, l, r);
    else if (l >= M + 1)
        return query(2 * id + 2, M + 1, R, l, r);
    else
    {
        node LVal = query(2 * id + 1, L, M, l, M);
        node RVal = query(2 * id + 2, M + 1, R, M + 1, r);

        if (LVal.first == RVal.first)
            return node(LVal.first, LVal.second + RVal.second);
        else
            return std::min(LVal, RVal);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    std::cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    build(HEAD_NODE, 0, n - 1);

    for (int i = 0; i < m; i++)
    {
        int op, a;
        long long b;
        std::cin >> op >> a >> b;

        if (op == 1)
            update(HEAD_NODE, 0, n - 1, a, b);
        else
        {
            node q = query(HEAD_NODE, 0, n - 1, a, b - 1);

            std::cout << q.first << " " << q.second << std::endl;
        };
    }

    return 0;
}