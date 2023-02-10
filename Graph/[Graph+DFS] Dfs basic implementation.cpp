#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj,vector<int>& visit,int s){
	cout<<s<<" ";
	visit[s]=1;
	for(auto i:adj[s]){
		if(visit[i]==-1)
		{dfs(adj,visit,i);}
	}
}
int main(){
	int n,m;
	vector<int> visited(n+1,-1);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
    	int x,y;
    	cin>>x>>y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }
    dfs(adj,visited,1);
}
