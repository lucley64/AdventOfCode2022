#include "day5.h"

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

#include "utils.h"

void day5Test();
void day5True();
std::vector<std::stack<char>> getStacks(const std::vector<std::string> &);
std::string moveCrates(std::vector<std::stack<char>> &, const std::vector<std::string> &);
int getStartPos(const std::vector<std::string> &);
void getInstruction(const std::string &, int &, int &, int &);

void day5()
{
    std::cout << "This is day 5" << std::endl;
    day5Test();
    day5True();
}

void day5Test()
{
    auto input = readInput("../res/day5Input/testInput.txt");
    auto stacks = getStacks(input);
    auto tops = moveCrates(stacks, input);
    std::cout << "The tops of test are: " << tops << std::endl;
}

void day5True()
{
    auto input = readInput("../res/day5Input/input.txt");
    auto stacks = getStacks(input);
    auto tops = moveCrates(stacks, input);
    std::cout << "The tops are: " << tops << std::endl;
}

std::vector<std::stack<char>> getStacks(const std::vector<std::string> &input)
{
    std::vector<std::stack<char>> ret;

    int startPos = getStartPos(input);

    int nbStacks = input[startPos - 1][input[startPos - 1].size() - 2] - '0';

    ret.resize(nbStacks);

    for (const std::string *line = &input[startPos - 1] - 1; line >= &input[0]; --line)
    {
        for (int i = 0; i < nbStacks; ++i)
        {
            int pos = 4 * i + 1;
            if ((*line)[pos] != ' ')
            {
                ret[i].push((*line)[pos]);
            }
        }
    }
    return ret;
}

std::string moveCrates(std::vector<std::stack<char>> &stacks, const std::vector<std::string> &input)
{
    int startPos = getStartPos(input) + 1;
    std::string ret = "";
    std::stack<char> temp;
    for (; startPos < input.size(); startPos++)
    {
        int nb;
        int from;
        int to;
        getInstruction(input[startPos], nb, from, to);
        for (int i = 0; i < nb; ++i)
        {
            char c = stacks[from].top();
            stacks[from].pop();
            temp.push(c);
        }
        for (int i = 0; i < nb; ++i)
        {
            char c = temp.top();
            temp.pop();
            stacks[to].push(c);
        }
    }

    for (const auto &stack : stacks)
    {
        ret.append({stack.top()});
    }
    return ret;
}

int getStartPos(const std::vector<std::string> &input)
{
    int startPos = 0;
    for (const auto &line : input)
    {
        if (line == "")
        {
            break;
        }
        else
        {
            startPos++;
        }
    }
    return startPos;
}

void getInstruction(const std::string &line, int &nb, int &from, int &to)
{
    std::stringstream stream{line};
    std::string segment;
    std::vector<std::string> segString;

    while (std::getline(stream, segment, ' '))
    {
        segString.push_back(segment);
    }

    for (size_t i = 0; i < segString.size(); i++)
    {
        if (segString[i] == "move")
        {
            nb = atoi(segString[i + 1].c_str());
        }
        else if (segString[i] == "from")
        {
            from = atoi(segString[i + 1].c_str()) - 1;
        }
        else if (segString[i] == "to")
        {
            to = atoi(segString[i + 1].c_str()) - 1;
        }
    }
}