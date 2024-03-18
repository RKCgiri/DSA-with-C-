#include<bits/stdc++.h>
using namespace std;
void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
void bubbleSort(int arr[],int n){
	int i,j;
	cout<<endl;
	for(i=0;i<n-1;i++){
		cout<<"Step "<<i+1<<endl;
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(arr,j,j+1);
			}
			for(int k=0;k<n;k++){
			cout<<arr[k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}

void selectionSort(int arr[],int n){
	cout<<endl;
	for(int i=0;i<n-1;i++){
		int min=i;
		cout<<"Step"<<i+1<<endl;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		if(min!=i){
				swap(arr,i,min);
			}
			for(int k=0;k<n;k++){
			cout<<arr[k]<<" ";
			}
			cout<<endl;
	}
}
void insertionSort(int arr[],int n){
	for(int i=1;i<n;i++){
		int key=arr[i],j=i-1;
		cout<<endl<<"step "<<i<<endl;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
			for(int k=0;k<n;k++){
			cout<<arr[k]<<" ";
			}
			cout<<endl;
	}
}
void marge(int arr[],int low,int mid,int high){
	int B[100],i=low,j=mid+1,k=low;
	while(i<=mid && j<=high){
		if(arr[i]<arr[j]) B[k++]=arr[i++];
		else B[k++]=arr[j++];
	}
	while(i<=mid) B[k++]=arr[i++];
	while(j<=high) B[k++]=arr[j++];
	for(i=low;i<=high;i++) arr[i]=B[i];
}



void margeSort(int arr[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		margeSort(arr,low,mid);
		margeSort(arr,mid+1,high);
		marge(arr,low,mid,high);
	}
}

int partition(int arr[],int low,int high){
	int pivot=arr[high];
	int i=low-1,j=low;
	while(j<high){
		if(arr[j]<=pivot){
			i++;
			swap(arr,i,j);
			
		}
		j++;
	}
	swap(arr,i+1,high);
	
	return i+1;
}
void quickSort(int arr[],int low,int high){
	if(low<high){
		for(int k=low;k<high;k++){
			cout<<arr[k]<<" ";
			}
			cout<<endl;
		int j=partition(arr,low,high);
		quickSort(arr,low,j-1);
		quickSort(arr,j+1,high);
		
	}
}

void heaptify(int arr[],int i,int n){
	int j=2*i;
	int key=arr[i];
	while(j<=n){
		if(j<n && arr[j]<arr[j+1]){
			j=j+1;
		}
		if(arr[j]<=key){
			break;
		}
		arr[j/2]=arr[j];
		j=j*2;
	}
	arr[j/2]=key;
}
void makeHeap(int arr[],int n){
	for(int i=n/2;i>=1;i--){
		heaptify(arr,i,n);
	}
}
void heapSort(int arr[],int n){
	makeHeap(arr,n);
	for(int i=n;i>=2;i--){
		int t=arr[1];
		arr[1]=arr[i];
		arr[i]=t;
		heaptify(arr,1,i-1);
	}
	return;
}
int main(){
	int n;
	cout<<"Enter the size of the array = ";
	cin>>n;
	cout<<endl<<"Enter the array elemets"<<endl;
	//int *arr=new int(n);
	int arr[n];
	for(int i=1;i<n+1;i++){
		cin>>arr[i];
	}
	cout<<endl<<"Array elemets are "<<endl;
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" , ";
	}
	heapSort(arr,n);
	cout<<endl<<"After sorting Array elemets are "<<endl;
	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" , ";
	}
}