#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>

int main() {
    std::string b;
    std::cin >> b;
    const char* n = b.c_str();
    
    int sum = 0;

    // shit code :)
    for (int i = 0; i < strlen(n); i++) {
        if (n[i] == '0') continue;
        else if (n[i] == '1') ++sum;
        else if (n[i] == '2') sum += pow(2, strlen(n));
        else if (n[i] == '3') sum += pow(3, strlen(n));
        else if (n[i] == '4') sum += pow(4, strlen(n));
        else if (n[i] == '5') sum += pow(5, strlen(n));
        else if (n[i] == '6') sum += pow(6, strlen(n));
        else if (n[i] == '7') sum += pow(7, strlen(n));
        else if (n[i] == '8') sum += pow(8, strlen(n));
        else if (n[i] == '9') sum += pow(9, strlen(n));
    }

    std::string bruh = std::to_string(sum);
    char* bruh2 = new char[bruh.length()-1];

    std::strcpy(bruh2, bruh.c_str());

    if (strcmp(bruh2, n) == 0) printf("YES\n");
    else printf("NO\n");

    return 0;
}

