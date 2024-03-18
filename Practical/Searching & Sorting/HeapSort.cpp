#include<bits/stdc++.h>
using namespace std;

void heaptify(int arr[],int i,int n){
	int j=i*2;
	int key=arr[i];
	while(j<=n){
		if(j<n && arr[j+1]>arr[j]){
			j=j+1;
		}
		if(arr[j]<=key)
			break;
		arr[j/2]=arr[j];
		j=j*2;
	}
	arr[j/2]=key;
}
void makeHeap(int arr[],int n){
	for(int i=floor(n/2);i>=1;i--){
		heaptify(arr,i,n);
	}
}
void heapSort(int arr[],int n){
	makeHeap(arr,n);
	cout<<endl<<"After makeheap"<<endl;
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	for(int i=n;i>=2;i--){
		int temp=arr[i];
		arr[i]=arr[1];
		arr[1]=temp;
		heaptify(arr,1,i-1);
		cout<<endl<<"After "<<i<<"th loop"<<endl;
		for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
		}

	}
	
}

int main(){
	cout<<"Enter the size of the array"<<endl;
	int n;
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of the array"<<endl;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	cout<<"Array elements are "<<endl;
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
	heapSort(arr,n);
	cout<<endl<<"After sorting the array elemnts are "<<endl;
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
return 0;
}
