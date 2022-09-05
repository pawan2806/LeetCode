class Solution
{
    public:
        int firstMissingPositive(vector<int> &nums)
        {

            auto i = 0;
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                if (nums[i] <= 0 || nums[i] > n)
                {
                    continue;
                }
                else
                {
                    int chair = nums[i] - 1;
                    int element = nums[i];
                    if (nums[chair] != element)
                    {
                        swap(nums[chair], nums[i--]);
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (nums[i]!=i+1)
                {
                    return i+1;
                }
               
            }
            return n+1;
        }
};