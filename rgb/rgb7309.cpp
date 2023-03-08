#include <iostream>
#include <math.h>

int reverse_int(char* b) {
    int r = 0;
    for (int i = 0; i < strlen(b); i++) {
        if (b[i] - '0' == 0) continue;
        else if (b[i] - '1' == 0) r += pow(10, i);
        else if (b[i] - '2' == 0) r += pow(10, i)*2;
        else if (b[i] - '3' == 0) r += pow(10, i)*3;
        else if (b[i] - '4' == 0) r += pow(10, i)*4;
        else if (b[i] - '5' == 0) r += pow(10, i)*5;
        else if (b[i] - '6' == 0) r += pow(10, i)*6;
        else if (b[i] - '7' == 0) r += pow(10, i)*7;
        else if (b[i] - '8' == 0) r += pow(10, i)*8;
        else if (b[i] - '9' == 0) r += pow(10, i)*9;
    }

    return r;
}

int true_int(char* b) {
    int r = 0;
    for (int j = 0; j < strlen(b); j++) {
        int i = strlen(b) - j - 1;
        if (b[j] - '0' == 0) continue;
        else if (b[j] - '1' == 0) r += pow(10, i);
        else if (b[j] - '2' == 0) r += pow(10, i)*2;
        else if (b[j] - '3' == 0) r += pow(10, i)*3;
        else if (b[j] - '4' == 0) r += pow(10, i)*4;
        else if (b[j] - '5' == 0) r += pow(10, i)*5;
        else if (b[j] - '6' == 0) r += pow(10, i)*6;
        else if (b[j] - '7' == 0) r += pow(10, i)*7;
        else if (b[j] - '8' == 0) r += pow(10, i)*8;
        else if (b[j] - '9' == 0) r += pow(10, i)*9;
    }

    return r;
}

int main() {
    std::string n;
    std::cin >> n;

    char d[n.size()];

    for (int i = 0; i < n.size(); i++) {
        d[i] = n.c_str()[i];
    }

    printf("%s\n", (reverse_int(d) == true_int(d)) ? "YES": "NO");
}
