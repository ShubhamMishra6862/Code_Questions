#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj){
    queue<int>q;
    q.push(1);
    vector<int> visited(adj.size(),0);
    visited[1]=1;
    while(q.size()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(auto i:adj[curr]){
            if(visited[i]==1){
                continue;
            }
            visited[i]=1;
            q.push(i);
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(adj);
}
