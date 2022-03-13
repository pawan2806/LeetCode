class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxtillnow=nums[0], maxans=nums[0], n=nums.size();
    
       for(int i=1;i<n;i++){
           maxtillnow+=nums[i];
           if(nums[i]>maxtillnow){
               maxtillnow=nums[i];
           }
           maxans=max(maxans,  maxtillnow);
       }
        
        return maxans;
    }
};