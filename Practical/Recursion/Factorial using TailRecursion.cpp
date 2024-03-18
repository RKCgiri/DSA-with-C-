#include<iostream>
using namespace std;

int factorial_tail(int n,int result=1){
	if(n==1) return result;
	else{
		return factorial_tail(n-1,n*result);
	}
}


int main(){
	int n;
	cout<<"Enter the number to calculate factorial = ";
	cin>>n;
	int result=factorial_tail(n);
	cout<<"The factoril of "<<n<<" is "<<result<<endl;
}