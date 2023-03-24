#include <stdio.h>
#include <string>
#include <iostream>

int main() {
    int N = 4;
    const char* a = "aacd";

    for (int i = 0; i < N; i++) {
        std::string b = "";
        for (int j = 0; j < N; j++) if (i != j) {
            for (int z = 0; z < N; z++) if (i != z && j != z) {
                for (int k = 0; k < N; k++) if (i != k && j != k && z != k) {
                    std::string b = "";
                    b += std::string() + a[i] + a[j] + a[z] + a[k];
                    std::cout << b << std::endl;
                }
            }
        }
    }
}
