#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int width, height;

int count;
bool visited[1000][1000];

bool solve(int x, int y) {
    if (x >= width || x < 0 || y >= height || y < 0 || visited[y][x] != 0) {
        return false;
    };

    visited[y][x] = true;

    solve(x+1, y);
    solve(x, y+1);
    solve(x, y-1);
    solve(x-1, y);

    return true;
}

int main() {
    scanf("%d %d", &height, &width);

    for (int i = 0; i < height; i++) {
        string row;
        cin >> row;

        for (int x = 0; x < row.size(); ++x) {
            if (row[x] - '#' == 0)
                visited[i][x] = true;
        }
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            bool res = solve(i, j);
            if (res)
                ++count;
        }
    }

    printf("%d\n", count);
}
