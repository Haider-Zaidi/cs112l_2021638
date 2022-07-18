#include <iostream>
using namespace std;

class matrixType
{

private:
    int rows, cols;
    int **mat;

public:
    matrixType()
    {
        rows = cols = 0;

        mat = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            mat[i] = new int[cols];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                mat[i][j] = 0;
            }
        }
    }

    matrixType(int r, int c)
    {
        rows = r;
        cols = c;

        mat = new int*[rows];

        for (int i = 0; i < rows; i++)
        {
            mat[i] = new int[cols];
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                mat[i][j] = 0;
            }
        }
    }

    friend istream &operator>>(istream &in, matrixType &m);
    friend ostream &operator<<(ostream &out,const matrixType &m);

    matrixType operator+(matrixType m)
    {

        if(this->rows == m.rows && this->cols == m.cols)
        {
            matrixType result(m.rows, m.cols);
            for (int i = 0; i < this->rows; i++)
            {
                for (int j = 0; j < this->cols; j++)
                {
                    result.mat[i][j] = this->mat[i][j] + m.mat[i][j];
                }
            }
            return result;
        }
    }

    matrixType operator-(matrixType m)
    {

        if(this->rows == m.rows && this->cols == m.cols)
        {
            matrixType result(m.rows, m.cols);
            for (int i = 0; i < this->rows; i++)
            {
                for (int j = 0; j < this->cols; j++)
                {
                    result.mat[i][j] = this->mat[i][j]-m.mat[i][j];
                }
            }
            return result;
        }
    }

    matrixType operator*(matrixType m)
    {

        if(this->cols == m.rows)
        {
            matrixType result(this->rows, m.cols);

            for (int i = 0; i < this->rows; i++)
            {
                for (int j = 0; j < m.cols; j++)
                {   
                    for(int k = 0; k < this->cols; k++)
                    {
                        result.mat[i][j] += this->mat[i][k]*m.mat[k][j];
                    }
                }
            }
            return result;
        }
        else
            cout << "Invalid Size for Multiplication" << endl;    
    }    
};

istream &operator>>(istream &in, matrixType &m)
{
    cout << "Enter the Matrix Elements: " << endl;

    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.cols; j++)
        {
            in >> m.mat[i][j];
        }
    }

    return in;
}

ostream &operator<<(ostream &out,const matrixType &m)
{
    for (int i = 0; i < m.rows; i++)
    {

        for (int j = 0; j < m.cols; j++)
        {
            out << m.mat[i][j] << " ";
        }
        out << endl;
    }

    return out;
}

int main()
{
    int rows, cols;

    cout << "Enter the Number of Rows: ";
    cin >> rows;
    cout << "Enter the Number of Columns: ";
    cin >> cols;
    
    matrixType m1(rows, cols);

    cin >> m1;
    cout << m1;

    cout << "Enter the Number of Rows: ";
    cin >> rows;
    cout << "Enter the Number of Columns: ";
    cin >> cols;
    
    matrixType m2(rows, cols), m3;

    cin >> m2;
    cout << m2;

    // m3 = m1 + m2;
    // m3 = m1 - m2;
    m3 = m1 * m2;
    
    cout << m3;

    return 0;
}