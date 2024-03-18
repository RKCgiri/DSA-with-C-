#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int val){
		data=val;
		next=NULL;
	}
};
class LinkedList{
	Node* front;
	Node* rear;
	public:
		LinkedList(){
			front=NULL;
			rear=NULL;
		}
	  	void enqueue(int);
	  	void dequque();
	  	bool isEmpty();
	  	int peek();
		void display();
};
void LinkedList::enqueue(int val){
	Node* curr=new Node(val);
	if(isEmpty()){
		rear=curr;
		front=curr;
		return;
	}
	rear->next=curr;
	rear=curr;
}
void LinkedList::dequque(){
	if(isEmpty()){
		cout<<"List is empty "<<endl;
		return;
	}
	Node* del=front;
	cout<<"poped element is "<<del->data<<endl;
	front=front->next;
	delete(del);
}
bool LinkedList::isEmpty(){
	return front==NULL;
}
void LinkedList::display(){
	if(isEmpty()){
		cout<<"No elemet is present "<<endl;
		return;
	}
	Node* temp=front;
	while(temp!=NULL){
		cout<<temp->data<<",";
		temp=temp->next;
	}
	cout<<endl;
}
int LinkedList::peek(){
	if(isEmpty()){
		cout<<"Empty list "<<endl;
		return -1;
	}
	return front->data;
}

int main(){
	LinkedList l;
		int n;
	do{
		cout<<"1->Insert,2->pop,3->display ,4->peek ,5->exit "<<endl;
	
		cin>>n;
		switch(n){
			case 1:
				cout<<"Enter the value = ";
				int val;
				cin>>val;
				l.enqueue(val);
				break;
			case 2:
				l.dequque();
				break;
			case 3:
				l.display();
				break;
			case 4:
				if(l.peek()!=-1)
					cout<<"peek elemet is "<<l.peek()<<endl;
				break;
			case 5:
				exit(0);
			default:
				cout<<"Wrong Choise"<<endl;
		}
		
	}while(1);
	
	return 0;
}

