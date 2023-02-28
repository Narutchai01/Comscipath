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
		cout << endl
			 << "Your MBTI type : ";
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
	MBTI data[40], me;
	int i;
	float inv[40];
	input("Poramat Wongphueng", 29.4, 34, 34, 32, 30, 33, 29, 36, "", &me);
	input("Warin Wattanapornprom", 32, 32, 27, 36, 29, 31, 28, 23, "INTP", &data[0]);
	input("Kantinan Meesuk", 35.4, 31, 33, 30, 38, 31, 34, 31, "ENTP", &data[1]);
	input("Kumpanat Joompabuth", 26, 31, 33, 30, 26, 33, 30, 24, "INTJ", &data[2]);
	input("Kittiphot Amnakkittikul", 24.4, 30.2, 31, 34, 28, 36, 22, 17, "ISTJ", &data[3]);
	input("Kanate Boonsiri", 24.4, 18.4, 31, 30, 32, 34, 25, 24, "ISTJ", &data[4]);
	input("Jirakit Meesupparsert", 22.2, 25.8, 36, 37, 29, 36, 34, 22, "ENTJ", &data[5]);
	input("Jirasika Kijsanapitak", 43.2, 34, 36, 36, 39, 38, 40, 35, "INTP", &data[6]);
	input("Chisanupong Wipachainun", 34.6, 19, 18, 24, 19, 20, 30, 22, "INFP", &data[7]);
	input("Thapanee Rueangrongwat", 32.4, 27, 35, 34, 27, 23, 31, 19, "ENFP", &data[8]);
	input("Nachanon Nuanphet", 28.4, 25.6, 33, 35, 32, 30, 24, 26, "ESTP", &data[9]);
	input("Thanakrit  Sangsuwan", 30.2, 31.4, 35, 33, 36, 33, 36, 34, "ENTJ", &data[10]);
	input("Thunyathep Tassanaananchai", 19.4, 12, 25, 28, 25, 23, 23, 22, "ESTJ", &data[11]);
	input("Bavornthat Dangtang", 38.8, 28.8, 44, 39, 27, 36, 40, 33, "INTJ", &data[12]);
	input("Worabdin Piammahamongkol", 26, 27, 31, 32, 21, 41, 26, 21, "ISTJ", &data[13]);
	input("Pichsinee Angsuchaikij", 33.4, 38.6, 29, 29, 26, 37, 24, 25, "INTJ", &data[14]);
	input("Phutthiphong Saelu", 26.8, 30.6, 25, 31, 24, 19, 21, 20, "ENTP", &data[15]);
	input("Wutthichai piyarungroj", 30, 29.6, 34, 32, 38, 28, 33, 22, "ENTP", &data[16]);
	input("Surawee Kraikruan", 29.4, 30, 28, 25, 37, 23, 30, 36, "ENTP", &data[17]);
	input("Kanokwan Deelee", 29.8, 32, 17, 25, 26, 26, 32, 20, "ENFP", &data[18]);
	input("Katepiss Sriburapa", 29, 22.8, 40, 28, 27, 31, 29, 19, "ENTJ", &data[19]);
	input("Khananon Kamjumroon", 30, 23.2, 27, 32, 26, 30, 30, 25, "ENTP", &data[20]);
	input("Julalak Pongsri", 25.5, 33, 28, 34, 37, 27, 28, 24, "INFJ", &data[21]);
	input("Chinnakit Bunluepanyadee", 37.4, 32, 38, 37, 31, 35, 34, 30, "ESTJ", &data[22]);
	input("Chotnarint Phisitphadhrikul", 29.8, 26.4, 28, 36, 29, 30, 33, 28, "INTJ", &data[23]);
	input("Thitipong Thongkam", 18.4, 15, 30, 33, 33, 31, 26, 23, "ESTJ", &data[24]);
	input("Nitipat Sritharachiyanon", 25.4, 29.4, 30, 31, 37, 27, 36, 20, "ESTP", &data[25]);
	input("Palita Simaborvonsut", 28.2, 25.4, 31, 28, 30, 32, 25, 32, "ENTP", &data[26]);
	input("Pisanu Boonyaanan", 32.8, 31, 34, 40, 28, 26, 20, 30, "INTP", &data[27]);
	input("Pattarawarin Jeamthong", 18.2, 16.2, 21, 22, 22, 33, 23, 21, "ESTP", &data[28]);
	input("Pakorn Moungsri", 24.4, 24.2, 26, 34, 18, 22, 12, 20, "ISTJ", &data[29]);
	input("Poohdish Thawornsusin", 26.8, 15, 36, 35, 22, 26, 21, 23, "ESTJ", &data[30]);
	input("Wasamon Suksai", 37.4, 36.8, 39, 39, 26, 33, 31, 29, "INTJ", &data[31]);
	input("Witwisit Sorranawit", 26.4, 21.4, 35, 44, 31, 30, 36, 30, "ESTP", &data[32]);
	input("Weeraya Muenkai", 15.6, 25, 12, 19, 11, 19, 24, 20, "INFP", &data[33]);
	input("Nutyada Thanasinthunyawath", 31.6, 29.4, 32, 30, 34, 29, 31, 29, "ENTP", &data[34]);
	input("Thanathat Lertpinitamonkul", 31, 19.6, 21, 21, 20, 24, 19, 24, "INFP", &data[35]);
	input("Pronphol Tangaulrat", 19.8, 12, 24, 28, 28, 28, 23, 14, "ESTJ", &data[36]);
	input("Peerawat Manopapapin", 27, 26.6, 30, 32, 27, 32, 25, 23, "ESFP", &data[37]);
	input("Attaporn Peungsook", 38.6, 25.8, 29, 39, 22, 27, 33, 22, "INTP", &data[38]);
	for (i = 0; i < 39; i++)
	{
		inv[i] = sqrt(pow((data[i].ne - me.ne), 2) + pow((data[i].ni - me.ni), 2) + pow((data[i].te - me.te), 2) + pow((data[i].ti - me.ti), 2) + pow((data[i].se - me.se), 2) + pow((data[i].si - me.si), 2) + pow((data[i].fe - me.fe), 2) + pow((data[i].fi - me.fi), 2));
	}
	for (i = 0; i < 39; i++)
	{
		calld->board(data[i].name, inv[i], data[i].type);
	}
	calld->print();
}