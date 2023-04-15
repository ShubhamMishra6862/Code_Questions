// https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/
// Tells extensively about 2DP use. RECOMMENDED TO TRY BY YOURSELF
class Solution {
public:
    int DP(int i,int k,vector<vector<int>> &piles,vector<vector<int>> &dp){
        
        if(k==0 || i>=dp.size()){
            return 0;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int res=DP(i+1,k,piles,dp);
        int curr=0;
        for(int j=0;j<=k-1 && j<piles[i].size();j++){
            curr+=piles[i][j];
            res=max(res,curr+DP(i+1,k-j-1,piles,dp));
        }
        return dp[i][k]=res;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size(),m=piles[0].size();
        vector<vector<int>> dp(n,vector<int> (k+1,-1));
        return DP(0,k,piles,dp);
    }
};
