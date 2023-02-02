#include <bits/stdc++.h>
using namespace std;
using ll = long long;


vector<ll> finddist(vector<vector<ll>> &adj,ll a,ll n){
  vector<ll> dist(n+1,100);
  vector<ll> visit(n+1,0);
  queue<ll> q;
  visit[a]=1;
  dist[a]=0;
  q.push(a);

  while(q.size()){
    ll curr=q.front();
    q.pop();
    for(auto i:adj[curr]){
      if(visit[i]==1)
      {
        continue;
      }
      visit[i]=1;
      dist[i]=dist[curr]+1;
      q.push(i);
    }
  }
  return dist;
}

int main()
{
  ll n,m;
  cin>>n>>m;
  vector<vector<ll>> adj(n+1);
  for(ll i=0;i<m;i++){
    ll x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  } 
  
  ll s,i1,i2,f;
  cin>>s>>i1>>i2>>f;
  vector<ll> distS=finddist(adj,s,n);
  vector<ll> distF=finddist(adj,f,n);
 
  cout<<min(distS[i1]+distF[i2]+1,distS[i2]+distF[i1]+1);
}
