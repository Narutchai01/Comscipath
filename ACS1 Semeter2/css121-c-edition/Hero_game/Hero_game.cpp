#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n = 10;
    int map[10][10] = {};
    int tree[2] = {rand() % 10, rand() % 10};
    int birtday = 2, last = 0, slast = 4;
    int Taxicab = abs(last - birtday) + abs(slast - (10 - birtday));
    double Euclidean = sqrt(pow(last - birtday, 2) + pow(slast - (10 - birtday), 2));
    int Chebyshev = (5 > 10) ? abs(last - birtday) : abs(slast - (10 - birtday));

    map[tree[0]][tree[1]] = 1;    // tree
    map[birtday][last] = 2;       // hero
    map[10 - birtday][slast] = 3; // monster

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            int temp = map[i][j];
            map[i][j] = map[j][n - i - 1];
            map[j][n - i - 1] = map[n - i - 1][n - j - 1];

            map[n - i - 1][n - j - 1] = map[n - j - 1][i];
            map[n - j - 1][i] = temp;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Taxicab distance = " << Taxicab << endl;
    cout << "Euclidean distance = " << Euclidean << endl;
    cout << "Chebyshev distance = " << Chebyshev << endl;

    return 0;
}