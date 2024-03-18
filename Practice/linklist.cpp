#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data ;
		node* next;
		node(int val){
			data=val;
			next=NULL;
		}
};
class linklist{
public:
void insertattail(node * &head,int  val){
	node* n=new node(val);
	node* temp=head;
		if(head==NULL)
		{
			head=n;
			return;
		}
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
}
void display(node * head){
	if(head==NULL){
		cout<<"Linklist is empty"<<endl;
		return;
	}
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
};
int main(){
	node* head=NULL;
	linklist l;
	l.display(head);
	l.insertattail(head,3);
	l.insertattail(head,6);
	l.insertattail(head,9);
	l.display(head);
}