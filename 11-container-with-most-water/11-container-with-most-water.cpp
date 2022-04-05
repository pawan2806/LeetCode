#include <bits/stdc++.h>

class Solution {
public:
    int maxArea(vector<int>& height) {
//         vector<pair<int, int>> left;
//         vector<pair<int, int>> right(height.size());
//         int n=height.size();
//         if(n==1){
//             return 0;
//         }
//         left.push_back({height[0], 1});
//         right[n-1]={height[n-1], n};
//         int leftmax=height[0];
//         int index=0;
//         for(int i=1;i<n;i++){
//             if(leftmax>height[i]){
//                 leftmax=height[i];
//                 index=i+1;
//             }
            
//             left.push_back({leftmax, index});
//         }
//         leftmax=height[n-1];
//         index=n-1;
  
//         for(int i=n-2;i>=0;i--){
//             if(leftmax>height[i]){
//                 leftmax=height[i];
//                 index=i+1;
//             }
//             right[i]={leftmax, index};
//         }
        
//         int ans=INT_MIN;
//         for(int i=0;i<n;i++){
//             int h=min(right[i].first, left[i].first);
//             int width=abs(right[i].second- left[i].second);
//             ans=max(ans, h*width);
//         }
//         return ans;
//     }
        
         int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        while (height[i] <= h && i < j) i++;
        while (height[j] <= h && i < j) j--;
    }
    return water;
    }
};