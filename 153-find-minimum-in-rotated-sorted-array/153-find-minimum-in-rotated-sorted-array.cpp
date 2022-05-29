class Solution {
public:
   
    
    int findMin(vector<int>& nums) {
        int ans=INT_MAX;
        if(nums.size()==1){
            return nums[0];
        } else if(nums[0]<=nums[nums.size()-1]){
            return nums[0];
        }
        int left=0, right=nums.size()-1;
        
        while(left<=right){
            int mid=(left+right)/2;
            
            if(nums[0]<=nums[mid]){
                left=mid+1;
            } else {
                ans=min(ans, nums[mid]);
                right=mid-1;
            }
            
        }
        
        return ans;
      
    }
};