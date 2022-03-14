class Solution
{
    public:
        string simplifyPath(string path)
        {

            string temp = "";
            path = path + "/";
            stack<string> s;
            int n = path.length();
            for (int i = 0; i < n; i++)
            {
                if (path[i] == '/')
                {
                    if (temp == "..")
                    {
                        if (s.size())
                        {
                            s.pop();
                        }
                    }
                    else if (temp != "" && temp != ".")
                    {
                        s.push(temp);
                    }
                    temp = "";
                }
                else
                {
                    temp += path[i];
                }
            }
            if (temp != "" && temp != ".")
            {
                s.push(temp);
            }
            temp = "";
            temp += "/";
            vector<string> ans;
            while (!s.empty())
            {
                ans.push_back(s.top());
                s.pop();
            }
            reverse(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
            {
                temp += ans[i];
                if (i != ans.size() - 1)
                {
                    temp += "/";
                }
            }

            return temp;
        }
};