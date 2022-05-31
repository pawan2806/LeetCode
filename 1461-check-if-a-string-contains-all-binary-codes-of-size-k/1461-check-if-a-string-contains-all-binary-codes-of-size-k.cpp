#include <bits/stdc++.h>

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> gg;
        if(s.length()<k){
            return false;
        }
        for(int i=0;i<=s.length()-k;i++){
            
                gg.insert(s.substr(i,k));
              
                
            
        }
       
        return gg.size()==pow(2,k);
    }
};