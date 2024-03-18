#include<bits/stdc++.h>
using namespace std;

int binaryS(int arr[],int l,int h,int key)
{	int m=l+(h-l)/2;
	if(l>h)
		return -1;
	if(arr[m]==key)
		return m;
	if(arr[m]>key)
		binaryS(arr,l,h=m-1,key);
	else
		binaryS(arr,l=m+1,h,key);
return 0;
};
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
int l=0,h=n-1;
int index=binaryS(a,l,h,key);

//while(l<=h)
//{
//	int m=l+(h-l)/2;
//	if(a[m]==key)
//		{
//		  index= m;
//			break;
//		}
//	else if(a[m]>key)
//			h=m-1;
//		else
//			l=m+1;	
//}		
cout<<endl<<index;

return 0;		
}
