#include <iostream>
using namespace std;

class twoDArray
{

private:
    static const int size = 3;
    int arr[size][size];

public:
    void initialize()
    {

        cout << "Input: " << endl;

        for (int i = 0; i < size; i++) // rows
        {
            for (int j = 0; j < size; j++) // columns
            {
                cin >> arr[i][j];
            }
            cout << endl;
        }
    }

    void print()
    {

        cout << "Output: " << endl;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    void transpose()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << arr[j][i] << " ";
            }
            cout << endl;
        }
    }

    void isSymmetry()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (arr[i][j] == arr[j][i])
                {
                    cout << "Symmetric";
                    break;
                }
                else
                {
                    cout << "Not Symmetric";
                    break;
                }
            }
        }
    }
};

int main()
{
    twoDArray a1;
    a1.initialize();
    a1.transpose();
    // a1.print();
    //a1.isSymmetry();
    return 0;
}