#include <iostream>
using namespace std;

void Printarray(int number[][4], int length)
{
    cout << "COL     A       B       C" << endl;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << number[i][j] << "\t";
        }
        cout << endl;
    }
}

void sortA(int number[][4], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (number[i][1] > number[j][1] || (number[i][1] == number[j][1] && number[i][2] > number[j][2]) || (number[i][1] == number[j][1] && number[i][2] == number[j][2] && number[i][3] > number[j][3]))
            {
                int temp[4];
                for (int k = 0; k < 4; k++)
                {
                    temp[k] = number[i][k];
                    number[i][k] = number[j][k];
                    number[j][k] = temp[k];
                }
            }
        }
    }
}

void sortB(int number[][4], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (number[i][2] > number[j][2] || (number[i][2] == number[j][2] && number[i][3] > number[j][3]) || (number[i][2] == number[j][2] && number[i][3] == number[j][3] && number[i][1] > number[j][1]))
            {
                int temp[4];
                for (int k = 0; k < 4; k++)
                {
                    temp[k] = number[i][k];
                    number[i][k] = number[j][k];
                    number[j][k] = temp[k];
                }
            }
        }
    }
}

int main()
{
    int number[14][4] = {
        {1, 1, 1, 4},
        {2, 3, 1, 1},
        {3, 4, 4, 4},
        {4, 2, 4, 4},
        {5, 3, 5, 3},
        {6, 4, 3, 3},
        {7, 1, 3, 3},
        {8, 2, 4, 3},
        {9, 3, 3, 5},
        {10, 1, 5, 3},
        {11, 1, 1, 4},
        {12, 4, 1, 1},
        {13, 5, 2, 3},
        {14, 3, 5, 2}};
    int length = 14;

    cout << "Before sort" << endl;
    Printarray(number, length);
    cout << endl;
    sortA(number, length);
    cout << "Sortting A>B>C" << endl;
    Printarray(number, length);
    cout << endl;
    sortB(number, length);
    cout << "Sortting B>C>A" << endl;
    Printarray(number, length);
}