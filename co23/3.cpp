#include <iostream>
#include <set>
#include <vector>
#include <string.h>

using namespace std;

vector<long long> ledger;
vector<long long> sieve;
set<long long> poss;

vector<long long> prime_factors(long long n) {
    if (n == 1) return vector<long long>{};
    if (sieve[n] == 0) return vector<long long>{n};

    vector<long long> factors;

    for (int i = 0; i < ledger.size(); i++) {
        if (n % ledger[i] == 0) {
            factors.push_back(ledger[i]);
            vector<long long> sub = prime_factors((long long)(n / ledger[i]));
            for (int j = 0; j < sub.size(); j++) {
                factors.push_back(sub[j]);
            }
            break;
        }
    }

    return factors;
}

set<long long> gen(vector<long long> factors, long long a) {
    if (a <= 1) return set<long long>{};
    
    set<long long> poss;

    for (const long long f : factors) {
        poss.insert((long long)(a / f));
        set<long long> child = gen(factors, (long long)(a / f));

        for (long long i : child) {
            poss.insert(i);
        }
    }

    return poss;
}

int main() {
    long long a, b;
    cin >> a >> b;

    long long c = a + b;
    long long d = (long)(c);

    for (int i = 0; i < d; i++) sieve.push_back(0);

    for (long long i = 2; i <= d; i++) {
        if (sieve[i] == 1) continue;
        ledger.push_back(i);

        for (long long j = 2*i; j <= d; j += i) {
            sieve[j] = 1;
        }
    }

    vector<long long> f1 = prime_factors(c);
    vector<long long> f2 = prime_factors(b);

    set<long long> p1 = gen(f1, c);
    set<long long> p2 = gen(f2, b);


    if (p2.size() == 0) p2 = set<long long>{1};
    if (p1.size() == 0) p1 = set<long long>{1};

    for (long long i : p1) {
        if (i == 0) continue;
        long long j = (long long)(c / i);
        for (long long k : p2) {
            if (k == 0) continue;

            long long l = (long long)(b / k);

            if (i - k >= 2 && j - l >= 2) {
                if (i > j) cout << i << " " << j << endl;
                else cout << j << " " << i << endl;
                
                return 0;
            }
        }
    }

    printf("NO SOLUTION"); // not part of the question but whatevs
    return 0;
}
