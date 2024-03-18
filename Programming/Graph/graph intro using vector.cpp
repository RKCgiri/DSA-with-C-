#include<bits/stdc++.h>
using namespace std;

class Graph{
	 vector<vector<int>>adjList;	
	int vertex,edge;
	public:
		Graph(int m,int e){
		 vertex=m;
		 edge=e;
		adjList.resize(m);
		}
		void addEdge(int u,int v){
				adjList[u].push_back(v);
				adjList[v].push_back(u);
		}
			
		void printEdge(){
			for(int i=0;i<vertex;i++){
				cout<<i<<"->";
				for(auto it:adjList[i]){
					cout<<it<<" ,";
				}
			cout<<endl;
			}
		}
		
};
 
int main(){

	int n,m;
	cout<<"Enter the no of nodes"<<endl;
	cin>>n;
	cout<<"Enter no of edges"<<endl;
	cin>>m;
	Graph g(n,m);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g.addEdge(u,v);
	}
	
	g.printEdge();
	return 0;
}


