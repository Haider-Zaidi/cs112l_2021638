#include <iostream>
#include <string>
using namespace std;

class Person
{

private:
    string compName;
    string uniName;

public:
    
    void setterComp(string com)
    {
        compName = com;
    }
    void getterComp()
    {
        cout << compName << endl;
    }
    void setterUni(string uni)
    {
        uniName = uni;
    }
    void getterUni()
    {
        cout << uniName << endl;
    }

    void compareUni(Person p1, Person p2);
    int roomNum(Person p1, Person p2);
};

void Person::compareUni(Person p1, Person p2)
{

    for (int i = 0; i < 10; i++)
    {
        if (p1.uniName == p2.uniName)
        {
            cout << "Will be roommates" << endl;
            break;
        }
        else
        {
            cout << "Won't be roommates" << endl;
            break;
        }
    }
}

int Person::roomNum(Person p1, Person p2)
{
    int fLen = 0;
        for (int i = 0; p1.compName[i] != '\0'; i++)
        {
            fLen++;
        }
        
        int sLen = 0;
        for (int i = 0; p2.compName[i] != '\0'; i++)
        {
            sLen++;
        }

        if(fLen > sLen)
        {
            return fLen;
        }
        else{
            return sLen;
        }
}

int main()
{

    Person p1, p2;

    p1.setterComp("AIC");
    p1.getterComp();
    p1.setterUni("GIKI");
    p1.getterUni();

    p2.setterComp("PC");
    p2.getterComp();
    p2.setterUni("GIKI");
    p2.getterUni();

    p1.compareUni(p1, p2);

    cout << "Room Number: " << p1.roomNum(p1, p2);
    
    return 0;
}