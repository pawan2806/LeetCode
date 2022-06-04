class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(), m=text2.length();
        vector<vector<int>> dp(n, vector<int>(m,0));
        dp[0][0]=(text1[0]==text2[0])?1:0;
        for(int i=1;i<m;i++){
            if(text1[0]==text2[i]){
                dp[0][i]=1;
            } else {
                dp[0][i] =dp[0][i-1] | dp[0][i];
            }
        }
        for(int i=1;i<n;i++){
            if(text1[i]==text2[0]){
                dp[i][0]=1;
            } else {
                dp[i][0] =dp[i-1][0] | dp[i-1][0];
            }
        }
         for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(text1[i]!=text2[j]){
                    dp[i][j]=max({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
                } else {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
            }
        }
        return dp[n-1][m-1];
        
    }
};