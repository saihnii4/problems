// Most convoluted code i've ever written lmfaooooooo aosjdaoiwjdlkaj

#include <stdio.h>
#include <set>
#include <math.h>
#include <vector>

using namespace std;

int main() {
    int n;
    long long x;
    scanf("%lld %d", &x, &n);
    long long max_dist = 0;

    set<long long> road = {0};
    long long instructions[n];

    for (int i = 0; i < n; i++) {
        long long division;
        scanf("%lld", &division);

        instructions[i] = division;
        road.insert(division);
    }

    road.insert(x);

    int i = 0;
    for (auto it = road.begin(); it != road.end(); ++it) {
        long long deref = *it;
        max_dist = max(max_dist, deref - i);
        i = deref;
    }

    vector<long long> maxes = {max_dist};

    for (int i = n - 1; i > 0; i--) {
        long long instruction = instructions[i];

        auto low = road.lower_bound(instruction);
        --low;
        auto upper = road.upper_bound(instruction);

        road.erase(instruction);

        maxes.push_back(max(maxes.back(), (*upper) - (*low)));
    }

    for (int i = maxes.size() - 1; i >= 0; i--) {
        printf("%lld", maxes[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");

    return 0;
}
