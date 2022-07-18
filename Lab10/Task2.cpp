#include<iostream>
using namespace std;

int main()
{
    int v1, v2;

    cout << "Enter First Value: ";
    cin >> v1;
    cout << "Enter Second Value: ";
    cin >> v2;
    
    cout << "\nImplicit Type Casting: " << endl << "Result: " << v1/v2 << endl;

    cout << "Explicit Type Casting: " << endl << "Result: " << (float)v1/v2;

    return 0;
}