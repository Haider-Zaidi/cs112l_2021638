#include<iostream>
using namespace std;

int timesTen(int* numPtr){
    return *(numPtr)*10;
}

int main()
{
    int in;

    cout << "Number: ";
    cin >> in;

    const int* num;

    num = &in;

    cout << "The value of ptr cast: " << timesTen(const_cast<int *>(num));

    return 0;
}