#include <bits/stdc++.h>
class Solution {
public:
    int reverse(int x) {
        long long int ans=0;
        bool neg=(x<0);
        if(x<=INT_MIN){
            return 0;
        }
        if(neg){
            x=-x;
        }
        string gg=to_string(x);
        std::reverse(gg.begin(), gg.end());
        int n=gg.length();
        int i=0;
        while(i<n){
            ans=ans*10;
            ans+=gg[i]-'0';
            i++;
            if(ans>=INT_MAX){
                return 0;
            }
        }
        
        return (neg==1)? -1*(int)ans : (int)ans;
    }
};