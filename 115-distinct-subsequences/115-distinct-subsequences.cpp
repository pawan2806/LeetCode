class Solution {
public:
    int helper(string s, string t, int i, int j, vector<vector<int>> dp ){
         if(j<0){
            return 1;
        }
        if(i<0){
            return 0; 
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]==t[j]){
            return dp[i][j]= helper(s,t,i-1,j-1,dp)+helper(s,t,i-1,j,dp);
        } else {
             return dp[i][j]= helper(s,t,i-1,j,dp);
        }
    }
    int numDistinct(string s, string t) {
        static int MOD = (int)1e9 + 7;    
        long long int n=s.length(), m=t.length();
        vector<vector<long long int >> dp(n+1, vector<long long int >(m+1,0));
        for(long long int  j=0;j<=n;j++){
            dp[j][0]=1;
        }
        for(long long int  i=1;i<=n;i++){
            for(long long int  j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%MOD;
                } else {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};