class Solution
{
    public:
        bool backspaceCompare(string s, string t)
        {
            string ans;
            int n = s.length();
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '#')
                {
                    if (ans.length() > 0)
                    {
                        ans.pop_back();
                    }
                }
                else
                {
                    ans += s[i];
                }
            }
            string ans2;
            n = t.length();
            for (int i = 0; i < n; i++)
            {
                if (t[i] == '#')
                {
                    if (ans2.length() > 0)
                    {
                        ans2.pop_back();
                    }
                }
                else
                {
                    ans2 += t[i];
                }
            }
            return ans == ans2;
        }
};