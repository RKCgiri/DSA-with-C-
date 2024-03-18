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
	Node* top;
	public:
		LinkedList(){
			top=NULL;
		}
		bool isEmpty();
	    void Push(int);
	
		void Pop();
	
		void display();
};
void LinkedList::Push(int val){
	Node* curr=new Node(val);
	curr->next=top;
	top=curr;
	
}
void LinkedList::Pop(){
	if(top==NULL){
	cout<<"No element is present in the list so deletion is not possible"<<endl;
	return;
	}
	Node* temp=top;
	cout<<"Poped element is = "<<temp->data<<endl;
	top=top->next;
	delete(temp);
}


void LinkedList::display(){
	if(top==NULL){
		cout<<"No element is present "<<endl;
		return;
	}
	Node* temp=top;
	while(temp!=NULL){
		cout<<temp->data<<" ->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
	
}

int main(){
	LinkedList st;
		int n;
	do{
		cout<<"1->Insert on statck,2->pop elemnt ,3->display ,4->exit "<<endl;
	
		cin>>n;
		switch(n){
			case 1:
				cout<<"Enter the value = ";
				int val;
				cin>>val;
				st.Push(val);
				break;
		
			case 3:
				st.display();
				break;
			case 2:
				st.Pop();
				break;
		
			case 4:
				exit(0);
			default:
				cout<<"Wrong Choise"<<endl;
		}
		
	}while(1);
	
	return 0;
}