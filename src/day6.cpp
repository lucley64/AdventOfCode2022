#include "day6.h"

#include <iostream>
#include <queue>

#include "utils.h"

void day6(const std::string &fileName);
int findStartOfPacketMarker(const std::string &);
bool hasRepeatChar(std::queue<char>);
int findStartOfMessageMarker(const std::string &);

void day6()
{
    std::cout << "This is day 6" << std::endl;
    day6("../res/day6Input/input.txt");
}

void day6(const std::string &fileName)
{
    auto input = readInput(fileName);
    int startOfPacketMarker = findStartOfPacketMarker(input[0]);
    std::cout << "Packet: The first marker is after character " << startOfPacketMarker << std::endl;
    int startOfMessageMarker = findStartOfMessageMarker(input[0]);
    std::cout << "Message: The first marker is after character " << startOfMessageMarker << std::endl;
}

int findStartOfPacketMarker(const std::string &str)
{
    std::queue<char> last4;
    int start = 0;
    for (const char &c : str)
    {
        if (last4.size() == 4)
        {
            if (hasRepeatChar(last4))
            {
                last4.pop();
                last4.push(c);
                start++;
            }
            else
            {
                return start;
            }
        }
        else
        {
            last4.push(c);
            start++;
        }
    }
    return start;
}

bool hasRepeatChar(std::queue<char> qstr)
{
    std::vector<char> vector;
    while (!qstr.empty())
    {
        vector.push_back(qstr.front());
        qstr.pop();
    }

    for (int i = 0; i < vector.size(); i++)
    {
        for (int j = i + 1; j < vector.size(); j++)
        {
            if (vector[j] == vector[i])
            {
                return true;
            }
        }
    }

    return false;
}

int findStartOfMessageMarker(const std::string &str)
{
    int start = 0;

    std::queue<char> last14;

    for (; start < str.length(); start++)
    {
        if (last14.size() == 14)
        {
            if (hasRepeatChar(last14))
            {
                last14.pop();
                last14.push(str[start]);
            }
            else
            {
                return start;
            }
        }
        else
        {
            last14.push(str[start]);
        }
    }

    return start;
}