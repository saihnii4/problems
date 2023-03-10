#include <algorithm>
#include <iostream>
#include <string>

// it's hilarious how overengineered this is

int main() {
    char m;

    std::string a;
    std::cin >> a;

    std::string b = a;

    std::sort(b.begin(), b.end());
    std::sort(a.begin(), a.end());

    for (int i = 0; i < b.size(); i++) {
        if (b[i] - 48 != 0) {
            m = b[i];
            break;
        }
    }

    /* std::string() + m +  */

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == m) {
            a.erase(i, 1);
            a.insert(0, 1, m);
            break;
        }
    }
    std::cout << a << std::endl;
}
