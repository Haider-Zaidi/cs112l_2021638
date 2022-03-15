#include<iostream>
using namespace std;

class Swap{
    
private:
    int a;
    int b;

public:
    void setter()
    {
        cout << "Enter the two values: \n";
        cin >> a >> b;
        cout << "Before Swapping A= " << a << " & B= " << b << endl;
    }

    int swapping()
    {
        b = a+b;
        a = b-a;
        b = b-a;

        return a, b;
    }

    void display()
    {
        cout << "After Swapping A= " << a << " & B= " << b;
        
    }
};

int main()
{
    Swap s1;
    s1.setter();
    s1.swapping();
    s1.display();
    
    return 0;
}