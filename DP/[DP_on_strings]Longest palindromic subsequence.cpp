//leetcode problem:https://leetcode.com/problems/longest-palindromic-subsequence/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int i=0,j=0,n=s.size();
        string si=s;
        reverse(s.begin(),s.end());
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=n;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==si[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};
