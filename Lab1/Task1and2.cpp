#include<iostream>
using namespace std;

struct Record
{
    string name;
    string reg;
    string degree;
    int courses;
    int marks;
    float sgpa;

};

int main()
{
    Record student[3];
    float gp, GPperCourse = 0, totalGp = 0;


    for(int i = 0; i < 3; i++)
    {
        cout << "Enter the record of " << i+1 << " student: " << "\n\n";
        cout << "Enter the name: ";
        cin >> student[i].name;
        cout << "Enter the registration number: ";
        cin >> student[i].reg;
        cout << "Enter the degree program: ";
        cin >> student[i].degree;
        cout << "Enter the number of courses: ";
        cin >> student[i].courses;

        for(int j = 0; j < student[i].courses; j++)
        {
            cout << "Enter the marks of " << j + 1 << " courses: ";
            cin >> student[i].marks;

            if(student[i].marks >= 86)
            {
                gp = 4.00;
            }

            else if(student[i].marks >= 82 && student[i].marks < 86)
            {
                gp = 3.67;
            }
            else if(student[i].marks >= 78 && student[i].marks < 82)
            {
                gp = 3.33;
            }
            else if(student[i].marks >= 74 && student[i].marks < 78)
            {
                gp = 3.00;
            }
            else if(student[i].marks >= 70 && student[i].marks < 74)
            {
                gp = 2.67;
            }
            else if(student[i].marks >= 66 && student[i].marks < 70)
            {
                gp = 2.33;
            }

            GPperCourse = gp * 3;
            totalGp += GPperCourse;
        }

        student[i].sgpa = totalGp / (student[i].courses * 3);

        GPperCourse = 0;
        totalGp = 0;
        cout << endl;
    }

    cout << "S.No.          Name            Reg. No.        Degree Program      SGPA" << endl;
    
    for (int i = 0; i < 3; i++)
    {
        cout << i+1 << "              " << student[i].name << "              " << student[i].reg << "              " << student[i].degree << "         " << student[i].sgpa << endl;
        
    }

    cout << endl;
    float sortedArr[3], desc;

    for (int i = 0; i < 3; i++)
    {
        sortedArr[i] = student[i].sgpa;      
    }
    
    for (int i = 0; i < 4; ++i)   
    {
        for (int j = i + 1; j < 4; ++j)
        {
            if (sortedArr[i] < sortedArr[j])
            {
                desc = sortedArr[i];
                sortedArr[i] = sortedArr[j];
                sortedArr[j] = desc;
            }
        }
    }

    cout << "The Best Student is: " << endl;

    for (int i = 0; i < 3; i++)
    {
        if (student[i].sgpa == sortedArr[0])
        {
            cout << student[i].name << "       " << student[i].reg << "        " << student[i].degree << "     " << student[i].sgpa << endl;
        }
        
    }
    
    return 0;
}