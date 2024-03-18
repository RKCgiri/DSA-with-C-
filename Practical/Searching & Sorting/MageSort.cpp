#include<bits/stdc++.h>
using namespace std;
void marge(int arr[],int low,int mid,int high){
	int a[20],i=low,k=low,j=mid+1;
	while(i<=mid && j<=high){
		if(arr[i]<arr[j]){
			a[k++]=arr[i++];
		}
		else a[k++]=arr[j++];
	}
	
	while(i<=mid) a[k++]=arr[i++];
	while(j<=high) a[k++]=arr[j++];
	
	for(i=low;i<=high;i++){
		arr[i]=a[i];
	}
}

void margeSort(int arr[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		margeSort(arr,low,mid);
		margeSort(arr,mid+1,high);
		marge(arr,low,mid,high);
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
	
	margeSort(arr,0,n-1);
	
	cout<<"After sorting the array elemnts are "<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
return 0;
}