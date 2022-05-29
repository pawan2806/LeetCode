class Solution {
public:
    
    int search(vector<int>& nums, int target) {
         int low=0,high=nums.size()-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;
            
            if(nums[mid]>=nums[low])//left side is sorted
            {
                if(target<nums[mid] && target>=nums[low])//if left side contains the target (range check)
                    high=mid-1;
                else//if doesn't contains target, goto right half of the array
                    low=mid+1;
            }
            else//right side is sorted
            {
                if(target<=nums[high] && target>nums[mid])//if right side contains target
                    low=mid+1;
                else//else goto left part 
                    high=mid-1;
            }
        }
        return -1;
    }
};