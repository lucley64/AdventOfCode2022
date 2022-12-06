#include <iostream>
#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"
#include "day6.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int choice;
    cout << "Select day : " << endl;
    cout << "   1- Calorie Counting" << endl;
    cout << "   2- Rock Paper Scissors" << endl;
    cout << "   3- Rucksack Reorganization" << endl;
    cout << "   4- Camp Cleanup" << endl;
    cout << "   5- Supply Stacks" << endl;
    cout << "   6- Tuning Trouble" << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        day1();
        break;
    case 2:
        day2();
        break;
    case 3:
        day3();
        break;
    case 4:
        day4();
        break;

    case 5:
        day5();
        break;
    case 6:
        day6();
        break;
    default:
        cout << "WTF?" << endl;
        break;
    }

    return 0;
}
