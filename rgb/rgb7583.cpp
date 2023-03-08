// TODO: implement in C++

#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <math.h>
#include <string.h>

int convert_to_int(const char* c) {
    int r = 0;
    for (int i = 0; i < strlen(c); i++) r += pow(10, strlen(c)-i-1)*(c[i]-48);
    return r;
}

int reverse_convert_to_int(const char* c) {
    int r = 0;
    for (int i = 0; i < strlen(c); i++) r += pow(10, i)*(c[i]-48);
    return r;
}

int main() {
    std::string n;
    std::cin >> n;

    std::sort(n.start(), n.end());
}
