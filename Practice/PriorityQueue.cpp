#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	int priority;
	Node* next;
	Node(int val,int p){
		priority=p;
		 data=val;
		next=NULL;
	}
};
class PQ{
	Node* head;
	public:
		PQ(){
			head=NULL;
		}
		void insert(int,int);
		void del();
		void display();
		bool isEmpty();
};

void PQ::insert(int val,int priority){
	Node* curr=new Node(val,priority);
	if(head==NULL || priority<head->priority){
		curr->next=head;
		head=curr;
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL && temp->next->priority<=priority){
		temp=temp->next;
	}
	curr->next=temp->next;
	temp->next=curr;
}
void PQ::del(){
	if(head==NULL){
		cout<<"No element present"<<endl;
		return;
	}
	Node* del=head;
	head=head->next;
	delete(del);
}
void PQ::display(){
	if(isEmpty()){
		cout<<"Empty"<<endl;
		return;
	}
	Node* temp=head;
	while(temp!=NULL){
		cout<<"<"<<temp->data<<","<<temp->priority<<">"<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
bool PQ::isEmpty(){
	return head==NULL;
}

int main(){
	PQ q;
	int n,val,p;
	do{
		cout<<"1->insert2->del,3->display,4->empty,5->exit"<<endl;
		cin>>n;
		switch(n){
			case 1:
				cout<<"Ente rvl and priority ";
				cin>>val>>p;
				q.insert(val,p);
				cout<<endl;
				break;
			case 2:
				q.del();
				break;
			case 3:
				q.display();
				break;
			case 4:
				cout<<q.isEmpty()<<endl;
				break;
			case 5:
				exit(0);
			default:
				cout<<"Wriong choise"<<endl;
		}
	}while(1);
	return 0;
}