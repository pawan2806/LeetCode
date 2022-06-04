class Solution
{
    public:
        bool isMatch(string &s, string &p)
        {
            if (p.size() == 0) return s.size() == 0;

            int x = s.size(), y = p.size();
            vector<vector < int>> t(x + 1, vector<int> (y + 1, 0));

            t[0][0] = 1;

            for (int i = 1; i <= p.size(); i++)
            {
                if (p[i - 1] == '*') t[0][i] = 1;
                else break;
            }

            for (int i = 1; i <= s.size(); i++)
            {
                for (int j = 1; j <= p.size(); j++)
                {
                    if (p[j - 1] == '*') t[i][j] = t[i - 1][j] || t[i][j - 1];
                    else if (p[j - 1] == '?' || p[j - 1] == s[i - 1])
                    {
                        t[i][j] = t[i - 1][j - 1];
                    }
                }
            }
            return t[x][y];
        }
};