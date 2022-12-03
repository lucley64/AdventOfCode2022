#include "day3.h"

#include <iostream>
#include <fstream>
#include <vector>

void day3Test();
void day3True();
char getComonChar(const std::string &);
char getComonChar3Line(const std::string &, const std::string &, const std::string &);

void day3()
{
    std::cout << "This is day 3" << std::endl;
    day3Test();
    day3True();
}

void day3Test()
{
    std::ifstream file{"../res/day3Input/inputTest.txt"};
    std::string line;
    char commonChar;
    int value;
    int sum = 0;
    std::vector<std::string> rucksacks;

    if (file.is_open())
    {
        while (getline(file, line))
        {
            std::cout << line << " (" << line.size() << ") " << std::endl;
            commonChar = getComonChar(line);
            if (commonChar > 'Z')
            {
                value = commonChar - 'a' + 1;
            }
            else
            {
                value = commonChar - 'A' + 27;
            }
            sum += value;
            std::cout << "common char: " << commonChar << ", Value: " << value << std::endl;
            rucksacks.push_back(line);
        }
        std::cout << "The total sum is " << sum << std::endl;
        file.close();

        sum = 0;
        for (int i = 0; i < rucksacks.size(); i += 3)
        {
            std::string line1 = rucksacks.at(i);
            std::string line2 = rucksacks.at(i + 1);
            std::string line3 = rucksacks.at(i + 2);
            commonChar = getComonChar3Line(line1, line2, line3);
            if (commonChar > 'Z')
            {
                value = commonChar - 'a' + 1;
            }
            else
            {
                value = commonChar - 'A' + 27;
            }
            std::cout << commonChar << ", " << value << std::endl;
            sum += value;
        }

        std::cout << "The total sum of badges is " << sum << std::endl;
    }
}

void day3True()
{
    std::ifstream file{"../res/day3Input/input.txt"};
    std::string line;
    char commonChar;
    int value;
    int sum = 0;

    std::vector<std::string> rucksacks;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            commonChar = getComonChar(line);
            if (commonChar > 'Z')
            {
                value = commonChar - 'a' + 1;
            }
            else
            {
                value = commonChar - 'A' + 27;
            }

            sum += value;
            rucksacks.push_back(line);
        }
        std::cout << "The total sum is " << sum << std::endl;
        file.close();
        sum = 0;
        for (int i = 0; i < rucksacks.size(); i += 3)
        {
            std::string line1 = rucksacks.at(i);
            std::string line2 = rucksacks.at(i + 1);
            std::string line3 = rucksacks.at(i + 2);
            commonChar = getComonChar3Line(line1, line2, line3);
            if (commonChar > 'Z')
            {
                value = commonChar - 'a' + 1;
            }
            else
            {
                value = commonChar - 'A' + 27;
            }
            std::cout << commonChar << ", " << value << std::endl;
            sum += value;
        }

        std::cout << "The total sum of badges is " << sum << std::endl;
    }
}

char getComonChar(const std::string &line)
{
    for (const char *i = &line[0]; i < &line[line.size() / 2]; i++)
    {
        for (const char *j = &line[line.size() / 2]; j < &line[line.size()]; j++)
        {
            if (*i == *j)
            {
                return *i;
            }
        }
    }
    return 'a';
}

char getComonChar3Line(const std::string &line1, const std::string &line2, const std::string &line3)
{
    for (const auto &c1 : line1)
    {
        for (const auto &c2 : line2)
        {
            for (const auto &c3 : line3)
            {
                if (c1 == c2 && c1 == c3)
                {
                    return c1;
                }
            }
        }
    }

    return 'a';
}