#include <iostream>
#include <string>
#include <cmath>
using namespace std;
struct MBTI
{
    string name, type;
    float ne, ni, te, ti, se, si, fe, fi;
};
struct node
{
    float score;
    string name, type;
    node *next;
    node *prev;
    node()
    {
        next = NULL;
        prev = NULL;
    }
    node(string name, float score, string type)
    {
        next = NULL;
        prev = NULL;
        this->name = name;
        this->score = score;
        this->type = type;
    }
};
class doublylinkedlist
{
private:
    node *top;
    node *low;
    node *curr;
    node *bef;

public:
    void board(string name, float score, string type)
    {
        node *newnode = new node(name, score, type);
        if (top == NULL)
        {
            top = newnode;
            low = newnode;
        }
        else
            curr = top;
        {
            while (curr != NULL)
            {
                if (curr == top && curr->score > newnode->score)
                {
                    newnode->next = top;
                    curr->prev = newnode;
                    newnode->prev = 0;
                    top = newnode;
                    break;
                }
                else
                {
                    if (curr->score > newnode->score)
                    {
                        newnode->prev = bef;
                        newnode->next = curr;
                        curr->prev = newnode;
                        bef->next = newnode;
                        break;
                    }
                    else if (curr->next == 0)
                    {
                        low->next = newnode;
                        newnode->prev = curr;
                        low = newnode;
                        low->next = 0;
                        break;
                    }
                }
                bef = curr;
                curr = curr->next;
            }
        }
    }
    void print()
    {
        int I = 0, E = 0, N = 0, S = 0, T = 0, F = 0, P = 0, J = 0, i;
        curr = top;
        for (i = 0; i < 3; i++)
        {
            cout << "Your closest friend number " << i + 1 << " name  : " << curr->name << endl;
            cout << "Your closest friend number " << i + 1 << " score : " << curr->score << endl;
            cout << "Your closest friend number " << i + 1 << " type  : " << curr->type << endl;
            if (curr->type[0] == 'I')
            {
                I++;
            }
            else
            {
                E++;
            }
            if (curr->type[1] == 'N')
            {
                N++;
            }
            else
            {
                S++;
            }
            if (curr->type[2] == 'T')
            {
                T++;
            }
            else
            {
                F++;
            }
            if (curr->type[3] == 'P')
            {
                P++;
            }
            else
            {
                J++;
            }
            curr = curr->next;
        }
        cout << endl<< "Your MBTI type : ";
        if (I > E)
        {
            cout << "I";
        }
        else
        {
            cout << "E";
        }
        if (N > S)
        {
            cout << "N";
        }
        else
        {
            cout << "S";
        }
        if (T > F)
        {
            cout << "T";
        }
        else
        {
            cout << "F";
        }
        if (P > J)
        {
            cout << "P";
        }
        else
        {
            cout << "J";
        }
    }
};
void input(string name, float ne, float ni, float te, float ti, float se, float si, float fe, float fi, string type, struct MBTI *data)
{
    data->name = name;
    data->ne = ne;
    data->ni = ni;
    data->te = te;
    data->ti = ti;
    data->se = se;
    data->si = si;
    data->fe = fe;
    data->fi = fi;
    data->type = type;
}
int main()
{
    doublylinkedlist *calld = new doublylinkedlist();
    MBTI data[55], me;
    int i;
    float inv[55];
    input("Narutchai Mauensaen", 33.2, 27, 32, 28, 33, 32, 39, 40, "", &me);
    input("Warin Wattanapornprom", 32, 32, 27, 36, 29, 31, 28, 23, "INTP", &data[0]);
    input("Kornkanok Welagert", 28.4, 29.4, 29, 34, 27, 24, 23, 21, "ISTP", &data[1]);
    input("Kritamet Chongcharoen", 22.4, 21.2, 20, 27, 21, 30, 17, 21, "INTP", &data[2]);
    input("Kunakron Tana", 30, 24, 25, 27, 23, 28, 26, 17, "ENTP", &data[3]);
    input("Chinnapt Sukthong", 21, 25.6, 29, 30, 28, 29, 28, 30, "ISTJ", &data[4]);
    input("Chinavat Nachaithong", 35.6, 37.8, 27, 28, 28, 29, 36, 35, "ENFP", &data[5]);
    input("Teekamon Chaiwongwutikul", 23.4, 26, 27, 30, 28, 31, 26, 21, "ISTJ", &data[6]);
    input("Dollatham Charoethammkic", 37, 47.8, 43, 47, 47, 45, 37, 43, "INTJ", &data[7]);
    input("Thiyada Kittiwithitkun", 34, 26.6, 26, 29, 28, 34, 33, 32, "ESFJ", &data[8]);
    input("Thidarat Sitthidech", 29, 31.2, 26, 27, 17, 32, 33, 26, "INFJ", &data[9]);
    input("Phumiphat Santithawornying", 26.2, 28.6, 21, 25, 30, 31, 32, 20, "INFJ", &data[10]);
    input("Manotham Damnoen", 35.4, 29.4, 26, 28, 28, 19, 29, 27, "ENTP", &data[11]);
    input("Wachirawit Intapan", 29, 25, 21, 23, 32, 36, 14, 19, "INTP", &data[12]);
    input("Warit Teerapong", 35.8, 28.4, 28, 32, 18, 32, 31, 35, "INFP", &data[13]);
    input("Sasima Phanta", 20.4, 22.4, 32, 32, 24, 28, 25, 16, "ESTJ", &data[14]);
    input("Artima Rojanagamonson", 34.8, 28, 35, 32, 26, 32, 28, 17, "ESTJ", &data[15]);
    input("Koraphan Manitha", 22.4, 31.4, 33, 34, 33, 35, 25, 23, "INTP", &data[16]);
    input("Ganyawee Sanghom", 34.4, 36.8, 24, 32, 28, 35, 32, 34, "INFP", &data[17]);
    input("Kimhan Jongjaidee", 38.2, 32.2, 35, 34, 17, 28, 28, 18, "ENTP", &data[18]);
    input("Chaithawat Saklang", 24.8, 24.6, 29, 26, 29, 28, 29, 29, "ESFP", &data[19]);
    input("Nattanischa Aumpornchairuch", 29.2, 23.8, 28, 30, 22, 31, 32, 21, "ESTJ", &data[20]);
    input("Thanapong Simmanee", 23.4, 30.8, 35, 41, 31, 36, 39, 29, "ISFJ", &data[21]);
    input("Thidarut Deeramies", 31.6, 36.4, 24, 32, 32, 30, 24, 20, "ISTP", &data[22]);
    input("Panachai Suvimolopas", 34.2, 24.6, 31, 35, 33, 25, 32, 25, "ENTP", &data[23]);
    input("Pattanapol Saelim", 41.8, 37.8, 28, 21, 34, 34, 33, 23, "ENTP", &data[24]);
    input("Pichayut Sombat", 32.2, 25.2, 29, 27, 30, 31, 25, 26, "INTP", &data[25]);
    input("Poomthai Promkote", 39.6, 46.8, 33, 36, 32, 36, 30, 30, "INTP", &data[26]);
    input("Lalhada Suttiprapha", 27.8, 23.4, 21, 27, 24, 35, 26, 22, "ISFJ", &data[27]);
    input("Santijit Kamnak", 22.4, 20.6, 26, 26, 26, 30, 22, 25, "ISTJ", &data[28]);
    input("Kantinan Kuikeaw", 13.8, 16, 33, 31, 35, 32, 23, 16, "ESTJ", &data[29]);
    input("Chothanin Thitisrirat", 29.8, 28, 24, 26, 29, 32, 36, 18, "ESFJ", &data[30]);
    input("Warin Wattanapornprom", 32, 32, 27, 36, 29, 31, 28, 23, "INTP", &data[31]);
    input("Yanisa Mungkarotai", 23, 26.6, 28, 25, 17, 29, 29, 31, "INTJ", &data[32]);
    input("Jessada Pranee", 27.8, 24.2, 32, 29, 18, 20, 13, 31, "INTP", &data[33]);
    input("Suphanut Chanroong", 34.6, 32, 25, 29, 23, 24, 29, 26, "ENFP", &data[34]);
    input("Keerataphan Malai", 15.6, 28.2, 21, 31, 19, 28, 18, 23, "ISTP", &data[35]);
    input("Thanachot Wongyai", 24.8, 19.2, 25, 30, 22, 28, 19, 25, "INTP", &data[36]);
    input("Pawinnarut Pornpanarat", 47.4, 31.2, 36, 32, 36, 37, 29, 31, "ENTP", &data[37]);
    input("Phirada Chemmanmud", 23.6, 22.2, 28, 35, 27, 40, 23, 22, "ISTJ", &data[38]);
    input("Phattawee Witthayapanyanont", 37.2, 23.6, 36, 39, 34, 33, 31, 16, "INTP", &data[39]);
    input("Sathapana Tinop", 23.2, 30.6, 30, 36, 19, 21, 4, 28, "INTP", &data[40]);
    input("Nuttasit Tannitipaisal", 33.6, 34.4, 24, 24, 31, 35, 32, 25, "ENTP", &data[41]);
    input("Nut Somwang", 19.6, 19.2, 25, 32, 36, 30, 20, 17, "ESTJ", &data[42]);
    input("Pattarachanon Uraiwichaikul", 35.6, 28.4, 36, 38, 36, 28, 29, 30, "ESTJ", &data[43]);
    input("Pattarapong Srisawat", 32.4, 28.4, 32, 32, 28, 28, 28, 28, "ENTP", &data[44]);
    input("Krantharat Ratchart", 26.6, 21, 27, 27, 25, 26, 22, 19, "ESTJ", &data[45]);
    input("Pasin Laopooti", 32.8, 31, 28, 37, 29, 38, 25, 29, "INTP", &data[46]);
    input("Patchnida Hemwannanukul", 29.8, 23.4, 30, 26, 27, 30, 29, 29, "ESTJ", &data[47]);
    input("Nakamon Yongpaisarn", 28, 24, 31, 31, 29, 37, 28, 28, "INFP", &data[48]);
    input("Natthapon Tanateeraanan", 24.6, 22, 32, 32, 36, 38, 35, 27, "ESTP", &data[49]);
    input("Naphatchanun Suecey",23.4, 26, 31, 33, 24, 27, 31, 21, "ESFJ", &data[50]);
    input("Natchapon Ponlaem",33.6, 32, 34, 31, 31, 37, 36, 29, "ENTP", &data[51]);
    input("Phacharaphon Aiamphan",36.4, 36.4, 34, 32, 31, 31, 37, 29, "INTP", &data[52]);
    input("Sarita Tongsawat",33, 33.6, 25, 29, 25, 28, 35, 34, "INFJ", &data[53]);
    input("Thitirat Atchayasoontorn",31.1, 23.2, 23, 34, 23, 33, 24, 17, "INTP", &data[54]);

    for (i = 0; i < 55; i++)
    {
        inv[i] = sqrt(pow((data[i].ne - me.ne), 2) + pow((data[i].ni - me.ni), 2) + pow((data[i].te - me.te), 2) + pow((data[i].ti - me.ti), 2) + pow((data[i].se - me.se), 2) + pow((data[i].si - me.si), 2) + pow((data[i].fe - me.fe), 2) + pow((data[i].fi - me.fi), 2));
    }
    for (i = 0; i < 55; i++)
    {
        calld->board(data[i].name, inv[i], data[i].type);
    }
    calld->print();
}