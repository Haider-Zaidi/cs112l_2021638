#include<iostream>
using namespace std;

// Lab 9 Task 1

class Vehicle{

protected:
    int numOfTires;
    int size;
    int numOfSeats;

public:

    Vehicle()
    {
        numOfTires = 0;
        size = 0;
        numOfSeats = 0;
    }

    Vehicle(int noT, int sz, int noS)
    {
        numOfTires = noT;
        size = sz;
        numOfSeats = noS;
    }

    virtual void setValue(){

        cout << "Enter Number of Tires: ";
        cin >> numOfTires;
        cout << "Enter Size: ";
        cin >> size;
        cout << "Enter Number of Seats: ";
        cin >> numOfSeats;
    }

    virtual int getNumofTires()=0;   
    virtual int getSize()=0;       
    virtual int getNumofSeats()=0;   

    virtual void printValue(){
        cout << "Number of Tires: " << numOfTires << endl;
        cout << "Size: " << size << endl;
        cout << "Number of Seats: " << numOfSeats << endl;
    }

};

class Car: public Vehicle{

protected:
    string colour;

public:

    Car():Vehicle(){ colour = " ";}

    Car(int noT, int sz, int noS, string col):Vehicle(noT, sz, noS){
        colour = col;
    }

    void setValue()
    {
        cout << "\nEnter Number of Tires: ";
        cin >> numOfTires;
        cout << "Enter Size: ";
        cin >> size;
        cout << "Enter Number of Seats: ";
        cin >> numOfSeats;
        cout << "Enter Colour: ";
        cin >> colour;
    }

    int getNumofTires(){return numOfTires;}
    int getSize(){return size;}
    int getNumofSeats(){return numOfSeats;}

    virtual string getColour(){};

    void printValue()
    {
        cout << "\nNumber of Tires: " << getNumofTires() << endl;
        cout << "Size: " << getSize() << endl;
        cout << "Number of Seats: " << getNumofSeats() << endl;
        cout << "Number of Colour: " << colour << endl;
    }

};

class Vitz: public Car{

private:
    int model;
    string plateNum;

public:

    Vitz():Car(){
        model = 0;
        plateNum = " ";
    }

    Vitz(int noT, int sz, int noS, string col, int mod, string pltNo):Car(noT, sz, noS, col){
        model = mod;
        plateNum = pltNo;
    }

    void setValue()
    {
        cout << "\nEnter Number of Tires: ";
        cin >> numOfTires;
        cout << "Enter Size: ";
        cin >> size;
        cout << "Enter Number of Seats: ";
        cin >> numOfSeats;
        cout << "Enter Colour: ";
        cin >> colour;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Plate Number: ";
        cin >> plateNum;
    }

    string getColour(){return colour;};

    void printValue()
    {
        cout << "\nNumber of Tires: " << getNumofTires() << endl;
        cout << "Size: " << getSize() << endl;
        cout << "Number of Seats: " << getNumofSeats() << endl;
        cout << "Number of Colour: " << getColour() << endl;
        cout << "Model: " << model << endl;
        cout << "Plate Number: " << plateNum << endl;
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
    Vehicle* v1;
    Vehicle* v2;
    Car c;
    Vitz vz;

    v1 = &c;
    v2 = &vz;

    int menu;
    bool running = true;
    
    while (running)
    {
       cout << "\n\n********** MENU **********\n\n(Following Methods are invoked through Vehicle Class Pointers)\n" << endl;
       cout << "Enter 1 for Setting Value for Car Class" << endl;
       cout << "Enter 2 for Printing Value for Car Class" << endl;
       cout << "Enter 3 for Setting Value for Vitz Class" << endl;
       cout << "Enter 4 for Printing Value for Vitz Class" << endl;
       cout << "Enter 5 to Exit" << endl;
       cout << "\n\nEnter Option: ";
       cin >> menu;
    
       switch (menu)
       {
            case 1:
                v1->setValue();
                cout << endl << "Enter 2 in the Main Menu to see the result" << endl;
                running = exit();
                break;
    
            case 2:
                v1->printValue();
                running = exit();
                break;
    
            case 3:
                v2->setValue(); 
                cout << endl << "Enter 4 in the Main Menu to see the result" << endl;
                running = exit();
                break;
    
            case 4:
                v2->printValue();
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