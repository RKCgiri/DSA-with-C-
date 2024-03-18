#include<bits/stdc++.h>
using namespace std;
#define size 10
class Stack{
	int top,arr[size];
	public:
		Stack(){
			top=-1;
		}
		bool isEmpty();
		bool isFull();
		void insert(int);
		void del();
		int getSize();
		void dislay();
};
bool Stack::isEmpty(){
	return top==-1;
}
bool Stack::isFull(){
	return top==size-1;
}
void Stack::insert(int val){
	if(isFull()){
		cout<<"Circular queue is full "<<endl;
		return;
	}
	else{
		if(isEmpty()){
			top=0;
		}
		else{
			top++;
		}
		arr[top]=val;
	}
}

void Stack::del(){
	if(isEmpty()){
		cout<<"Stack is empty "<<endl;
		return;
	}
	else{
		cout<<"poped elemet is "<<arr[top--]<<endl;
		}

}
int Stack::getSize(){
	if(isEmpty()){
		cout<<"No elemet present "<<endl;
		return 0;
	}
	else{
		return top+1;
	}
}
void Stack::dislay(){
	if(isEmpty()){
		cout<<"No element is present "<<endl;
		return;
	}
	cout<<"The elements are =";
		for(int i=0;i<=top;i++){
			cout<<arr[i]<<",";
		}
		cout<<endl;
}
int main(){
	Stack s;
	int n,val;
	do{
		cout<<"1->insetrt,2->del,3->display,4->size,5->empty,6->full,7->exit"<<endl;
		cin>>n;
		switch(n){
			 case 1:
			 	cout<<"Enter the val to insert = ";
			 	cin>>val;
			 	s.insert(val);
			 	cout<<endl;
			 	break;
			case 2:
				s.del();
				break;
			case 3:
				s.dislay();
				break;
			case 4:
				cout<<"Size of the circular quque is "<<s.getSize()<<endl;
				break;
			case 5:
				cout<<s.isEmpty()<<endl;
				break;
			case 6:
				cout<<s.isFull()<<endl;
				break;
			case 7:
				exit(0);
			default:
				cout<<"Wrong choise "<<endl;
		}
	}while(1);
	return 0;
}
