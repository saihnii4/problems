#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int height, width, A_x, A_y, B_x, B_y, min_dist = 1e5, board[1000][1000];
string min_actions;
bool possible, visited[1000][1000];

bool search(int x, int y) {
  if (x >= width || x < 0 || y >= height || y < 0 || visited[y][x])
    return false;

  visited[y][x] = true;

  if (x == B_x && x == B_y) {
    possible = true;
    return true;
  }

  return search(x + 1, y) || search(x - 1, y) || search(x, y + 1) ||
         search(x, y - 1);
}

void traverse(int x, int y, int dist, string actions) {
  if (x >= width || x < 0 || y >= height || y < 0 || board[y][x] ||
      dist >= min_dist)
    return;

  if (x == B_x && y == B_y) {
    min_actions = actions;
    min_dist = dist;
    return;
  }

  board[y][x] = true;
  if (x < width - 1)
      traverse(x + 1, y, dist + 1, actions + "R");
  board[y][x] = false;

  board[y][x] = true;
  if (x > 0)
      traverse(x - 1, y, dist + 1, actions + "L");
  board[y][x] = false;

  board[y][x] = true;
  if (y < height - 1)
      traverse(x, y + 1, dist + 1, actions + "D");
  board[y][x] = false;

  board[y][x] = true;
  if (y > 0)
      traverse(x, y - 1, dist + 1, actions + "U");
  board[y][x] = false;
}

int main() {
  scanf("%d %d", &height, &width);

  for (int i = 0; i < height; i++) {
    string row;
    cin >> row;

    for (int j = 0; j < row.size(); j++) {
      if (row[j] - '#' == 0) {
        board[i][j] = true;
        visited[i][j] = true;
      }

      if (row[j] - 'A' == 0) {
        A_x = j;
        A_y = i;
      }

      if (row[j] - 'B' == 0) {
        B_x = j;
        B_y = i;
      }
    }
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      search(i, j);
    }
  }

  if (!possible)
      cout << "NO" << endl;
  else {
      cout << "YES" << endl;
      traverse(A_x, A_y, 0, "");
      cout << min_actions << endl;
      cout << min_dist << endl;
  }

  return 0;
}
