class Solution
{
    public:
        string longestPalindrome(string s)
        {
            int n = s.size();
            vector<vector < int>> dp(n + 1, vector<int> (n + 1));
            int start = 0, end = 0;
            int ans = 1;
            for (int i = 0; i < n; i++)
                dp[i][i] = 1;
            for (int gap = 1; gap < n; gap++)
            {
                for (int i = 0; i < n - gap; i++)
                {
                    if (gap == 1)
                    {
                        if (s[i] == s[i + 1])
                        {
                            dp[i][i + 1] = 1;
                            dp[i + 1][i] = 1;
                            start = i, end = i + 1, ans = 2;
                        }
                    }
                    int j = gap + i;
                    if (s[i] == s[j] && dp[i + 1][j - 1])
                    {
                        dp[i][j] = 1;
                        if (j - i + 1 > ans)
                            ans = j - i + 1, start = i, end = j;
                    }
                    else
                        dp[i][j] = 0;
                }
            }
            return s.substr(start, end - start + 1);
        }
};