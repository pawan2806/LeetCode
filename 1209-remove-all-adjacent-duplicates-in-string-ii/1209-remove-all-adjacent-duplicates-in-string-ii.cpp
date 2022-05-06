class Solution
{
    public:
        string removeDuplicates(string s, int k)
        {
            stack<pair<char, int>> st;
            string ans = "";
            int n = s.size();

            for (int i = 0; i < n; i++)
            {
                if (st.empty() || st.top().first != s[i])
                {
                    st.push({ s[i],
                        1 });
                }
                else
                {
                    auto prev = st.top();
                    st.pop();
                    st.push({ s[i],
                        prev.second + 1 });
                }

                if (st.top().second == k) st.pop();
            }

            while (st.size() != 0)
            {
                auto prev = st.top();
                st.pop();

                while (prev.second--)
                {
                    ans.push_back(prev.first);
                }
            }

            reverse(ans.begin(), ans.end());

            return ans;
        }
};