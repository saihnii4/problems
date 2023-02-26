#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main()
{
    std::string in;
    std::vector<int> numbers;
    int temp;
    std::getline(std::cin, in);

    std::istringstream ss(in);
    while (ss >> temp)
        numbers.push_back(temp);

    int peak = 0;
    int valley = 0;

    for (int i = 0; i < numbers.size(); i++)
    {
        if (i < 1 || i+1 >= numbers.size())
            continue;

        if (numbers[i - 1] < numbers[i] && numbers[i] > numbers[i + 1])
        {
            peak++;
        }
        else if (numbers[i - 1] > numbers[i] && numbers[i] < numbers[i + 1])
        {
            valley++;
        }
    }

    printf("%d %d\n", peak, valley);
}