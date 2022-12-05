#include "utils.h"

#include <fstream>

std::vector<std::string> readInput(const std::string &fileName)
{
    std::ifstream file{fileName};
    std::vector<std::string> lines;
    std::string line;

    if (file.is_open())
    {

        while (std::getline(file, line))
        {
            lines.push_back(line);
        }

        file.close();
    }

    return lines;
}