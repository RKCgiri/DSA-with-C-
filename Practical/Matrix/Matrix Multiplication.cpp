#include<bits/stdc++.h>
using namespace std;


int main(){
	int row1,col1,row2,col2;
	cout<<"Enter row and column of the 1st matrix"<<endl;
	cin>>row1>>col1;
	cout<<"Enter row and column of the 1st matrix"<<endl;
	cin>>row2>>col2;
	if(col1!=row2){
		cout<<"Matrix multiplication is not possible "<<endl;
	}else{
		int arr1[row1][col1],arr2[row2][col2];
		cout<<"Enter the first matrix's elements "<<endl;
		for(int i=0;i<row1;i++){
			for(int j=0;j<col1;j++){
				cin>>arr1[i][j];
			}
    	}
		cout<<"Enter the second matrix elements"<<endl;
		for(int i=0;i<row2;i++){
			for(int j=0;j<col2;j++){
				cin>>arr2[i][j];
			}
		}
		int arr[row1][col2];
		for(int i=0;i<row1;i++){
			for(int j=0;j<col2;j++){
				int sum=0;
				for(int k=0;k<row2;k++){  //row2=col1
					sum+=arr1[i][k]*arr2[k][j];
				}
				arr[i][j]=sum;
			
			}
		}
		cout<<"The result of two matrix multiplication is = "<<endl;
		for(int i=0;i<row1;i++){
			for(int j=0;j<col2;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
	}

}