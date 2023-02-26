#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    int N, K;
    scanf("%d", &N);

    int arr[N];
    std::string line;
    int temp;
    int i = 0;
    std::cin.ignore();
    std::getline(std::cin, line);

    std::istringstream ss(line);

    while (ss >> temp)
    {
        arr[i] = temp;
        i++;
    }

    scanf("%d", &K);
    K %= N;
    if (K < 0)
        K = N + K;

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[(i + K) % N]);
    }
    printf("\n");

    return 0;
}