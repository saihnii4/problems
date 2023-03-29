#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<long long> ppl;
    vector<long long> apt;

    for (int i = 0; i < N; i++) {
        long long T;
        cin >> T;
        ppl.push_back(T);
    }

    for (int i = 0; i < M; i++) {
        long long T;
        cin >> T;
        apt.push_back(T);
    }

    sort(apt.begin(), apt.end());

    int b = 0;

    for (long long p : ppl) {
        long long lower = p - K;
        long long upper = p + K;

        int i = -1;
        for (i = apt.size() - 1; (apt[i] > upper || apt[i] < lower) && i >= 1; i /= 2) {
            if (apt[i] < lower) i += 2*i;
            printf("%lld %lld %lld %lld %d\n", apt[i], p, upper, lower, i);
        }
        printf("BRUH : %lld %lld %lld %lld %d\n", apt[i], p, upper, lower, i);

        if (i != 0 && (b ^ i) == 0) continue;
        b ^= i;

        /* printf("%lld %lld %d\n", p, apt[i], i); */
    }
}
