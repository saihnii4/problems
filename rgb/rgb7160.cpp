#include <iostream>
#include <istream>
#include <string>

// TODO: implement in c

int main() {
    std::string n;
    std::cin >> n;

    std::cin.getline();

    std::string b;

    for (int i = 0; i < n.size(); i++) {
        std::cout << n[i] << std::endl;
        if (n[i] > 97 && n[i] < 122) b.push_back(n[i] - 32);
    }

    std::cout << b << std::endl;
}

