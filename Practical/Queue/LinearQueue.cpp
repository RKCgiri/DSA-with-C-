#include<bits/stdc++.h>
#define MAX_SIZE 3
using namespace std;
class Queue{
	public:
	 	int front,rear;
	 	int arr[MAX_SIZE];
	 	Queue(){
		 	front=-1;
		 	rear=-1;
	 	}
 	bool isEmpty();
 	bool isFull();
 	void enqueue(int val);
 	void dequeue();
  	void peek();
 	int size();
	
};
bool Queue::isEmpty(){
 	return (front==rear);
}
bool Queue::isFull(){
 	return rear==MAX_SIZE;
}
void Queue::enqueue(int x){
 	if(isFull())
		cout<<"The queue is full"<<endl;
 	else{
	 	if(rear==-1){
		 	front=0;
		 	rear=0;
		 	arr[rear++]=x;
 		}
	 	else
		 	arr[rear++]=x;
 	}
}
void Queue::dequeue(){
	if(isEmpty())
		cout<<"Underflow"<<endl;
	else
	{
		cout<<"Poped element is "<<arr[front]<<endl;
		front++;
	}
}
void Queue::peek(){
 	if(isEmpty())
	 	cout<<"No element exists"<<endl;
 	else
	 	cout<<"Peek element is "<<arr[front]<<endl; 
}
int Queue::size(){
 	if(!isEmpty()){
	 	return rear-front;		
 	}
 	else
	 	cout<<"No element"<<endl;
 	return -1;
}
int main(){
 	int val,n;
 	Queue q;
 	do{
	
 	    cout<<"1->push 2->pop 3->peek 4->size 5-> exit"<<endl;
 	    cin>>n;
     	switch(n){
	     	case 1:
		 		cout<<"Enter the element to push"<<endl;
			 	cin>>val;
			 	q.enqueue(val);
			 	break;
			
	      	case 2:
    	    	 q.dequeue();
			 	break;
	     	case 3:
				 q.peek();
			 	break;
	     	case 4: 
				 cout<<"size of the queue is "<<q.size()<<endl;
			 	break;
	     	default:
			 	cout<<" Wrong Choise"<<endl;
     	}
  	
	}while(n!=5);

     return 0;
}