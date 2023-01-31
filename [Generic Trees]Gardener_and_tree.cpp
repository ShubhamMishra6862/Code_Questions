#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
  ll t;
  cin>>t;
  while(t--){
    ll n,k;
    cin>>n>>k;
    if(n==1){
      if(k>0){
        cout<<1<<endl;
      }
      else{cout<<0<<endl;}
    }
    vector<ll> deg(n+1,0);
    vector<vector<ll>> edges(n+1);
    for(ll i=0;i<n-1;i++){
      ll x,y;
      cin>>x>>y;
      edges[x].push_back(y);
      edges[y].push_back(x);
      deg[x]++;
      deg[y]++;
    }
    queue<ll> q1,q2;
    for(ll i=1;i<=n;i++){
      if(deg[i]==1) q1.push(i);
    }
    ll count=n;
    while(q1.size() && k--){
      while(q1.size()){
        auto curr=q1.front();
        count--;
        q1.pop();
        for(auto l:edges[curr]){
          deg[l]--;
          if(deg[l]==1){
            q2.push(l);
          }
        }
      }
      swap(q1,q2);
    }
    cout<<count<<endl;
  }
}
