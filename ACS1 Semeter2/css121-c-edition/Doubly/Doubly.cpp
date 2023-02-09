#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct student
{
    int score;
    string name;
    student *next;
    student *prev;
};

student *head = NULL;
student *tail = NULL;

void insertStudent(int score, string name)
{
    student *temp = new student;
    temp->score = score;
    temp->name = name;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void sortStudents()
{
    student *current = head;

    while (current->next != NULL)
    {
        student *compare = current->next;
        while (compare != NULL)
        {
            if (current->score > compare->score)
            {
                swap(current->score, compare->score);
                swap(current->name, compare->name);
            }
            compare = compare->next;
        }
        current = current->next;
    }
}

void printStudents()
{
    student *temp = head;
    for (size_t i = 0; i < 10; i++)
    {
        cout << temp->name << " : " << temp->score << endl;
        temp = temp->next;
    }
    
}

int main()
{
    insertStudent(10, "John");
    insertStudent(20, "Jane");
    insertStudent(30, "Bob");
    insertStudent(5, "Tom");
    insertStudent(25, "Alice");
    insertStudent(100,"Fluk");
    insertStudent(50,"Do");
    insertStudent(20,"Luv");
    insertStudent(40,"Bell");
    insertStudent(99,"Sup");
    insertStudent(30,"Leo");

    sortStudents();
    printStudents();

    return 0;
}
