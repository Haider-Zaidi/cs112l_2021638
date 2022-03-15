#include<iostream>
using namespace std;

class Parity{

private:
    int size;
    int* arr = new int[size];

public:

    Parity()
    {
        size = 0;
    }

    Parity(int sz)
    {
        size = sz;
    }

    void put(int num)
    {
        int* tempStr = new int[++size];

        for(int i = 0; i < size; i++)
        {
            tempStr[i] = arr[i];
        }

        tempStr[size-1] = num;

        arr = tempStr;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    void del()
    {
        int* tempStr = new int[--size];

        for (int i = 0; i < size; i++)
        {
            tempStr[i] = arr[i];
        }
        arr = tempStr;    
    }

    int test()
    {
        if(size%2 == 0)
        {
            return 1;
        }

        else{
            return 0;
        }
    }
    
};

bool exit()
{
    char in;
    cout << "\nPress Y/y to Exit or Any other key to continue: ";
    cin >> in;

    if(in == 'Y' || in == 'y')
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int menu, n;
    bool running = true;
    Parity p1;
    
    while (running)
    {
        cout << "*****************************" << endl;
        cout << "Enter 1 for adding a number" << endl;
        cout << "Enter 2 for printing numbers" << endl;
        cout << "Enter 3 for deleting last number" << endl;
        cout << "Enter 4 for checking if Even or Odd" << endl;
        cout << "\n\nEnter Option: ";
        cin >> menu;

        switch (menu)
        {
            case 1:
                cout << "Enter number to Add: ";
                cin >> n;
                p1.put(n);
                running = exit();
                break;

            case 2:
                p1.print();
                running = exit();
                break;

            case 3:
                p1.del();
                running = exit();
                break;

            case 4:
                cout << p1.test() << endl;
                break;

            default:
                cout << "Wrong Input";
                break;
        }
    }

    return 0;
}