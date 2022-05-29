class Solution {
    // if whole array is sorted, this will take N+(N-1)+(N-2)... = O(N^2)
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size()-1;
        int pivotIdx = nums.size();
        
        while (pivotIdx != nums.size()-k) {
            pivotIdx = partition(nums, left, right);
            if (pivotIdx < nums.size()-k) {
                left = pivotIdx+1;
            } else {
                right = pivotIdx-1;
            }
        }
        return nums[pivotIdx];
    }
private:
    int partition(vector<int>& nums, int left, int right) {
        // 1. we take the middle element
        int pivot_idx = right;
        int pivot_val = nums[pivot_idx];
        // 3. we swap all elements smaller than pivot to the left
        int store_idx = left;
        for (int i = left; i < right; ++i) {
            if (nums[i] < pivot_val) {
                swap(nums[i], nums[store_idx]);
                store_idx++;
            }
        }
        // 4. move pivot back to its place
        swap(nums[store_idx], nums[pivot_idx]);
        return store_idx;
    }
};