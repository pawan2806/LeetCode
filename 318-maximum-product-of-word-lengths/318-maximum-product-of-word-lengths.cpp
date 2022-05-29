#include <bits/stdc++.h>
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int ans=0;
        vector<int> state(n,0);
        for(int i=0;i<n;i++){
            int temp=0;
            string gg=words[i];
            for(char c:gg){
                int index=c-'a';
                temp |= 1<<(index);
            }
            state[i]=temp;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               if((state[i] & state[j])==0){
                   if(words[i].length()*words[j].length()> ans){
                       ans=words[i].length()*words[j].length();
                   }
                  
               }
            }
        }
        
        return ans;
    }
};