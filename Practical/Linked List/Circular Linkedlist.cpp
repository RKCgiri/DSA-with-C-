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
class CLL{
	Node* tail;
	public:
		CLL(){
			tail=NULL;
		}
		void insertAtBeg(int);
		void insertAtEnd(int);
		void deleteAtBeg();
		void deleteAtEnd();
		void display();
};

void CLL::insertAtBeg(int val){
	Node* curr=new Node(val);
	if(tail==NULL){
		curr->next=curr;
		tail=curr;
		return;
	}
	curr->next=tail->next;
	tail->next=curr;
}
void CLL::insertAtEnd(int val){
	Node* curr=new Node(val);
	if(tail==NULL){
		curr->next=curr;
		tail=curr;
		return;
	}
	curr->next=tail->next;
	tail->next=curr;
	tail=curr;
}
void CLL::display(){
	if(tail==NULL){
		return;
	}
	Node* temp=tail->next;
	while(temp!=tail){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<temp->data<<endl;
}

void CLL::deleteAtBeg(){
	if(tail==NULL){
		return;
	}
	if(tail->next==tail){
		delete(tail);
		tail=NULL;
		return;
	}
	Node* del=tail->next;
	tail->next=tail->next->next;
	delete(del);
}
void CLL::deleteAtEnd(){
	if(tail==NULL){
		return;
	}
	Node* temp=tail->next,*del=tail;
	if(tail->next==tail){
		delete(tail);
		tail=NULL;
		return;
	}
	while(temp->next!=tail){
		temp=temp->next;
	}
	temp->next=tail->next;
	tail=temp;
	delete(del);
	
}


int main(){
	CLL l;
	int val,n;
	do{
		cout<<"1->insertAtBeg,2->insertAtEnd,3->display,4->deleteAtbeg, 5->deleteatEnd,6->end"<<endl;
		cin>>n;
		switch(n){
			case 1:
				cout<<"Enter the value"<<endl;
				cin>>val;
				l.insertAtBeg(val);
				break;
			case 2:
				cout<<"Enter the value"<<endl;
				cin>>val;
				l.insertAtEnd(val);
				break;
			case 3:
				l.display();
				break;
			case 4:
				l.deleteAtBeg();
				break;
			case 5:
				l.deleteAtEnd();
				break;
			case 6:
				exit(0);
			default:
				cout<<"Wrong Choise"<<endl;	
		}
	}while(n);
return 0;
}