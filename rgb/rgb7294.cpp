#include <iostream>
#include <string.h>
#include <stdio.h>

int main() {
    const char* a = "qwertyuiopasdfghjkl;zxcvbnm,./";
    const char* b = "wertyuiopasdfghjkl;zxcvbnm,./q";
    const char* c = "/qwertyuiopasdfghjkl;zxcvbnm,.";

    std::string r;
    std::cin >> r;
    std::string d;
    std::cin >> d;
    
    char e[d.size()];

    for (int i = 0; i < d.size(); i++) {
        for (int j = 0; j < strlen(a); j++) {
            if (a[j] - d.c_str()[i] == 0) {
                if (r.c_str()[0] - 'L' == 0) e[i] = b[j];
                else if (r.c_str()[0] - 'R' == 0) e[i] = c[j];
            }
        }
    }

    std::cout << e << std::endl;
}
