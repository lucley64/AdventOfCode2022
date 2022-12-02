#include <iostream>
#include "day1.h"
#include "day2.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int choice;
    cout << "Select day : " << endl;
    cout << "   1- Calorie Counting" << endl;
    cout << "   2- Rock Paper Scissors" << endl;

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
        cout << "WTF?" << endl;
        break;

    default:
        break;
    }

    return 0;
}
