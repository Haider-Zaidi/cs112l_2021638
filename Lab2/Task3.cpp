#include <iostream>
using namespace std;

int main()
{
    int num1, num2, base, carry = 0, temp1, temp2, tempSum, counter = 0, biSum=0, invert=1, denSum;

    cout << "Enter base:  ";
    cin >> base;
    cout<<"Enter num1:  ";
    cin >> num1;
    cout<<"Enter num2:  ";
    cin >> num2;
    
   
    if (base == 2)
    {
        while (counter < 8)
        {
            if (carry == 2)
                carry = 1;
            temp1 = num1 % 10, temp2 = num2 % 10;
            num1 = num1 / 10;
            num2 = num2 / 10;
            if (temp1 + temp2 + carry == 3)
            {
                carry = 1;
                tempSum = 1;
            }
            else if (carry + temp1 + temp2 == 2)
            {
                carry = 1;
                tempSum = 0;
            }
            else
            {
                tempSum = carry + temp1 + temp2;
                carry = 0;
            }

            biSum += tempSum*invert;
            invert *= 10;
            counter++;
        }

        cout << biSum;
    }

    else if (base == 10)
    {
        denSum = num1 + num2;
        cout << denSum;
    }
    



    return 0;
}