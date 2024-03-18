 #include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j){
	int temp=arr[j];
	arr[j]=arr[i];
	arr[i]=temp;
}


void selectionSort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		int minInd=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[minInd]){
				minInd=j;
			}
			swap(arr,i,minInd);
		}
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
	selectionSort(arr,n);
	cout<<"After sorting the array elemnts are "<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
return 0;
}