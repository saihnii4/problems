#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int R, B;
    cin >> R >> B;

    int sum = (int)((R / 2) + 2);

    for (int i = 1; i <= sum; i++) {
        if ((sum - i)*i == (R + B)) {
            if (sum > 2 * i) cout << sum - i << " " << i << endl;
            else cout << i << " " << sum - i << endl;
            break;
        }
    }
}
