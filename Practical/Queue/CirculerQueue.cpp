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
 	void push(int val);
 	void pop();
 	void getFront();
 	int size();
 	void display();
	
};
bool Queue::isEmpty(){
 	return (front==-1);
}
bool Queue::isFull(){
 	if((front==0 && rear==MAX_SIZE-1)||(front==rear+1))
	 	return true;
 	else 
	 	return false;
}
void Queue::push(int x){
 	if(isFull())
	 	cout<<"The queue is full"<<endl;
 	else{
	 	if(rear==-1){
		 	front=0;
		 	rear=0;
			}
	 	else{
		 	if(rear==MAX_SIZE-1)
			 	rear=0;
		 	else
			 	rear++;
				
	 	}
	 	arr[rear]=x;
 	}
}

void Queue::pop(){
 	if(isEmpty())
		cout<<"Underflow"<<endl;
 	else{
	 	cout<<"Poped element is "<<arr[front]<<endl;	
	 	if(front==rear){
		 	front=-1;
		 	rear=-1;		
 		}
 		else{
			if(front==MAX_SIZE-1)
				front=0;
			else		
				front++;
		}
	}
}
void Queue::getFront(){
	if(isEmpty())
	 	cout<<"No element exists"<<endl;
 	else
	 	cout<<"Front  element is "<<arr[front]<<endl; 
}
int Queue::size(){
 	int cnt=0;
 	if(isEmpty())
	 	cout<<"No element"<<endl;
 	else{
		
		 	int i=front;
		 	cout<<"front ="<<front<<"rear="<<rear<<endl;
		 	if(i<=rear){
		 		while(i<=rear){
					cnt++;
					i++;
					}
				}
			else{
				while(i<=MAX_SIZE-1){
					 	cnt++;
					 	i++;
			 	}
			 	i=0;
			 	for(i=0;i<=rear;i++)
					cnt++;
			}
		}
	return cnt;
}
void Queue::display(){
	if(isEmpty())
		cout<<"the queue is empty"<<endl;
	else
		{	cout<<"The element are "<<endl;
			int i=front;
			cout<<"front"<<front<<endl;
			if(i<=rear){
				for(i=front;i<=rear;i++)
					cout<<i<<"->"<<arr[i]<<" ";
			}
			else{
				while(i<=MAX_SIZE-1){
					 	cout<<arr[i]<<" ";
					 	i++;
			 	}
			 	for(i=0;i<=rear;i++)
				  	cout<<arr[i]<<" ";
				
			}
		}
	cout<<endl;
}
int main(){
 	int val,n;
 	Queue q;

	do{
	 	cout<<"1->push 2->pop 3->front 4->size 5-> display 6-> exit"<<endl;
	 	cin>>n;
	 	switch(n){
		 	case 1:
			 	cout<<"Enter the element to push"<<endl;
			 	cin>>val;
			 	q.push(val);
			 	break;
	 		case 2: 
			 	q.pop();
			 	break;
		 	case 3:
			     q.getFront();
			 	break;
	 		case 4:
				 cout<<"size of the queue is "<<q.size()<<endl;
			  	break;
	 		case 5:
				 q.display();
			 	break;
	 		default:
			  	cout<<" Wrong Choise"<<endl;
	 	}
	
     }while(n!=6);
   
     return 0;
}