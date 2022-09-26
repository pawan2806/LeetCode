#include <bits/stdc++.h>
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
         map<string, int> m;
        int ans = 0;
        for(int i=0;i<startWords.size();i++){
            string x = startWords[i];
            sort(x.begin(), x.end());
            m[x] = 1;
        }
        for(int i=0;i<targetWords.size();i++){
            string x = targetWords[i];
            sort(x.begin(), x.end());
            for(int j=0;j<x.size();j++){
                string y;
                if(j==x.size()-1) y=x.substr(0,j);
                else y = x.substr(0, j)+x.substr(j+1, x.size()-j-1);
                if(m[y]==1){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
 
};
