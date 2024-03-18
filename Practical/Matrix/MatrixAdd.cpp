#include<bits/stdc++.h>
using namespace std;


int main(){
	int n,m;
	cout<<"Enter row and column of the both matrix"<<endl;
	cin>>n>>m;
	int arr1[n][m],arr2[n][m];
	cout<<"Enter the first matrix's elements "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr1[i][j];
		}
	}
	cout<<"Enter the second matrix elements"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr2[i][j];
		}
	}
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			arr[i][j]=arr1[i][j]+arr2[i][j];
		}
	}
	cout<<"The result of two matrix addition is = "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}