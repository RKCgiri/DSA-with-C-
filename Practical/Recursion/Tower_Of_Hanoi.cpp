#include<iostream>
using namespace std;

void tower_Of_Hanoi(int n,char source,char destination,char auxulary){
	if(n==1){
		cout<<n<<" th disk is transfered from "<<source<<" to "<<destination<<endl;
		return;
	}
	tower_Of_Hanoi(n-1,source,auxulary,destination);
	cout<<n<<" th disk is transfered from "<<source<<" to "<<destination<<endl;
	tower_Of_Hanoi(n-1,auxulary,destination,source);
}
int main(){
	int n;
	cout<<"Enter the disk number = ";
	cin>>n;
	tower_Of_Hanoi(n,'s','d','a');
}