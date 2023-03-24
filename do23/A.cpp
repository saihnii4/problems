// pretty terse approach owing to my finite brain (smaller than epsilon squared)

#include <string>
#include <math.h>
#include <string.h>
#include <iostream>

using namespace std;

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
    string a, b;
    cin >> a >> b;

    // max allotments
    char a_[a.size()];
    char b_[b.size()];

    // min allotments
    char c_[a.size()];
    char d_[b.size()];

    for (int i = 0; i < a.size(); i++) {
        if (a.c_str()[i] == '5') a_[i] = '6';
        else a_[i] = a.c_str()[i];
    }
    
    for (int i = 0; i < b.size(); i++) {
        if (b.c_str()[i] == '5') b_[i] = '6';
        else b_[i] = b.c_str()[i];
    }

    for (int i = 0; i < a.size(); i++) {
        if (a.c_str()[i] == '6') c_[i] = '5';
        else c_[i] = a.c_str()[i];
    }
    
    for (int i = 0; i < b.size(); i++) {
        if (b.c_str()[i] == '6') d_[i] = '5';
        else d_[i] = b.c_str()[i];
    }

    int max = convert_to_num(a_) + convert_to_num(b_);
    int min = convert_to_num(c_) + convert_to_num(d_);

    printf("%d %d\n", min, max);
}
