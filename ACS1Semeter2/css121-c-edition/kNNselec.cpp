#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

struct Data
{
    float cogFunc[8];
    string type;
    float distance;
};

void printData(Data *, int);
float findDistance(Data, float *);
char findMajority(Data *, int, int);
void swap(int, int);
void selectionSort(Data *, int, int);

int main()
{
    const string fileName = "mbti_data.csv";
    const int dataNum = 49;
    float userCogFunc[8] = {13.8, 16, 33, 31, 35, 32, 23, 16};

    Data data[dataNum];
    Data tempData;
    ifstream inFile(fileName);
    string row;
    int rowNum = 0;

    // read and store csv file in an dataay
    while (getline(inFile, row))
    {
        istringstream linestream(row);
        string item;

        for (int i = 0; i < 8; i++)
        {
            getline(linestream, item, ',');
            stringstream ss(item);
            ss >> tempData.cogFunc[i];
        }

        getline(linestream, item, ',');
        tempData.type = item;

        data[rowNum] = tempData;
        rowNum++;
    }
    inFile.close();

    // calculate distance and assign into each struct
    for (int i = 0; i < dataNum; i++)
        data[i].distance = findDistance(data[i], userCogFunc);

    selectionSort(data, 3, dataNum);

    for (int i = 0; i < 4; i++)
        cout << findMajority(data, 3, i);

    cout << endl;

    return 0;
}

void printData(Data *data, int dataNum)
{
    for (int i = 0; i < dataNum; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << data[i].cogFunc[j] << "\t";

        cout << data[i].type << "\t";
        cout << data[i].distance << endl;
    }
}

float findDistance(Data data, float userData[8])
{
    float sum = 0;
    for (int i = 0; i < 8; i++)
        sum += pow(data.cogFunc[i] - userData[i], 2);

    float result = sqrt(sum);
    return result;
}

void swap(Data *xp, Data *yp)
{
    Data temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(Data *data, int k, int dataNum)
{
    int i, j, min_idx;
    for (i = 0; i < k; i++)
    {
        min_idx = i;
        for (j = i + 1; j < dataNum; j++)
        {
            if (data[j].distance < data[min_idx].distance)
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(&data[min_idx], &data[i]);
    }
}

// Boyer-Moore Majority Voting
char findMajority(Data *data, int voteNum, int index)
{
    int res = 0;
    int count = 1;
    for (int i = 1; i < voteNum; i++)
    {
        if (data[i].type[index] == data[res].type[index])
        {
            count++;
        }
        else
        {
            count--;
        }

        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }

    return data[res].type[index];
}