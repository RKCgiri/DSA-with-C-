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
	    void insertAthead(int);
		void insertAttail(int);
		void insertAtposition(int,int,char);
		void deleteAthead();
		void deleteAttail();
		void deleteAtposition(int);
		void deleteItem(int);
		int searchItem(int);
		void bubbleSort();
		void reverseList();
		void display();
};
void LinkedList::insertAthead(int val){
	Node* curr=new Node(val);
	//curr->data=val;
	curr->next=head;
	head=curr;
	
}
void LinkedList::insertAttail(int val){
	if(head==NULL){
		insertAthead(val);
		return;
	}
	Node* curr=new Node(val);
	Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=curr;	
}
void LinkedList::insertAtposition(int val,int pos,char c){
	if(pos==1){
		if(c=='B'){
		insertAthead(val);
		return;			
		}
		else{
			if(head==NULL){
				cout<<"Insertion is not possible beacuse th head is null"<<endl;
				return;
			}
			Node* curr=new Node(val);
			curr->next=head->next;
			head->next=curr;
			return;
		}
	}
	Node* curr=new Node(val);
	Node* temp=head;
	int cnt=1;
	while((cnt<pos-1) && temp!=NULL){
		cnt++;
		temp=temp->next;
	}
	if(temp==NULL){
		cout<<"Insertion at the position is not possible"<<endl;
		return;
    }else{
    	if(c=='B'){
    		curr->next=temp->next;
    		temp->next=curr;
		}else {
			temp=temp->next;
			curr->next=temp->next;
			temp->next=curr;
		}
	}
	
}

void LinkedList::deleteAthead(){
	if(head==NULL){
	cout<<"No element is present in the list so deletion is not possible"<<endl;
	return;
	}
	Node* temp=head;
	head=head->next;
	delete(temp);
}
void LinkedList::deleteAttail(){	
	if(head==NULL){
		cout<<"No element is present in the list so deletion is not possible"<<endl;
		return;
	}
	Node* temp=head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	Node* del=temp->next;
	temp->next=NULL;
	delete(del);
    
}

void LinkedList::deleteAtposition(int pos ){
   	if(head==NULL){
	cout<<"No element is present in the list so deletion is not possible"<<endl;
	return;
	}
	if(pos==1){
		deleteAthead();
		return;
	}
	Node* temp=head;
	int cnt=1;
	while((cnt<pos-1) && temp!=NULL){
		temp=temp->next;
		cnt++;
	}
	if(temp==NULL){
		cout<<"Deletion is not possible at this position "<<endl;
		return;
	}
	else{
		Node* del=temp->next;
		temp->next=temp->next->next;
		delete(del);
	}
}

void LinkedList::deleteItem(int key){
	if(head==NULL){
		cout<<"No value is present"<<endl;
		return;
	}
	if(head->data==key){
		deleteAthead();
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL && temp->next->data!=key){
		temp=temp->next;
	}
	if(!temp->next){
		cout<<"Element is not present "<<endl;
		return;
	}
	else{
		Node* del=temp->next;
		temp->next=temp->next->next;
		delete(del);
	}
	
}
int LinkedList::searchItem(int key){
	if(head==NULL){
		cout<<"No elemmet is present "<<endl;
		return -1;
	}
	Node* temp=head;
	int cnt=1;
	while(temp!=NULL){
		if(temp->data==key){
			return cnt;
		}
		cnt++;
		temp=temp->next;
	}
	return -1;
}

void LinkedList::bubbleSort(){
	if(head==NULL){
		cout<<"Empty list "<<endl;
		return;
	}
	Node* temp,*last=NULL;
	int swaped;
	do{
		temp=head;
		swaped=0;
		while(temp->next!=last){
			if(temp->data>temp->next->data){
				int x=temp->data;
				temp->data=temp->next->data;
				temp->next->data=x;
				swaped=1;
			}
		temp=temp->next;
		}
		display();
	}while(swaped);
return;
}
void LinkedList::reverseList(){
	Node* p=head,*q,*r=NULL;
	while(p!=NULL){
		q=p;
		p=p->next;
		q->next=r;
		r=q;
	}
	head=q;
	display();
}

void LinkedList::display(){
	if(head==NULL){
		cout<<"No element is present "<<endl;
		return;
	}
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
	
}

int main(){
	LinkedList l;
		int n;
	do{
		cout<<"1->InsertAtBeg, 2->InsertAtTail, 3->InsertAtPosition,4->display,5->deleteAtBeg , 6->DeleteAttail,7->DeleteAtposition, 8->deleteItem, 9->SearchItem, 10->Reverse list ,11-> BubbleSort ,12->exit "<<endl;
	
		cin>>n;
		switch(n){
			case 1:
				cout<<"Enter the value = ";
				int val;
				cin>>val;
				l.insertAthead(val);
				break;
			case 2:
				cout<<"Enter the val = ";
				val;
				cin>>val;
				l.insertAttail(val);
				break;
			case 3:
				cout<<"Enter the val, position ,char after or before "<<endl;
				int pos;
				char c;
				cin>>val>>pos>>c;
				l.insertAtposition(val,pos,c);
				break;
			case 4:
				l.display();
				break;
			case 5:
				l.deleteAthead();
				break;
			case 6:
				l.deleteAttail();
				break;
			case 7:
				cout<<"Enter the position to delete the element = ";
				cin>>pos;
				l.deleteAtposition(pos);
				break;
			case 8:
				cout<<"Enter the element to delete = ";
				cin>>val;
				l.deleteItem(val);
				break;
			case 9:
				cout<<"Enter the element to search =- ";
				cin>>val;
				int n1;
				n1=l.searchItem(val);
				if(n1!=-1){
					cout<<"The element is found at "<<n1<<"th position "<<endl;
				}
				break;
			case 10:
				cout<<"Reverse the list "<<endl;
				l.reverseList();
				break;
			case 11:
				cout<<"Buble  Sort ="<<endl;
				l.bubbleSort();
				break;
			case 12:
				exit(0);
			default:
				cout<<"Wrong Choise"<<endl;
		}
		
	}while(1);
	
	return 0;
}