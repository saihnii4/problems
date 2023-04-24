#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

#define INF 1e6

bool board[1000][1000];
int paths[1000][1000];
int height, width, A_x, A_y, B_x, B_y, min_dist = INF;
string min_path;

void traverse(int x, int y, int dist, string actions) {
    if (x < 0 || y < 0 || x >= width || y >= height || dist >= min_dist || paths[y][x] || board[y][x]) return;

    if (x == B_x && y == B_y) {
        min_dist = dist;
        min_path = actions;
        return;
    }

    board[y][x] = true;
    traverse(x + 1, y, dist + 1, actions + "R");
    board[y][x] = false;

    board[y][x] = true;
    traverse(x - 1, y, dist + 1, actions + "L");
    board[y][x] = false;
    
    board[y][x] = true;
    traverse(x, y + 1, dist + 1, actions + "D");
    board[y][x] = false;
    
    board[y][x] = true;
    traverse(x, y - 1, dist + 1, actions + "U");
    board[y][x] = false;
}

int main() {
    scanf("%d %d", &height, &width);

    for (int i = 0; i < height; i++) {
        string row;
        cin >> row;

        for (int j = 0; j < row.size(); j++) {
            char c = row[j];

            if (c - '#' == 0)
                board[i][j] = true;

            if (c - 'A' == 0) {
                A_x = j;
                A_y = i;
            }

            if (c - 'B' == 0) {
                B_x = j;
                B_y = i;
            }
        }
    }

    traverse(A_x, A_y, 0, "");

    if (min_dist != INF)
        cout << "YES" << endl << min_dist << endl << min_path << endl;
    else
        cout << "NO" << endl;

    return 0;
}
