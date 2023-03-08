#include <string>
#include <iostream>

int main() {
    std::string bruh;
    std::cin >> bruh;
    int min = 0;

    for (int i = 0; i < bruh.size(); i++) {
        int l = bruh.c_str()[i] - 48;
        if (l < min) min = l;
    }

    printf("%d\n", min);
}

