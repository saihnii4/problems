#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int main() {
    string test;
    
    getline(cin, test);
    char* input = (char*)malloc(test.length()*sizeof(char));
    strcpy(input, test.c_str());

    int i = 0;

    for (int j = 0; j < strlen(input); j++) {
        if (input[j] == '"') {
            if (i & 1) {
                input[j] = '_';
            } else {
                input[j] = '*';
            }
            i++;
        }
    }
    
    printf("%s\n", input);

    return 0;
}
