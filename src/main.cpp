#include <iostream>
#include "day1.h"
#include "day2.h"
#include "day3.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int choice;
    cout << "Select day : " << endl;
    cout << "   1- Calorie Counting" << endl;
    cout << "   2- Rock Paper Scissors" << endl;
    cout << "   3- Rucksack Reorganization" << endl;

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
        cout << "WTF?" << endl;
        break;

    default:
        break;
    }

    return 0;
}
