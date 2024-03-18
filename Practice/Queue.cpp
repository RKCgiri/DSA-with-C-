#include<bits/stdc++.h>
using namespace std;
#define size 10
class Queue{
	int front,rear,arr[size];
	public:
		Queue(){
			front=rear=-1;
		}
		bool isEmpty();
		bool isFull();
		void insert(int);
		void del();
		int getSize();
		void dislay();
};
bool Queue::isEmpty(){
	return front==rear;
}
bool Queue::isFull(){
	return rear==size-1;
}
void Queue::insert(int val){
	if(isFull()){
		cout<<"Circular queue is full "<<endl;
		return;
	}
	else{
		if(isEmpty()){
			rear=0;
		}
		else{
			rear++;
		}
		arr[rear]=val;
	}
}

void Queue::del(){
	if(isEmpty()){
		cout<<"Queue is empty "<<endl;
		return;
	}
	else{
		front++;
		cout<<"poped elemet is "<<arr[front]<<endl;
		}

}
int Queue::getSize(){
	if(isEmpty()){
		cout<<"No elemet present "<<endl;
		return 0;
	}
	else{
		return rear-front;
	}
}
void Queue::dislay(){
	if(isEmpty()){
		cout<<"No element is present "<<endl;
		return;
	}
	cout<<"The elements are =";
		for(int i=front;i<=rear;i++){
			cout<<arr[i]<<",";
		}
		cout<<endl;
}
int main(){
	Queue q;
	int n,val;
	do{
		cout<<"1->insetrt,2->del,3->display,4->size,5->empty,6->full,7->exit"<<endl;
		cin>>n;
		switch(n){
			 case 1:
			 	cout<<"Enter the val to insert = ";
			 	cin>>val;
			 	q.insert(val);
			 	cout<<endl;
			 	break;
			case 2:
				q.del();
				break;
			case 3:
				q.dislay();
				break;
			case 4:
				cout<<"Size of the circular quque is "<<q.getSize()<<endl;
				break;
			case 5:
				cout<<q.isEmpty()<<endl;
				break;
			case 6:
				cout<<q.isFull()<<endl;
				break;
			case 7:
				exit(0);
			default:
				cout<<"Wrong choise "<<endl;
		}
	}while(1);
	return 0;
}
