#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

queue<int> q1;
queue<int> q2;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        q1.push(i);
    }

    int i = 0;

    queue<int>* a = &q1;
    queue<int>* b = &q2;

    while (!((*a).empty() && (*b).empty())) {
        ++i;
        if ((*a).empty()) {
            queue<int> tmp = *a;
            *a = *b;
            *b = tmp;
        }

        if ((i & 1) == 0) {
            printf("%d ", (*a).front());
            (*a).pop();
        } else {
            (*b).push((*a).front());
            (*a).pop();
        }
    }

    printf("\n");

    return 0;
}
