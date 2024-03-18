#include<iostream>
using namespace std;
#define max 10
class Array{
	int size,arr[max];
	public:
		Array(){
			size=0;
		}
		void initial(int );
		void insert(int,int);
		void update(int,int);
		void del(int);
		int getSize();
		void display();
};
void Array::initial(int size){
	if(size>max || size<=0){
		cout<<"Initializtion size is not valid"<<endl;
		return;
	}
	cout<<"Enter elements of the array "<<endl;
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}	
}
void Array::insert(int data,int index){
	if(index>=max){
		cout<<"Full array "<<endl;
		return;
	}
	for(int i=size-1;i>=index;i--){
		arr[i+1]=arr[i];
	}
	arr[index]=data;
	size++;
}
void Array::update(int data ,int index){
	if(index>=max || index<0){
		cout<<"Wrong index "<<endl;
		return;
	}
	arr[index]=data; 
} 
void Array::del(int data){
	int index;
	for(int i=0;i<size;i++){
		if(arr[i]==data){
			index=i;
		}
		for(int i=index;i<=size-1;i++){
			arr[i]=arr[i+1];
		}
		size--;
	}
}
int Array::getSize(){
	return size+1;
}
void Array::display(){
	if(size<0){
		cout<<"Not elemet present "<<endl;
		return;
	}
	for(int i=0;i<=size;i++){
		cout<<arr[i]<<",";
	}
	cout<<endl;
}
int main(){
	Array a;
	int n,index,size,val;
	do{
		cout<<"1->initialize, 2->insert ,3->delete,4->update ,5->dispaly,6->grtsize,7->exit"<<endl;
		cin>>n;
		switch(n){
			case 1:
				cout<<"Enter the size"<<endl;
				cin>>size;
				a.initial(size);
				break;
			case 2:
				cout<<"ENter the data with index "<<endl;
				cin>>val>>index;
				a.insert(val,index);
				break;
			case 3:
				cout<<"Enter the val to delete ";
				cin>>val;
				a.del(val);
				cout<<endl;
				break;
			case 4:
				cout<<"Enter the val with index ";
				cin>>val>>index;
				a.update(val,index);
				cout<<endl;
				break;
			case 5:
				a.display();
				break;
			case 6:
				cout<<a.getSize();
				break;
			case 7:
				exit(0);
			default:
				cout<<"Wrong Choise "<<endl;	
		}
	}while(1);
	return 0;
}