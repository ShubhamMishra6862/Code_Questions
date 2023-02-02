#include<bits/stdc++.h>
using namespace std;

int maxcomponent(vector<vector<int>> &adj,int n){
    vector<int> visit(n+1,0);
   
    int i;
    int ans=0;
    for(i=1;i<=n;i++){
       
       if(visit[i]==1){
          continue;
       }

       queue<int> q;
       int count=1;
       visit[i]=1;
       q.push(i);

       while(q.size()){
           int curr=q.front();
           q.pop();
           for(auto j:adj[curr]){
               if(visit[j]==1){
                   continue;
               }
               visit[j]=1;
               q.push(j);
               count++;
           }
       }
       ans=max(ans,count);
    }
    return ans;
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
    cout<<maxcomponent(adj,n);
}
