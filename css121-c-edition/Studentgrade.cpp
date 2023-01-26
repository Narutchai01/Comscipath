#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

struct Students
{
    char name[50];
    int score;
};

double AvrScore(Students student[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += student[i].score;
    }
    double avrscore = sum / size;
    return avrscore;
}

double SDscore(Students student[], int size) {
    double avr = AvrScore(student, size);
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow(student[i].score - avr, 2);
    }
    double sd = sqrt(sum / size);
    return sd;
}

void Maxscore(Students student[], int size) {
    int maxscore = 0;
    for (int i = 0; i < size; i++) {
        if (student[i].score > maxscore) {
            maxscore = student[i].score;
        }
    }
    std::cout << "Maxscore : " << maxscore << std::endl;
}

void Minscore(Students student[], int size) {
    int minscore = 99999;
    for (int i = 0; i < size; i++) {
        if (student[i].score < minscore) {
            minscore = student[i].score;
        }
    }
    std::cout << "Minscore : " << minscore << std::endl;
}
void Median(Students* students, int len) {
    if (len % 2 == 0) {
        double mediannumber = (students[(len / 2) - 1].score + students[len / 2].score) / 2;
        cout << "Medianscore is : " << mediannumber << endl;
    } else {
        cout << "Medianscore is : " << students[len / 2].score << endl;
    }
}
void ModeScore(Students students[], int size) {
    vector<int> modemember;
    int maxcount = 0;
    int count = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (students[i].score == students[j].score) {
                count++;
            }
        }
        if (count >= maxcount) {
            maxcount = count;
            if (find(modemember.begin(), modemember.end(), students[i].score) == modemember.end()) {
                modemember.push_back(students[i].score);
            }
        }
        count = 0;
    }
    for (auto integer : modemember) {
        cout << integer << " ";
    }
    cout << "is modenumber value : " << maxcount << endl;
}



void Gradstudent(Students student[], int size) {
    double avr = AvrScore(student, size);
    double sd = SDscore(student, size);
    for (int i = 0; i < size; i++) {
        if (student[i].score > avr + (2 * sd)) {
            std::cout << student[i].name << " GRAD = A" << std::endl;
        } else if (student[i].score < avr + (2 * sd) && student[i].score > avr + sd) {
            std::cout << student[i].name << " GRAD = B" << std::endl;
        } else if (student[i].score < avr + sd && student[i].score > avr) {
            std::cout << student[i].name << " GRAD = C" << std::endl;
        } else if (student[i].score < avr && student[i].score > avr - sd) {
            std::cout << student[i].name << " GRAD = D" << std::endl;
        } else {
            std::cout << student[i].name << " GRAD = F" << std::endl;
        }
    }
}



int main()
{
    Students student[10];
    student[0] = {"John", 60};
    student[1] = {"Ono", 63};
    student[2] = {"Non", 66};
    student[3] = {"Bryan", 63};
    student[4] = {"Earth", 77};
    student[5] = {"Mon", 63};
    student[6] = {"Toto", 60};
    student[7] = {"Boom", 85};
    student[8] = {"Dikolo", 85};
    student[9] = {"Boss", 77};
    int size = (sizeof(student) / (sizeof(student[0])));


    Maxscore(student,size);
    Minscore(student,size);
    cout<<"AVR is : "<<AvrScore(student,size)<<endl;
    ModeScore(student,size);
    Median(student,size);
    cout<<"SDscore : "<<SDscore(student,size)<<endl;
    Gradstudent(student,size);
    return 0;
}
