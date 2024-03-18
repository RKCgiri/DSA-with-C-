#include<bits/stdc++.h>
using namespace std;
template <typename t>
class graph{
	public:
		unordered_map<t,list<t>>adj;
		void addEdge(t u,t v,bool direction){
			//create an edge
			adj[u].push_back(v);
			if(direction==0){
				adj[v].push_back(u);
			}
			
			
		}
		void printAdjList(){
			for(auto i:adj){
				cout<<i.first<<"->";
				for(auto j:i.second){
					cout<<j<<" ,";
				}
				cout<<endl;
			}
		}
};






int main(){
	graph<int> g;
	int n,m;
	cout<<"Enter the no of nodes"<<endl;
	cin>>n;
	cout<<"Enter no of edges"<<endl;
	cin>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g.addEdge(u,v,0);
	}
	g.printAdjList();
	
	
	return 0;
}


