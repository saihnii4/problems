#include <cstring>
#include <iostream>
#include <string>

using namespace std;

long long count;
bool board[7][7];
char actions[48];
string caricature;

// (0, 0) starting point
void solve(int x, int y, int vstd) {
  if (board[x][y])
    return;

  if (x == 0 && y == 6) {
    if (vstd < 48)
      return;

    ++count;
    return;
  }

  bool prev = (x == 0 || board[x - 1][y]);
  bool next = (x == 6 || board[x + 1][y]);
  bool above = (y == 0 || board[x][y - 1]);
  bool below = (y == 6 || board[x][y + 1]);

  if ((prev && next) && (!above && !below) ||
      (!prev && !next) && (above && below))
    return;

  if (actions[vstd] == '?') {
    if (x < 6) {
      actions[vstd] = 'R';
      board[x][y] = true;
      solve(x + 1, y, vstd + 1);
      actions[vstd] = '?';
      board[x][y] = false;
    }

    if (y < 6) {
      actions[vstd] = 'D';
      board[x][y] = true;
      solve(x, y + 1, vstd + 1);
      actions[vstd] = '?';
      board[x][y] = false;
    }

    if (y > 0) {
      actions[vstd] = 'U';
      board[x][y] = true;
      solve(x, y - 1, vstd + 1);
      actions[vstd] = '?';
      board[x][y] = false;
    }

    if (x > 0) {
      actions[vstd] = 'L';
      board[x][y] = true;
      solve(x - 1, y, vstd + 1);
      actions[vstd] = '?';
      board[x][y] = false;
    }
  } else {
    switch (actions[vstd]) {
    case 'D':
      if (y == 6)
        break;
      board[x][y] = true;
      solve(x, y + 1, vstd + 1);
      board[x][y] = false;
      break;
    case 'U':
      if (y == 0) break;
      board[x][y] = true;
      solve(x, y - 1, vstd + 1);
      board[x][y] = false;
      break;
    case 'L':
      if (x == 0) break;
      board[x][y] = true;
      solve(x - 1, y, vstd + 1);
      board[x][y] = false;
      break;
    case 'R':
      if (x == 6) break;
      board[x][y] = true;
      solve(x + 1, y, vstd + 1);
      board[x][y] = false;
      break;
    default:
      break;
    }
  }
}

int main() {
  cin >> caricature;

  for (int i = 0; i < caricature.size(); i++) {
      actions[i] = caricature[i];
  }

  solve(0, 0, 0);

  printf("%lld\n", count);

  return 0;
}
