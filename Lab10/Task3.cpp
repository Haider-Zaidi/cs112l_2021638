#include<iostream>
using namespace std;

int main()
{
    double len, wid;

    cout << "Enter the length of rectangle: ";
    cin >> len;
    cout << "Enter the width of rectangle: ";
    cin >> wid;

    cout << "Int: " << endl << "The area of the rectangle is: " << static_cast<int>(len*wid) << "\n\n";

    cout << "Float: " << endl << "The area of the rectangle is: " << static_cast<float>(len*wid) << endl;

    return 0;
}