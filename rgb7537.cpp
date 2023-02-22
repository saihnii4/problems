#include <stdio.h>
#include <math.h>
#include <string>

int convert_to_num(char* num) {
    int r = 0;
    for (int i = 0; i < strlen(num); i++) {
        int j = strlen(num)-i-1;
        if (num[i] == '0') r *= pow(10, j);
        else if (num[i] == '1') r += pow(10, j);
        else if (num[i] == '2') r += pow(10, j) * 2;
        else if (num[i] == '3') r += pow(10, j) * 3;
        else if (num[i] == '4') r += pow(10, j) * 4;
        else if (num[i] == '5') r += pow(10, j) * 5;
        else if (num[i] == '6') r += pow(10, j) * 6;
        else if (num[i] == '7') r += pow(10, j) * 7;
        else if (num[i] == '8') r += pow(10, j) * 8;
        else if (num[i] == '9') r += pow(10, j) * 9;
        else continue; // filters unknown characters
    }

    return r;
}

int main() {
    char* n;
    scanf("%s", n);

    for (int i = 0; i < strlen(n); i++) {
        if (n[i] != '4' || n[i] != '7') break;
        if (i+1 == strlen(n)) printf("YES\n");
    }

    printf("%d\n", convert_to_num(n));
}
