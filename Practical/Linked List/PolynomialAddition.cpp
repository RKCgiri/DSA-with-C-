#include<bits/stdc++.h>
using namespace std;
struct Node{
	int coefficient;
	int exponant;
	Node* next;
};
class PQ{
	Node* head;
	public:
		PQ(){
			head=NULL;
		}
		void insert(int,int);
		void display();
		PQ operator+ (PQ &);
};
void PQ::insert(int coef,int exponant){
	Node* curr=new Node;
	curr->coefficient=coef;
	curr->exponant=exponant;
	if(head==NULL || head->exponant<exponant){
		curr->next=head;
		head=curr;
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL && temp->next->exponant>=exponant){
		temp=temp->next;
	}
	curr->next=temp->next;
	temp->next=curr;
}
void PQ::display(){
	if(head==NULL){
		cout<<"No element present"<<endl;
		return;
	}
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->coefficient<<"X^"<<temp->exponant<<"+";
		temp=temp->next;
	}
	cout<<endl;
}
PQ PQ::operator+(PQ & p){  //return type class_name::operatorr overloading.
	PQ result;
	Node* h1=head;
	Node* h2=p.head;
	while(h1!=NULL && h2!=NULL){
		if(h1->exponant>h2->exponant){
			result.insert(h1->coefficient,h1->exponant);
			h1=h1->next;
		}else if(h1->exponant<h2->exponant){
			result.insert(h2->coefficient,h2->exponant);
			h2=h2->next;
		}else{
			result.insert(h1->coefficient+h2->coefficient,h1->exponant);
			h1=h1->next;
			h2=h2->next;
		}
	}
	while(h1!=NULL){
		result.insert(h1->coefficient,h1->exponant);
		h1=h1->next;
	}
	
	while(h2!=NULL){
		result.insert(h2->coefficient,h2->exponant);
		h2=h2->next;
	}	
    return result;
}


int main(){
	PQ p1,p2,p3;
	int coef,exponant;
	p1.insert(2,3);
	p1.insert(1,1);
	p1.insert(3,5);
	p2.insert(2,3);
	p2.insert(1,1);
	p1.display();
	p2.display();
    p3=p1+p2;
    cout<<"After addition the result is = "<<endl;
    p3.display();
	
return 0;
}