#include <stdio.h>
#include <deque>
#include <string.h>
#include <math.h>

using namespace std;

int main() {
    int n;
    long long i = 0;
    scanf("%d", &n);

    deque<int> a, b, c;

    for (int i = n; i > 0; i--) {
        a.push_back(i);
    }

    long long moves = pow(2, n) - 1;

    printf("%lld\n", moves);

    for (int i = 0; i < moves; i++) {
        switch (i % 3) {
            case 0:
                if ((n & 1) == 0) {
                    if (b.size() != 0 && (a.size() == 0 || a.back() > b.back())) {
                        a.push_back(b.back());
                        b.pop_back();
                        printf("2 1\n");
                    } else {
                        b.push_back(a.back());
                        a.pop_back();
                        printf("1 2\n");
                    }
                } else {
                    if (c.size() != 0 && (a.back() == 0 || a.back() > c.back())) {
                        a.push_back(c.back());
                        c.pop_back();
                        printf("3 1\n");
                    } else {
                        c.push_back(a.back());
                        a.pop_back();
                        printf("1 3\n");
                    }
                }
                break;
            case 1:
                if ((n & 1) == 0) {
                    if (c.size() != 0 && (a.back() == 0 || a.back() > c.back())) {
                        a.push_back(c.back());
                        c.pop_back();
                        printf("3 1\n");
                    } else {
                        c.push_back(a.back());
                        a.pop_back();
                        printf("1 3\n");
                    }
                } else {
                    if (b.size() != 0 && (a.size() == 0 || a.back() > b.back())) {
                        a.push_back(b.back());
                        b.pop_back();
                        printf("2 1\n");
                    } else {
                        b.push_back(a.back());
                        a.pop_back();
                        printf("1 2\n");
                    }
                }
                break;
            case 2:
                if (c.size() != 0 && b.back() > c.back()) {
                    b.push_back(c.back());
                    c.pop_back();
                    printf("3 2\n");
                } else {
                    c.push_back(b.back());
                    b.pop_back();
                    printf("2 3\n");
                }
                break;
        }
    }
}
