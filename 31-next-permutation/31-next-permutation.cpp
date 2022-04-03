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
            int index = i;
            int min = INT_MAX;
            for (int j = i; j < nums.size(); j++)
            {
                if ((nums[j] - num) > 0 && (nums[j] - num) < min)
                {
                    index = j;
                }
            }
            swap(nums[i - 1], nums[index]);
            reverse(nums.begin() + i, nums.end());
        }
};