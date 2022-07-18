#include<iostream>
using namespace std;

class Date{

private:
    int date, month, year;  
public:


    Date()
    {
        date = month = year = 0;
    }

    Date(int dt, int mon, int yr)
    {
        date = dt;
        month = mon;
        year = yr;
    }


    friend istream& operator>>(istream& in, Date &d)
    {
        cout << "Enter Date(dd): ";
        in >> d.date;
        cout << "Enter Month(mm): ";
        in >> d.month;
        cout << "Enter Year(yyyy): ";
        in >> d.year;

        return in;
    }

    friend ostream& operator<<(ostream& out, Date &d)
    {
        out << d.year << "/" << d.month << "/" << d.date;

        return out;
    }

    bool operator>(Date &d)
    {
        if(this->year > d.year)
        {
            return false;
        }
        else if(this->year == d.year)
        {
            if(this->month > d.month)
            {
                return false;
            }   
            else if(this->month == d.month)
            {
                if(this->date > d.date)
                {
                    return false;
                }   
                else 
                    return true;
            }   
        }
    }
};

class Person{

private:

    string un;
    int id;
    Date d;
    static int counter;

public:

    Person()
    {
        un = " ";
        id = 0;
        counter++;
    }

    Person(string user, int identity)
    {
        un = user;
        id = identity;
    }

    friend class Date;

    friend istream& operator>>(istream&in, Person &p);
    friend ostream& operator<<(ostream& out, Person &p);

    void compare(Person p)
    {
        if(this->d > p.d)
        {
            cout << this->un <<" is senior to " << p.un << " because " << this->d << " is earlier than " << p.d;
        }
        else
            cout << p.un <<" is senior to " << this->un << " because " << p.d << " is earlier than " << this->d;
    }
};

istream& operator>>(istream& in, Person &p)
{
    cout << "\nPerson No. " << p.counter << " Data" << endl;
    cout << "Enter Username: ";
    in >> p.un;
    cout << "Enter ID: ";
    in >> p.id;
    in >> p.d;
    
    return in;
}

ostream& operator<<(ostream& out, Person &p)
{
    out << "Username: " << p.un << endl;
    out << "ID: " << p.id << endl;
    out << p.d << endl << endl;

    return out;
}

int Person::counter = 0;

int main()
{

    Person p1;

    cin >> p1;
    //cout << p1;
    Person p2;

    cin >> p2;
    //cout << p2;

    p1.compare(p2);

    return 0;
}