int lcs(string s1,string s2,vector<vector<int>> &dp,int i1,int i2){
          if(i1<0 || i2<0){
              return 0;
          }
          if(dp[i1][i2]!=-1){
              return dp[i1][i2];
          }
          if(s1[i1]==s2[i2]){
              return dp[i1][i2]=1+lcs(s1,s2,dp,i1-1,i2-1);
          }
          return dp[i1][i2]=max(lcs(s1,s2,dp,i1-1,i2),lcs(s1,s2,dp,i1,i2-1));
    };
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        for(int i=0;i<=m;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=n;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
