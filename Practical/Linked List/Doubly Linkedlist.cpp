#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* prev;
	node* next;
};
class DLL{
	node* head;
public:
	DLL(){
		head=NULL;
	}	
void addBeg(int);
void addEnd(int);
void display();
void delBeg();
void delEnd();
void deleteItem(int);
};

void  DLL::deleteItem(int key){
	if(head==NULL){
		cout<<"No elemet is present "<<endl;
		return;
	}
	if(head->data==key){
		delBeg();
		return;
	}
	node* temp=head;
	while(temp!=NULL && temp->data!=key){
		temp=temp->next;
	}	
	if(temp==NULL){
		cout<<"Such elemet is not present "<<endl;
	}
	else{
		node* del=temp;
		temp->prev->next=NULL;
		delete(del);
	}
}
void DLL::delBeg(){
	if(head==NULL){
		cout<<"empty list"<<endl;
		return;
	}
	if(head->next==NULL){
		node* temp=head;
		head=NULL;
		delete(temp);
		return;
	}
	node* temp=head;
	head=head->next;
	head->prev=NULL;
	delete(temp);
	display();
}
void DLL::delEnd(){
	if(head==NULL){
		cout<<"Empty so delete is not possible"<<endl;
		return;
	}
		if(head->next==NULL){
		node* temp=head;
		head=NULL;
		delete(temp);
		return;
	}
	node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}	
	node* del=temp;
	temp->prev->next=NULL;
	delete(del);
	display();
}
void DLL::addBeg(int item){
	node * curr=new node();
	curr->prev=NULL;
	curr->data=item;
	if(head==NULL){
		curr->next=NULL;
		head=curr;
		return;
	}
	head->prev=curr;
	curr->next=head;
	head=curr;
}
void DLL::addEnd(int item){
	node*temp=new node;
	temp->data=item;
	temp->next=NULL;
	if(head==NULL){
		temp->prev=NULL;
		temp->next=head;
		head=temp;
		return;
	}
	node* t=head;
	while(t->next!=NULL){
		t=t->next;
	}
	t->next=temp;
	temp->prev=t;
}
void DLL::display(){
	if(head==NULL){
		cout<<"Empty DLL"<<endl;
		return;
	}
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" <-->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
int main(){
	DLL l;
		int val,n;
	do{
		cout<<"1->insertAtBeg,2->insertAtEnd,3->display,4->deleteAtbeg, 5->deleteatEnd,6->delete item , 7->end"<<endl;
		cin>>n;
		switch(n){
			case 1:cout<<"Enter the value"<<endl;
					cin>>val;
					l.addBeg(val);
					break;
			case 2:cout<<"Enter the value"<<endl;
					cin>>val;
					l.addEnd(val);
					break;
			case 3:l.display();
					break;
			case 4:l.delBeg();
					break;
			case 5:l.delEnd();
					break;
			case 6:
				cout<<"Enter the item to delete = ";
				cin>>val;
				l.deleteItem(val);
				break;
			case 7:exit(0);
			default:
					cout<<"Wrong Choise"<<endl;
				
		}
	}while(n);
return 0;
}