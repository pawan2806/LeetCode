class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low = 0;
        int high = 0;
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            high += nums[i];
            low = max(low, nums[i]);
        }
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canSplit(nums, mid, m)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
    
    bool canSplit(vector<int>& nums, int maxSum, int m) {
        int totalPart = 0;
        int currSum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(currSum + nums[i] <= maxSum) {
                currSum += nums[i];
            }
            else {
                currSum = nums[i];
                totalPart++;
            }
        }
        return (totalPart + 1) <= m;
    }
};