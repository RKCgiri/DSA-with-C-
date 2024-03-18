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
	Node* head;
	public:
		LinkedList(){
			head=NULL;
		}
		void insertAtBeg(int);
		void insertAtEnd(int);
		void deleteAtBeg();
		void deleteAtEnd();
		void display();
		void reverse();
		bool search(int);
		
};

void LinkedList::insertAtBeg(int val){
	Node* curr=new Node(val);
	curr->next=head;
	head=curr;
}
void LinkedList::insertAtEnd(int val){
	if(head==NULL){
		insertAtBeg(val);
		return;
	}
	Node* curr=new Node(val);
	Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=curr;
}
void LinkedList::deleteAtBeg(){
	if(head==NULL){
		cout<<"No element is present "<<endl;
		return;
	}
	Node* del=head;
	head=head->next;
	delete(del);
}
void LinkedList::deleteAtEnd(){
	if(head==NULL){
		cout<<"No element present "<<endl;
		return;
	}
	Node* temp=head,*del;
	if(head->next==NULL){
		deleteAtBeg();
		return;
	}
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	del=temp->next;
	temp->next=NULL;
	delete(del);
}

void LinkedList::display(){
	if(head==NULL){
		cout<<"No element present "<<endl;
		return;
	}
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
bool LinkedList::search(int item){
	if(head==NULL){
		cout<<"No element is present"<<endl;
		return false;
	}
	Node* temp=head;
	while(temp!=NULL){
		if(temp->data==item) return true;
		temp=temp->next;
	}
	return false;
}
void LinkedList::reverse(){
	if(head==NULL) return;
	Node* p=head,*q,*r=NULL;
	while(p!=NULL){
		q=p;
		p=p->next;
		q->next=r;
		r=q;
	}
	head=q;
}

int main(){
	LinkedList l;
		int n;
	do{
		cout<<"1->InsertAtBeg, 2->InsertAtTail,3->display,4->deleteAtBeg , 5->DeleteAttail,6->SearchItem, 7->Reverse list,8->exit "<<endl;
	
		cin>>n;
		switch(n){
			case 1:
				cout<<"Enter the value = ";
				int val;
				cin>>val;
				l.insertAtBeg(val);
				break;
			case 2:
				cout<<"Enter the val = ";
				val;
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
				cout<<"Enter the element to search =- ";
				cin>>val;
				int n1;
				n1=l.search(val);
				if(n1!=-1){
					cout<<"The element is found "<<endl;
				}
				break;
			case 7:
				cout<<"Reverse the list "<<endl;
				l.reverse();
				break;
			case 8:
				exit(0);
			default:
				cout<<"Wrong Choise"<<endl;
		}
		
	}while(1);
	
	return 0;
}