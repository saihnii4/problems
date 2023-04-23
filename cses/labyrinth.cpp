#include <stdio.h>

int height, width;

bool board[1000][1000];

int main() {
    scanf("%d %d", &height, &width);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char c;
            scanf("%c", &c);

            if (c - '#' == 0) // TODO:
        }
    }
}
