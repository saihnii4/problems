#include <iostream>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

int board[8][8];
bool column[8];
bool diag1[9999];
bool diag2[9999];
int count;

void put(int x) {
    if (x == 8) {
        ++count;
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (board[x][i] == -1 || column[i] || diag1[x + i] || diag2[i - x + 7]) 
            continue;

        column[i] = diag1[x + i] = diag2[i - x + 7] = true;
        put(x + 1);
        column[i] = diag1[x + i] = diag2[i - x + 7] = false;
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < 8; j++) {
            if (row.c_str()[j] - '.' == 0) {
                board[i][j] = 0;
            } else {
                board[i][j] = -1;
            }
        }
    }

    put(0);
    printf("%d\n", count);
}
