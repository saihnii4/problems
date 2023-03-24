#include <sstream>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    scanf("%d", &N);

    int arr[N][N];

    for (int i = 0; i < N; i++) {
        int temp;
        std::string line;

        if (i == 0) cin.ignore();
        getline(cin, line);
        istringstream ss(line);

        for (int j = 0; j < N; j++) {
            ss >> temp;
            arr[i][j] = temp;
        }
    }

    int S = 0;

    for (int i = 0; i < N; i++)
        S += arr[i][i];

    int M = 0;
    bool bruh = false;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) if (i != j) {
            if (arr[i][j] > N*N) { bruh = true; break; }
            M += arr[i][j];
        }


    if (M % S == 0 && !bruh) printf("%s\n", "YES");
    else printf("%s\n", "NO");

    return 0;
}
