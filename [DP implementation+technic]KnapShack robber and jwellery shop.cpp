//robber has bag of k size you need to maximise his looted price but weight of jwellery should not exceed more than k
#include<bits/stdc++.h>
using namespace std;

using ll=long long;

ll dp[1011][1011];
ll dfn(ll k,ll i,vector<ll> &jw,vector<ll> &jp){
    if(k<0) return -1e18;
    if(i>=jw.size()) return 0;
    if(dp[i][k]!=-1){
        return dp[i][k];
    }
    return dp[i][k]=max(dfn(k-jw[i],i+1,jw,jp)+jp[i],dfn(k,i+1,jw,jp));
}

int main(){
    memset(dp,-1,sizeof(dp));
    vector<ll> jw{5,2,1,8,5};
    vector<ll> jp{4,3,2,10,6};
    cout<<dfn(10,0,jw,jp)<<endl;
}
