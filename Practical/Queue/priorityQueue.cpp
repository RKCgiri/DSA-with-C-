#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	int priority;
	Node* next;
};
class PQ{
	Node* head;
	public:
		PQ(){
			head=NULL;
		}
		void insert(int,int);
		void remove();
		void deleteatpos(int);
		void display();
};
void PQ::insert(int val,int priority){
	Node* curr=new Node;
	curr->data=val;
	curr->priority=priority; 
	if(head==NULL || head->priority>priority){
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
void PQ::display(){
	if(head==NULL){
		cout<<"No element present"<<endl;
		return;
	}
	Node* temp=head;
	while(temp!=NULL){
		cout<<"<"<<temp->data<<","<<temp->priority<<">"<<"---> ";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
void PQ::deleteatpos(int pos){
	if(head==NULL){
		cout<<"No elemet is present "<<endl;
		return;
	}
	if(pos==1){
		remove();
		return;
	}
	int cnt=1;
	Node* temp=head;
	while(cnt<pos-1 && temp!=NULL){
		cnt++;
		temp=temp->next;
	}
	if(!temp){
		cout<<"Such position is not present in priority queue "<<endl;
		return;
	}
	else{
		Node* del=temp->next;
		temp->next=temp->next->next;
		delete(del);
	}
}
void PQ::remove(){
	if(head==NULL){
		cout<<"No elemet is present "<<endl;
		return;
	}
	Node* del=head;
	head=head->next;
	delete(del);
}
int main(){
	PQ p;
	int val,priority,n;
	do{
		cout<<"1->insert,2-> remove , 3->delete at position 4->display,5->end"<<endl;
		cin>>n;
		switch(n){
			case 1:cout<<"Enter the value"<<endl;
					cin>>val;
					cin>>priority;
					p.insert(val,priority);
					break;
			case 2:
				p.remove();
				break;
			case 3:
				cout<<"Enter the position tom delete "<<endl;
				cin>>val;
				p.deleteatpos(val);
				break;
			case 4:p.display();
					break;
			case 5:exit(0);
			default:
					cout<<"Wrong Choise"<<endl;
				
		}
	}while(n);
return 0;
}