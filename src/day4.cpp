#include "day4.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


void day4Test();
void day4True();
std::vector<std::string> readInput(const std::string &);
int countOverlap(const std::vector<std::string> &);
bool isOverlappingOther(const std::string &);

void day4()
{
    std::cout << "This is day 4" << std::endl;
    day4Test();
    day4True();
}

void day4Test()
{
    auto input = readInput("../res/day4Input/inputTest.txt");
    std::cout << "There are " << countOverlap(input) << " pairs overlapping the other in test" << std::endl;
}

void day4True()
{
    auto input = readInput("../res/day4Input/input.txt");
    std::cout << "There are " << countOverlap(input) << " pairs overlapping the other" << std::endl;
}

std::vector<std::string> readInput(const std::string &fileName)
{
    std::ifstream file{fileName};
    std::vector<std::string> lines;
    std::string line;

    if (file.is_open())
    {

        while (getline(file, line))
        {
            lines.push_back(line);
        }

        file.close();
    }

    return lines;
}

int countOverlap(const std::vector<std::string> &lines)
{
    int count = 0;

    for (const auto &line : lines)
    {
        if (isOverlappingOther(line))
        {
            count++;
        }
    }

    return count;
}

bool isOverlappingOther(const std::string &line)
{
    std::stringstream lineStream{line};
    std::string segment;
    std::string segment2;
    std::vector<std::string> segList;

    while (std::getline(lineStream, segment, ','))
    {
        std::stringstream lineStream2{segment};
        while (std::getline(lineStream2, segment2, '-'))
        {
            segList.push_back(segment2);
        }
    }


    int startElf1 = atoi(segList[0].c_str());
    int startElf2 = atoi(segList[2].c_str());
    int endElf1 = atoi(segList[1].c_str());
    int endElf2 = atoi(segList[3].c_str());



    if ((startElf1 <= endElf2 && endElf1 >= startElf2) || (startElf2 <= endElf1 && endElf2 >= startElf1))
    {
        return true;
    }
    else
    {
        return false;
    }
}