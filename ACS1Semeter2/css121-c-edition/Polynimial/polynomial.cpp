#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using std::setw;

//declare node
class node{
	public:
		int coeff, expo;
		node *next;
	public:
		node(node *next = NULL){// without data
			next = next;
		}
		node(int coeff, int expo, node *next = NULL){//with data
			coeff = coeff;
			expo = expo;
			next = next;
		}
};

class slist{
	public:
		node *head;
		node *tail;
		node *fence;
		
		void init(){
			fence = tail = head = new node();
		}
		
		void removeall(){//Return link nodes to free store(basic)
			while(head != NULL){
				fence = head;
				head = head->next;
				delete fence;
			}
		}
		
	    slist(){//constructor
	    	init();
	    	cout << "Check: list created" << endl;
		}
		
		~slist(){//destructor
			removeall();
			cout << "Check: list destroyed" << endl;
		}
		
		void clear(){
			removeall();
			init();
		}
		
		//sort polynomial node
		struct node *insert(struct node *head, int co, int ex){
			node *newNode = new node();
			node *temp = new node();
			newNode->coeff = co;
			newNode->expo = ex;
			newNode->next = NULL;
			
			if(head == NULL || ex > head->expo){
				newNode->next = head;
				tail = head;
				head = newNode;
			}else{
				temp = head;
				while(temp->next != NULL && temp->next->expo >= ex){
					temp = temp->next;
				}
				newNode->next = temp->next;
				temp->next = newNode;
			}
			return head;
		}
		
		//input infomation from keyboad
		struct node *create(struct node *head){
			int n, i, coeff, expo;
			cout << "Enter the number of terms: ";
			cin >> n;
			cout << "====================================" << endl;
			for(i=0;i<n;i++){
				cout << "Enter the cofficient for term " << i+1 << " : ";
				cin >> coeff;
				cout << "Enter the exponent for term " << i+1 << "   : ";
				cin >> expo;
				head = insert(head, coeff, expo);
				cout << "------------------------------------" << endl;
			}
			return head;
		}
		
		//display polynomial
		void display(node *head){
			if(head == NULL){
				cout << "No Polynomail ;w;" << endl;
			}else{
				node *temp = head;
				while(temp != NULL){
					cout << "(" << temp->coeff << "x^" << temp->expo << ")";
					temp = temp->next;
					if(temp != NULL){
						cout << "+";
					}else{
						cout << endl;
					}
				}
			}
		}
		
		//additional polynomial
		void addfunc(struct node *head1, struct node *head2){
			node *fence1 = head1;
			node *fence2 = head2;
			node *head3 = NULL;
			
			while(fence1!=NULL && fence2!=NULL){
				if(fence1->expo == fence2->expo){
					head3 = insert(head3, fence1->coeff+fence2->coeff, fence1->expo);
					fence1 = fence1->next;
					fence2 = fence2->next;
				}else if(fence1->expo > fence2->expo){
					head3 = insert(head3, fence1->coeff, fence1->expo);
					fence1 = fence1->next;
				}else if(fence2->expo > fence1->expo){
					head3 = insert(head3, fence2->coeff, fence2->expo);
					fence2 = fence2->next;
				}
			}
			
			while(fence1 != NULL){
				head3 = insert(head3, fence1->coeff, fence1->expo);
				fence1 = fence1->next;
			}
			while(fence2 != NULL){
				head3 = insert(head3, fence2->coeff, fence2->expo);
				fence2 = fence2->next;
			}
			cout << "====================================" << endl;
			cout << setw(26) << "Added polynomial" << endl;
			cout << "====================================" << endl;
			display(head3);
		}
		
		//multiplication polynomial
		void multifunc(struct node *head1, struct node *head2){
			node *fence1 = head1;
			node *fence2 = head2;
			node *head3 = NULL;
			
			if(head1 == NULL || head2 == NULL){
				cout << "Zero polynomial" << endl;
			}
			
			while(fence1 != NULL){
				fence2 = head2;
				while(fence2 != NULL){
					head3 = insert(head3, fence1->coeff*fence2->coeff, fence1->expo+fence2->expo);
					fence2 = fence2->next;
				}
				fence1 = fence1->next;
				
			}
			cout << "====================================" << endl;
			cout << setw(27) << "Multiply polynomial" << endl;
			cout << "====================================" << endl;
			display(head3);
		}
};

int main(){
	slist s1;
	node *head1 = NULL;
	node *head2 = NULL;
	cout << "====================================" << endl;
	cout << setw(25) << "1st polynomial" << endl;
	cout << "====================================" << endl;
	head1 = s1.create(head1);
	cout << "====================================" << endl;
	cout << setw(25) << "2nd polynomial" << endl;
	cout << "====================================" << endl;
	head2 = s1.create(head2);
	cout << "====================================" << endl;
	cout << setw(28) << "Polynomial function" << endl;
	cout << "====================================" << endl;
	cout << "Func1: ";
	s1.display(head1);
	cout << "Func2: ";
	s1.display(head2);
	s1.addfunc(head1, head2);
	s1.multifunc(head1, head2);	
}
