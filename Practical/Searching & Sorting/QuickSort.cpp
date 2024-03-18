#include<bits/stdc++.h>
using namespace std;
void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
int partion(int arr[],int low,int high){
	int i=low-1,j=low,pivot=arr[high];
	for(j=low;j<high;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr,i,j);
		}
	}
	swap(arr,i+1,j);
return i+1;
}

void quickSort(int arr[],int low,int high){
	if(low<high){
		int j=partion(arr,low,high);
		quickSort(arr,low,j-1);
		quickSort(arr,j+1,high);
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
	quickSort(arr,0,n-1);
	cout<<"After sorting the array elemnts are "<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
return 0;
}