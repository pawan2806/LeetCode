class Solution {
public:
    int search(vector<int>& nums, int l, int r, int key)
{
    int index = -1;
    while (l <= r) 
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] <= key)
            r = mid - 1;
        else 
        {
            l = mid + 1;
            if (index == -1 || nums[index] >= nums[mid])
                index = mid;
        }
    }
    return index;
}
    
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
    int i;
    for(i = n - 2; i >= 0; i--)
    {
        if(nums[i] < nums[i + 1])
            break;
    }
    
    if(i < 0)
        reverse(nums.begin(), nums.end());
    
    else
    {
        int index = search(nums, i + 1, n - 1, nums[i]);
        swap(nums[i], nums[index]);
        reverse(nums.begin() + i + 1, nums.end());
    }
    }
};