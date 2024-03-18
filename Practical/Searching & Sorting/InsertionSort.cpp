#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int n){
	int i,j;
	for(i=1;i<n;i++){
		int j=i-1;
		int key=arr[i];
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}




int main(){
	cout<<"Enter the size of the array"<<endl;
	int n;
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of the array"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Array elements are "<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	insertionSort(arr,n);
	cout<<"After sorting the array elemnts are "<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
return 0;
}