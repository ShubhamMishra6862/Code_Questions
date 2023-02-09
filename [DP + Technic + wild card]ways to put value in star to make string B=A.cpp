#include <iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[1011][1011];
int dfn(string s,string t,int i1,int i2){
    if(i1>=s.size() && i2>=t.size())return 1;
    if(dp[i1][i2]!=-1) return dp[i1][i2];

    if(i2>=t.size()) return 0;
    if(i1>=s.size()){
        if(t[i2]>='a' && t[i2]<='z')return 0;
        return dp[i1][i2]=dfn(s,t,i1,i2+1);
    }
    int ans=0;
    if(t[i2]>='a' && t[i2]<='z'){
        if(s[i1]==t[i2])ans=dfn(s,t,i1+1,i2+1);
        else ans=0;
    }
    else{
        ans=dfn(s,t,i1+1,i2)+dfn(s,t,i1,i2+1);
    }
    return dp[i1][i2]=ans;
}
int main() {
    memset(dp,-1,sizeof(dp));
    string s="abcde",t="a**d*";
    cout<<dfn(s,t,0,0);
}
