#include<bits/stdc++.h>
using namespace std;

vector<int>bfs(vector<int>adj[],int v){
	queue<int>q;
	vector<int>res;
	int vis[v]={0};
	vis[0]=1;
	q.push(0);
	while(!q.empty()){
		int ele=q.front();
		q.pop();
		res.push_back(ele);
		for(auto it:adj[ele]){
			if(!vis[it]){
				vis[it]=1;
				q.push(it);
			}
			
		}
	}
	return res;
}

void print(vector<int> &ans){
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<",";
	}
	cout<<endl;
}

void addEdge(vector<int>&adj[],int u,int v){
		adj[u].push_back(u);
		adj[v].push_back(v);
}
int main(){
	int m,n;
	cout<<"Enter the vertices of the graph"<<endl;
	cin>>n;
	cout<<"Enter the edges of graph"<<endl;
	cin>>m;
	vector<int>adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		addEdge(adj,u,v);
	
	}
	
	vector<int>ans =bfs(adj,n );
	print(ans);
	cout<<"end";
	return 0;
}




