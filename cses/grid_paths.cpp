#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int ct;
vector<char> base;
int map[49];

void solve(vector<char> path, int loc, int x, int y) {
    if (x < 0 || x > 6 || y > 6 || y < 0 || map[x + y] != 0) return;
    
    if (x == 6 && y == 6 && loc == 48) {
        ++ct;
        return;
    }

    if (path[loc] - '?' == 0) {
        if (y < 6) {
            path[loc] = map[x + y] = 'D';
            solve(path, loc + 1, x, y + 1);
            path[loc] = map[x + y] = '?';
        }

        if (y > 0) {
            path[loc] = map[x + y]  = 'U';
            solve(path, loc + 1, x, y - 1);
            path[loc] = map[x + y] = '?';
        }

        if (x < 7) {
            path[loc] = map[x + y]  = 'R';
            solve(path, loc + 1, x + 1, y);
            path[loc] = map[x + y] = '?';
        }

        if (x > 0) {
            path[loc] = map[x + y] = 'L';
            solve(path, loc + 1, x - 1, y);
            path[loc] = map[x + y] = '?';
        }
    } else {
        switch (base[loc]) {
            case 'L':
                solve(path, loc + 1, x - 1, y);
                break;
            case 'R':
                solve(path, loc + 1, x + 1, y);
                break;
            case 'D':
                solve(path, loc + 1, x, y + 1);
                break;
            case 'U':
                solve(path, loc + 1, x, y - 1);
                break;
            default:
                break;
        }
    }
}

int main() {
    memset(map, 0, sizeof(int)*49);
    for (int i = 0; i < 48; i++) {
        char _c;
        cin >> _c;
        base.push_back(_c);
    }

    solve(base, 0, 0, 0);

    printf("%d\n", ct);
}
