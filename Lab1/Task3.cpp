#include<iostream>
using namespace std;

struct Record{

    string name;
    int age;
    string city;
    int date;
    string month;
    int year;
};


int main()
{
    Record people[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "\nEnter the record of " << i+1 << " user: " << "\n\n";
        cout << "Enter the name: ";
        cin >> people[i].name;
        cout << "Enter the age: ";
        cin >> people[i].age;
        cout << "Enter the city: ";
        cin >> people[i].city;
        cout << endl;
        cout << "Enter the Date of Birth: " << endl;
        cout << "Enter day: ";
        cin >> people[i].date;
        cout << "Enter month: ";
        cin >> people[i].month;
        cout << "Enter year: ";
        cin >> people[i].year;
    }

    int dateToCheck;
    string monthToCheck;
    int yearToCheck;
    
    for (int i = 0; i < 3; i++)
    {
        cout << "\n\nEnter a Date of Birth to check: " << endl;
        cout << "Enter day: ";
        cin >> dateToCheck;
        cout << "Enter month: ";
        cin >> monthToCheck;
        cout << "Enter year: ";
        cin >> yearToCheck;

        if (people[i].date == dateToCheck && people[i].month == monthToCheck && people[i].year == yearToCheck)
        {
            cout << "It is " << people[i].name << "'s Birthday. Happy Birthday, " << people[i].name << "." << endl;
            break;
        }
        else{
            cout << "No one's Birthday";
            break;
        }
        
    }
    
    return 0;
}