class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<strs.size();i++)
        {
            int o=0,z=0;
            string s=strs[i];
            for(int j=0;j<s.size();j++)
            {
                if(s[j]=='0')
                    z++;
                else
                    o++;
            }
            for(int j=m;j>=z;j--)
            {
                for(int k=n;k>=o;k--)
                {
                    dp[j][k]=max(dp[j][k],dp[j-z][k-o]+1);
                }
            }
        }
        return dp[m][n];
    }
};