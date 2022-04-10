#include <bits/stdc++.h>
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        int n=ops.size();
        for(int i=0;i<n;i++){
            if(ops[i]!="D" && ops[i]!="C" && ops[i]!="+"){
                int x=stoi(ops[i]);
                s.push(x);
            } else if(ops[i]=="D"){
                int x=s.top();
                x*=2;
                s.push(x);
            } else if(ops[i]=="C"){
                s.pop();
            } else {
                int a=s.top();
                s.pop();
                int b=s.top();
                int x=a+b;
                s.push(a);
                s.push(x);
            }
        }
        int ans=0;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};