#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> dp(n+2,0),pref(n+2,0);
    dp[0]=0;dp[1]=1;
    pref[0]=0;pref[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=pref[i-1]-pref[max(0,i-k-1)]; //to handle if index get to zero
        pref[i]=pref[i-1]+dp[i];
    }
    cout<<dp[n]<<endl;
}
