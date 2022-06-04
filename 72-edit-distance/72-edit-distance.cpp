class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length(), m=word2.length();
        if(n==0){
            return m;
        } else if(m==0){
            return n;
        }
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=1;i<=m;i++){
            dp[0][i]=i;
        }
        for(int j=1;j<=n;j++){
            dp[j][0]=j;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                } else {
                    dp[i][j]=1+min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
                }
            }
        }
        return dp[n][m];
    }
};