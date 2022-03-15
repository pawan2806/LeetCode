class Solution
{
    public:
        string minRemoveToMakeValid(string s)
        {
            int n = s.length();
            string ans = "";
            stack<pair<char, int>> stk;
            for (int i = 0; i < n; i++)
            {
                if (s[i] != '(' && s[i] != ')')
                {
                    continue;
                }
                else if (s[i] == '(')
                {
                    pair<char, int> pair1;
                    pair1.first = '(';
                    pair1.second = i;
                    stk.push(pair1);
                }
                else
                {
                    pair<char, int> pair1;

                    if (!stk.empty())
                    {
                        pair1 = stk.top();
                        if (pair1.first == ')')
                        {
                            pair1.second = i;
                            stk.push(pair1);
                        }
                        else
                        {
                            stk.pop();
                        }
                    }
                    else
                    {
                        pair1.first = ')';
                        pair1.second = i;
                        stk.push(pair1);
                    }
                }
            }
            unordered_map<int,int> mp;
            int i=n-1;
            while(!stk.empty()){
                pair<char, int> pair1 =stk.top();
                mp[pair1.second]++;
                stk.pop();
                
            }
            for(int i=0;i<n;i++){
                if(mp[i]){
                    continue;
                } else {
                    ans+=s[i];
                }
            }
            return ans;
            
        }
};