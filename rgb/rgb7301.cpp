#include <iostream>
#include <stdio.h>

int main() {
    std::string a;
    std::cin >> a;
    std::cout << a.c_str()[0] << std::endl;
}
