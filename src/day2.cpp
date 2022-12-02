#include "day2.h"
#include <iostream>
#include <fstream>

void day2Test();
void day2True();

int lineScore(const std::string &);

void day2()
{
    std::cout << "This is day 2." << std::endl;
    day2Test();
    day2True();
}

void day2Test()
{
    std::ifstream file{"../res/day2Input/testInput.txt"};
    std::string line;
    int score = 0;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            score += lineScore(line);
            std::cout << line[0] << ", " << line[2] << std::endl;
        }
    }

    std::cout << "Test : The final score is " << score << std::endl;
}

void day2True()
{

    std::ifstream file{"../res/day2Input/input.txt"};
    std::string line;
    int score = 0;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            score += lineScore(line);
        }
    }

    std::cout << "The final score is " << score << std::endl;
}

int lineScore(const std::string &line)
{
    int score = 0;
    switch (line[0])
    {
    case 'A':
        switch (line[2])
        {
        case 'X':
            score = 3 + 0;
            break;
        case 'Y':
            score = 1 + 3;
            break;
        case 'Z':
            score = 2 + 6;
            break;
        default:
            break;
        }
        break;
    case 'B':
        switch (line[2])
        {
        case 'X':
            score = 1 + 0;
            break;
        case 'Y':
            score = 2 + 3;
            break;
        case 'Z':
            score = 3 + 6;
            break;
        default:
            break;
        }
        break;
    case 'C':
        switch (line[2])
        {
        case 'X':
            score = 2 + 0;
            break;
        case 'Y':
            score = 3 + 3;
            break;

        case 'Z':
            score = 1 + 6;
            break;

        default:
            break;
        }
        break;
    default:
        break;
    }
    return score;
}