#include<iostream>
using namespace std;

class Heater{

private:
    int tem;

public:
    Heater(){ tem = 15; }

    Heater(int temp){
        tem = temp;
    }

    void warmer()
    {
        tem += 5;
    }

    void cooler()
    {
        tem -= 5;
    }
    
    int access()
    {
        return tem;
    }

    void input()
    {
        cout << "\nInput: ";
        cin >> tem;
    }

    void display()
    {
        cout << "\nTemperature: " << access();
    }

    ~Heater(){}

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
    int menu;
    bool running = true;
    Heater h1;

    cout << "*****************************" << endl;
    cout << "Enter 1 for Temperature Input" << endl;
    cout << "Enter 2 for increasing Temperature by 5 degrees" << endl;
    cout << "Enter 3 for decreasing Temperature by 5 degrees" << endl;

    while (running)
    {
        cout << "\n\nEnter Option: ";
        cin >> menu;

        switch (menu)
        {
            case 1:
                h1.input();
                h1.display();
                running = exit();
                break;

            case 2:
                h1.warmer();
                h1.display();
                running = exit();
                break;

            case 3:
                h1.cooler();
                h1.display();
                running = exit();
                break;

            default:
                cout << "Wrong Input";
                break;
        }
    }

    return 0;
}