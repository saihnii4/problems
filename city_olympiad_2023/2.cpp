#include <iostream>
#include <string>

using namespace std;

// dirty but good enough lmao
char determine(char a) {
    switch (a) {
        case 'i':
        case 'j':
            return '1';
        case 'a':
        case 'b':
        case 'c':
            return '2';
        case 'd':
        case 'e':
        case 'f':
            return '3';
        case 'g':
        case 'h':
            return '4';
        case 'k':
        case 'l':
            return '5';
        case 'm':
        case 'n':
            return '6';
        case 'p':
        case 'r':
        case 's':
            return '7';
        case 't':
        case 'u':
        case 'v':
            return '8';
        case 'w':
        case 'x':
        case 'y':
            return '9';
        case 'o':
        case 'q':
        case 'z':
            return '0';
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        string b = "";
        for (int j = 0; j < a.size(); j++) {
            b += determine(a.c_str()[j]);
        }
        cout << b << endl;
    }
}
