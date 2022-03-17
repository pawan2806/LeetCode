class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                stk.push(-1);
            } else {
                if(stk.top()==-1){
                    stk.pop();
                    stk.push(1);
                } else {
                    int val=0;
                    while(stk.size() && stk.top()!=-1){
                        val+=stk.top();
                        stk.pop();
                    }
                    
                    stk.pop();
                    stk.push(2*val);
                }
            }
        }
        
        int val=0;
        while(stk.size()) {
            val+=stk.top();
            stk.pop();
        }
        
        return val;
    }
};