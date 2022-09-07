class Solution
{
    public:
        string minWindow(string s, string t)
        {
            vector<int> freq(128, 0);
            for (int i = 0; i < t.size(); i++)
            {
                freq[t[i]]++;
            }
            int start = 0, end = 0, counter = t.size(), minlen = INT_MAX, minstart = 0;
            while (end < s.size())
            {
                char temp = s[end];
                if (freq[temp] > 0) counter--;
                freq[temp]--;
                end++;
                while (counter == 0)
                {
                    if (minlen > end - start)
                    {
                        minlen = end - start;
                        minstart = start;
                    }
                    char chars = s[start];
                    freq[chars]++;
                    if (freq[chars] > 0) counter++;
                    start++;
                }
            }
            return minlen == INT_MAX ? "" : s.substr(minstart, minlen);
        }
};