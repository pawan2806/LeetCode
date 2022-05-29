#include <bits/stdc++.h>

class Solution
{
    public:
        int maxArea(vector<int> &height)
        {

           	int water = 0;
           	int i = 0, j = height.size() - 1;
           	while(i<j){
                if(height[i]<=height[j]){
                    water=max(water, (j-i)*height[i]);
                    i++;
                } else {
                    water=max(water, (j-i)*height[j]);
                    j--;
                }
            }
           	return water;
        }
};