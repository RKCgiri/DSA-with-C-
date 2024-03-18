#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
	int adj[n+1][m+1]={};// all values initializes with 0
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u][v]=1;
		adj[v][u]=1;
	}
	
	cout<<"The matrix is = "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
return 0;
}