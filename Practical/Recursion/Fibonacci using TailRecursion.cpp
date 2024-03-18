#include<iostream>
using namespace std;
int fibonacci_tail(int n,int prev=0,int next=1){
	if(n==0) return prev;
	if(n==1) return next;
	return fibonacci_tail(n-1,next,prev+next);
}
void fibonacci(int n){
	int a=0,b=1,c;
	cout<<a<<","<<b<<",";
	for(int i=2;i<n;i++){
		a=b;
		b=c;
		c=a+b;
		cout<<c<<",";
	}
	cout<<endl;
}
int main(){
	int n;
	cout<<"Enter the position of the fionacci number = ";
	cin>>n;
	fibonacci(n);
	int result=fibonacci_tail(n);
	cout<<"The result is "<<result<<endl;
}