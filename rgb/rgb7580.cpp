#include <iostream>
#include <algorithm>
#include <vector>
// TODO: TODO: TODO: TODO:

int main() {
    std::string a;
    std::cin >> a;

    std::sort(a.begin(), a.end());
    std::reverse(a.begin(), a.end());

    std::cout << a << std::endl;
}
