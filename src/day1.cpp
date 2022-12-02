#include "day1.h"
#include <iostream>
#include <fstream>
#include <map>

void day1Part1Test();
void day1Part1();
std::map<int, int> countCalFromFile(const std::string &);
void getMostCals(const std::map<int, int> &, int &, int &, int &, int &, int &, int &);

void day1()
{
    std::cout << "This is day 1" << std::endl;
    day1Part1Test();
    day1Part1();
}

void day1Part1Test()
{
    int mostCalElf1;
    int mostCalElf2;
    int mostCalElf3;
    int mostCalNb1;
    int mostCalNb2;
    int mostCalNb3;
    auto calories = countCalFromFile("../res/day1Input/testinput.txt");
    getMostCals(calories, mostCalElf1, mostCalNb1, mostCalElf2, mostCalNb2, mostCalElf3, mostCalNb3);

    std::cout << "Day1 Part1 Test : The elf number " << mostCalElf1 << " has the most calories : " << mostCalNb1 << std::endl;
    std::cout << "Day1 Part1 Test : The elf number " << mostCalElf2 << " has the most calories : " << mostCalNb2 << std::endl;
    std::cout << "Day1 Part1 Test : The elf number " << mostCalElf3 << " has the most calories : " << mostCalNb3 << std::endl;
    std::cout << "Summ = " << mostCalNb1 + mostCalNb2 + mostCalNb3 << std::endl;
}

void day1Part1()
{
    int mostCalElf1;
    int mostCalElf2;
    int mostCalElf3;
    int mostCalNb1;
    int mostCalNb2;
    int mostCalNb3;
    auto calories = countCalFromFile("../res/day1Input/input.txt");
    getMostCals(calories, mostCalElf1, mostCalNb1, mostCalElf2, mostCalNb2, mostCalElf3, mostCalNb3);
    std::cout << "Day1 Part1 True : The elf number " << mostCalElf1 << " has the most calories : " << mostCalNb1 << std::endl;
    std::cout << "Day1 Part1 True : The elf number " << mostCalElf2 << " has the most calories : " << mostCalNb2 << std::endl;
    std::cout << "Day1 Part1 True : The elf number " << mostCalElf3 << " has the most calories : " << mostCalNb3 << std::endl;
    std::cout << "Summ = " << mostCalNb1 + mostCalNb2 + mostCalNb3 << std::endl;
}

std::map<int, int> countCalFromFile(const std::string &fileName)
{
    std::ifstream inputTest;
    std::string input;
    std::map<int, int> calElves;
    int cal = 0;
    int i = 0;
    inputTest.open(fileName);

    if (inputTest.is_open())
    {
        while (getline(inputTest, input))
        {
            if (input == "")
            {
                calElves.insert({i, cal});
                i++;
                cal = 0;
            }
            else
            {
                cal += atoi(input.c_str());
            }
        }
        calElves.insert({i, cal});

        inputTest.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }
    return calElves;
}

void getMostCals(const std::map<int, int> &calElves, int &mostCalElf1, int &mostCalNb1, int &mostCalElf2, int &mostCalNb2, int &mostCalElf3, int &mostCalNb3)
{
    mostCalElf1 = 0;
    mostCalElf2 = 0;
    mostCalElf3 = 0;
    mostCalNb1 = 0;
    mostCalNb2 = 0;
    mostCalNb3 = 0;
    for (const auto &kv : calElves)
    {
        if (kv.second > mostCalNb1)
        {
            mostCalElf3 = mostCalElf2;
            mostCalNb3 = mostCalNb2;
            mostCalElf2 = mostCalElf1;
            mostCalNb2 = mostCalNb1;
            mostCalElf1 = kv.first;
            mostCalNb1 = kv.second;
        }
        else if (kv.second > mostCalNb2)
        {
            mostCalElf3 = mostCalElf2;
            mostCalNb3 = mostCalNb2;
            mostCalElf2 = kv.first;
            mostCalNb2 = kv.second;
        }
        else if (kv.second > mostCalNb3)
        {
            mostCalElf3 = kv.first;
            mostCalNb3 = kv.second;
        }
        
    }
}