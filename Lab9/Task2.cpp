#include<iostream>
using namespace std;

// Lab 9 Task 2

class MyFather{

protected: 
    string name;
    string eyeColour;
    string hairColour;

public:

    MyFather()
    {
        name = " ";
        eyeColour = " ";
        hairColour = " ";
    }

    MyFather(string n, string ec, string hc)
    {
        name = n;
        eyeColour = ec;
        hairColour = hc;
    }

    virtual void setValues()
    {
        cout << "\nEnter Name: ";
        cin >> name;
        cout << "Enter Eye Colour: ";
        cin >> eyeColour;
        cout << "Enter Hair Colour: ";
        cin >> hairColour;
    }

    virtual void getValues()
    {
        cout << "\nName: " << name << endl;
        cout << "Eye Colour: " << eyeColour << endl;
        cout << "Hair Colour: " << hairColour << endl;
    }
};

class MyMother{

protected: 
    string name;
    string eyeColour;
    string hairColour;

public:

    MyMother()
    {
        name = " ";
        eyeColour = " ";
        hairColour = " ";
    }

    MyMother(string n, string ec, string hc)
    {
        name = n;
        eyeColour = ec;
        hairColour = hc;
    }

    virtual void setValues()
    {
        cout << "\nEnter Name: ";
        cin >> name;
        cout << "Enter Eye Colour: ";
        cin >> eyeColour;
        cout << "Enter Hair Colour: ";
        cin >> hairColour;
    }

    virtual void getValues()
    {
        cout << "\nName: " << name << endl;
        cout << "Eye Colour: " << eyeColour << endl;
        cout << "Hair Colour: " << hairColour << endl;
    }
};

class Myself: public MyFather{

private:
    string education;
    int age;

public:

    Myself(string n, string ec, string hc, string edu, int a):MyFather(n, ec, hc)
    {
        education = edu;
        age = a;
    }

    Myself():MyFather()
    {
        education = " ";
        age = 0;
    }

    void setValues()
    {
        MyFather::setValues();
        cout << "Enter Education: ";
        cin >> education;
        cout << "Enter Age: ";
        cin >> age;
    }

    void getValues()
    {
        MyFather::getValues();
        cout << "Education: " << education << endl;
        cout << "Age: " << age << endl;
    }

};

class MySister: public MyFather, public MyMother{

private:
    string education;
    int age;

public:

    MySister():MyFather(),MyMother()
    {
        education = " ";
        age = 0;
    }

    MySister(string n, string ec, string hc, string edu, int a):MyFather(n, ec, hc), MyMother(n, ec, hc)
    {
        education = edu;
        age = a;
    }

    void setValues()
    {
        MyMother::setValues();
        cout << "Enter Education: ";
        cin >> education;
        cout << "Enter Age: ";
        cin >> age;
    }

    void getValues()
    {
        MyMother::getValues();
        cout << "Education: " << education << endl;
        cout << "Age: " << age << endl;
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

    MyFather* f;
    MyMother* m;
    Myself my;
    MySister s;

    f = &my;
    m = &s;

    int menu;
    bool running = true;
    
    while (running)
    {
       cout << "\n\n********** MENU **********\n\n(Following Methods are invoked through MyFather or MyMother Class Pointers)\n" << endl;
       cout << "Enter 1 for Setting Values for Myself Class" << endl;
       cout << "Enter 2 for Getting Values for Myself Class" << endl;
       cout << "Enter 3 for Setting Values for MySister Class" << endl;
       cout << "Enter 4 for Getting Values for MySister Class" << endl;
       cout << "Enter 5 to Exit" << endl;
       cout << "\n\nEnter Option: ";
       cin >> menu;
    
       switch (menu)
       {
            case 1:
                f->setValues();
                cout << endl << "Enter 2 in the Main Menu to see the result" << endl;
                running = exit();
                break;
    
            case 2:
                f->getValues();
                running = exit();
                break;
    
            case 3:
                m->setValues();
                cout << endl << "Enter 4 in the Main Menu to see the result" << endl;
                running = exit();
                break;
    
            case 4:
                m->getValues();
                running = exit();
                break;
    
            case 5:
                running = false;
                break;

            default:
                cout << "\nWrong Input\n";
                break;
        }
    }

    return 0;
}