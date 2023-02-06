//max good value path
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll par[100111];

ll findPar(ll x){
    if(par[x]==x) return x;
    return par[x]=findPar(par[x]);
}

bool merge(ll a, ll b){
    a = findPar(a);
    b = findPar(b);
    if(a==b) return true;
    par[a]=b;
    return false;
}

int main(){
    ll n, m, ref1,ref2; cin>>n>>m>>ref1>>ref2;
    for(ll i=1;i<=n;i++) par[i]=i;
    vector<pair<ll,pair<ll,ll>>> arr;

    ll ans = 0;
    for(ll i=0;i<m;i++){
        ll x, y, z; cin>>x>>y>>z;
        arr.push_back({z, {x, y}});
    }
    sort(arr.begin(), arr.end());
    for(auto itr : arr){
        if(!merge(itr.second.first, itr.second.second)){
         if(par[ref1]==par[ref2]){
            ans=itr.first;
         }}
    }
    cout<<"parent: "<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<" : "<<par[i]<<endl;
    }
    cout<<ans<<endl;
}
