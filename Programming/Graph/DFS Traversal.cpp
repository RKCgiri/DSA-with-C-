#include<bits/stdc++.h>
using namespace std;
class BFS{
	public: 
		void addEdge(vector<int>adj[],int u,int v){
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
		void printEdge(vector<int>adj[],int n,int m){
			for(int i=0;i<n;i++){
				cout<<i<<"->";
				for(int j=0;j<adj[i].size();j++){
					cout<<adj[i][j]<<" ,";
				}
			cout<<endl;
			}
		}
		vector<int>bfsTraversal(vector<int>adj[],int n,int node){
			vector<int>ans;
		    stack<int>st;
			int visited[n]={0};
			st.push(node);
			visited[node]=1;
			while(!st.empty()){
				int e=st.top();
				st.pop();
				ans.push_back(e);
				for(auto it:adj[e]){
					if(visited[it]!=1){
					st.push(it);
					visited[it]=1;
					}
				}
			}
		return ans;
		}
};

int main(){
	int n,m;
	cout<<"Enter numer of vertex of the graph"<<endl;
	cin>>n;
	cout<<"Enter numer of edges of the graph"<<endl;
	cin>>m;
	BFS graph;
	vector<int>adj[n];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		graph.addEdge(adj,u,v);
	}
	graph.printEdge(adj,n,m);
	vector<int>ans=graph.bfsTraversal(adj,n,2);
	for(int i=0;i<n;i++){
		cout<<ans[i]<<",";
	}	
	cout<<endl;
	return 0;
}