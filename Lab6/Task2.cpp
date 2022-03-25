#include <iostream>
using namespace std;

class Officer
{

private:
    int id;
    string name;
    string rank;
    static int count;

    int reverse(int id)
    {
        int digit, rev = 0;

        do
        {
            digit = id % 10;
            rev = (rev * 10) + digit;
            id = id / 10;
        } while (id != 0);

        return rev;
    }

public:

    void setter()
    {
        cout << "\nEnter the ID of the officer: ";
        cin >> id;
        cout << "Enter the name of the officer: ";
        cin >> name;
        cout << "Enter the rank of the officer: ";
        cin >> rank;
    }

    void palindrome()
    {
        if (id == reverse(id))
        {
            cout << "\nThe officer is not allowed to enter the restricted area" << endl;
        }
        else
        {
            cout << "\nThe officer is allowed to enter the restricted area" << endl;
            count++;
        }
    }

    void counter()
    {
        cout << "\nTotal number of officers: " << count << endl;
    }
};

int Officer::count = 0;

int main()
{
    Officer o1;


    int menu;
    bool running = true;

    cout << "Please select the desired option" << endl;
    cout << "Enter 1 for entering the ID of Officer" << endl;
    cout << "Enter 2 to get Total Number of Officers" << endl;
    cout << "Enter 3 to Exit" << endl;

    while (running)
    {
        cout << "\n\nEnter Option: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            o1.setter();
            o1.palindrome();
            break;

        case 2:
            o1.counter();
            break;

        case 3:
            running = false;
            break;

        default:
            cout << "Wrong Input";
            break;
        }
    }

    return 0;
}