class Solution
{
    public:
        void nextPermutation(vector<int> &nums)
        {
            int i = nums.size() - 1;
            for (; i > 0; i--)
            {
                if (nums[i - 1] < nums[i])
                {
                    break;
                }
            }
            if (i == 0)
            {
                sort(nums.begin(), nums.end());
                return;
            }
            int num = nums[i - 1];
            int index = nums.size()-1;
            while(i-1<index && num>=nums[index]){
                index--;
            }
            swap(nums[i - 1], nums[index]);
            reverse(nums.begin() + i, nums.end());
        }
};