#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j){
	int temp=arr[j];
	arr[j]=arr[i];
	arr[i]=temp;
}

void bubbleSort(int arr[],int n){
	int i=0,j=0;
	for(i=0;i<n-1;i++){
		bool swaped=false;
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr,j,j+1);
				swaped=true;
			}
		}
		if(!swaped) break;
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
	bubbleSort(arr,n);
	cout<<"After sorting the array elemnts are "<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
return 0;
}