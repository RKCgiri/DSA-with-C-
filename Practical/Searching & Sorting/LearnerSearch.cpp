#include<bits/stdc++.h>
using namespace std;
int lSearch(int arr[],int n,int key)
{   if(n<0)
	return -1;
    if(arr[n]==key)
	 return n;
	lSearch(arr,n-1,key);
	return 0;
}
int main()
{
	int n,i,key;
	int *a=new int[n];
	cout<<"Enter the value of array size"<<endl;
	cin>>n;
	cout<<"Enter the array elemnt "<<endl;
	for(i=0;i<n;i++)
		cin>>a[i];
		cout<<"Enter the key ";
		cin>>key;
	cout<<"The array is "<<endl;
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
		

cout<<endl<<lSearch(a,n-1,key);
		
}
