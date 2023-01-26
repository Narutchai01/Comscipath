#include <iostream>
#include <vector>
using namespace std;

class Students
{
public:
    string name;
    int score;
};

double AvrScore(vector<Students> &student)
{
    double sum = 0;
    for (int i = 0; i < student.size(); i++)
    {
        sum += student[i].score;
    }
    double avrscore = sum / student.size();

    return avrscore;
}

void Maxscore(vector<Students> &student)
{
    int maxscore = 0;
    for (int i = 0; i < student.size(); i++)
    {
        if (student[i].score > maxscore)
        {
            maxscore = student[i].score;
        }
    }
    cout << "Maxscore : " << maxscore << endl;
}

void Minscore(vector<Students> &student)
{
    int minscore = 99999;
    for (int i = 0; i < student.size(); i++)
    {
        if (student[i].score < minscore)
        {
            minscore = student[i].score;
        }
    }
    cout << "Minscore : " << minscore << endl;
}

void ModeScore(vector<Students> &students)
{
    vector<int> modemember;
    int maxcount = 0;
    int count = 0;

    for (int i = 0; i < students.size(); i++)
    {
        for (int j = 0; j < students.size(); j++)
        {
            if (students[i].score == students[j].score)
            {
                vector<Students> student(10);
                string nameStudent[] = {"Art", "Fluk", "Ohm", "Mungkorn", "James", "Bell", "Pub", "Keng", "Leo", "Shogun"};
                int scoreStudnet[] = {90, 90, 70, 70, 85, 80, 92, 91, 82, 87};

                for (int i = 0; i < student.size(); i++)
                {
                    student[i].name = nameStudent[i];
                    student[i].score = scoreStudnet[i];
                }
                // Maxscore(student);
                // Minscore(student);
                // cout << "AVR : " << AvrScore(student) << endl;
                // ModeScore(student);
                // Median(student);
                // cout << "SDscore : " << fixed << setprecision(2) << SDscore(student) << endl;
                // Gradstudent(student);

                return 0;
            }
        }
    }
}
