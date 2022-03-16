class Solution
{
    public:
        bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
        {
            int n = pushed.size();
            map<int, int> m;
            for (int i = 0; i < n; i++)
            {
                m[pushed[i]] = i;
            }
            vector<int> v(1001, 0);
            int first = popped[0];
            stack<int> s;
            for (int i = 0; i <= m[first]; i++)
            {
                s.push(pushed[i]);
                v[pushed[i]]++;
            }
            s.pop();
            first = m[first];
            v[popped[0]]--;
            for (int i = 1; i < n; i++)
            {
                int element = popped[i];
                if (v[element]) {
                    if(s.empty()){
                        return false;
                    } else if(s.top()!=element){
                        return false;
                    } else {
                        s.pop();
                        v[element]--;
                    }
                }
                else
                {
                    for (int j = first + 1; j <= m[element]; j++)
                    {
                        s.push(pushed[j]);
                        v[pushed[j]]++;
                    }
                    first=m[element];
                    s.pop();
                    v[element]--;
                    
                }
            }
            
            return true;
        }
};