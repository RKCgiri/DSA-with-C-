#include<bits/stdc++.h>
#define MAX_SIZE 10
using namespace std;
class Stack{
	public:
		int top;
		int arr[MAX_SIZE];
		Stack(){
			top=-1;
		}
	bool isEmpty();
	bool isFull();
	void push(int val);
	void pop();
	void peek();
	int size();
	
};
bool Stack::isEmpty(){
	return (top==-1);
}
bool Stack::isFull(){
	return top==MAX_SIZE-1;
}
void Stack::push(int x){
	if(isFull())
		cout<<"The stack is full"<<endl;
	else
	{
		arr[++top]=x;
	}
}
void Stack::pop(){
	if(isEmpty())
		cout<<"Underflow"<<endl;
	else
	{
		cout<<"Poped element is "<<arr[top--]<<endl;
	}
}
void Stack::peek(){
	if(isEmpty())
		cout<<"No element exists"<<endl;
	else
		cout<<"Peek element is "<<arr[top]<<endl; 
}
int Stack::size(){
	return top+1;
}
int main()
{	int val,n;
	Stack s;

	do{
		cout<<endl<<"1->push 2->pop 3->peek 4->size 5-> exit"<<endl;
		cin>>n;
		switch(n){
			case 1:
				 	cout<<"Enter the element to push"<<endl;
				   	cin>>val;
				   	s.push(val);
				 	break;
			case 2: 
				 	s.pop();
				 	break;
			case 3: 
				 	s.peek();
			 		break;
			case 4: 
			     	cout<<"size of the stack is "<<s.size()<<endl;
				 	break;
			case 5:
					exit(0);
			default:
			        cout<<" Wrong Choise"<<endl;
		}
	
	}while(1);// while(n!=5) is also allowed.The we need not write case 5.

return 0;
}