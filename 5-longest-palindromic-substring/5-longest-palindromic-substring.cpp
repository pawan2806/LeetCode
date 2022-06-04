class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==1){
            return s;
        } else if(n==2){
            if(s[0]==s[1]){
                return s;
            } else {
                return s.substr(0,1);
            }
        }
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        int ans=1;
        string gg= s.substr(0,1);
        for(int gap=1;gap<n;gap++){
            if(gap==1){
                for(int i=0;i<n-1;i++){
                    if(s[i]==s[i+1]){
                        dp[i][i+1]=2;
                    } else {
                         dp[i][i+1]=0;
                    }
                    if(dp[i][i+1]>ans){
                        ans=max(ans, dp[i][i+1]);
                        gg=s.substr(i, gap+1);
                    }
                   
                }
            } else {
                 for(int i=0;i+gap<n;i++){
                     if(s[i]==s[i+gap] && dp[i+1][i+gap-1]>0){
                         dp[i][i+gap]=2+dp[i+1][i+gap-1];
                         
                     } else {
                         dp[i][i+gap]=0;
                     }
                     if(dp[i][i+gap]>ans){
                        ans=max(ans, dp[i][i+gap]);
                        gg=s.substr(i, gap+1);
                    }
                     
                 }
            }
            
            
        }
        return gg;
        
    }
};