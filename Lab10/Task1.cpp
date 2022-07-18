#include<iostream>
using namespace std;

int main()
{
    float v1, v3;
    int v2;
    char v4, v5;

    cout << "Enter Value for first variable: ";
    cin >> v1;

    v2 = v1;

    cout << "Enter value for third variable: ";
    cin >> v3;

    cout << "Enter value for fourth variable: ";
    cin >> v4;

    cout << "Enter value for fifth variable: ";
    cin >> v5;

    v3 += v4;

    cout << "First Variable: " << v1 << endl;
    cout << "Second Variable: " << v2 << endl;

    cout << "Type casting char to int data type(Third + Fourth) = " << v3 << endl;

    v3 -= v4;
    v3 += v5;

    cout << "Type casting char to int data type(Third + Fourth) = " << v3 << endl;

    return 0;
}