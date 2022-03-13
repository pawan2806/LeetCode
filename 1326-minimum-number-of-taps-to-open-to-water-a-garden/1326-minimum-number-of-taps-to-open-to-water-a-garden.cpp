#include <bits/stdc++.h>

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        int min=0, max=0, open=0;
        while(max<n){
            for(int i=0;i<ranges.size();i++){
                if(i-ranges[i]<=min && i+ranges[i]>max){
                    max=i+ranges[i];
                }
            }
            if(min==max){
                return -1;
            }
            open++;
            min=max;
        }
        return open;
        
    }
};