class Solution
{
    public:

        int totalHammingDistance(vector<int> &nums)
        {
            int n = nums.size();
            long long int count = 0;
            for (int i = 0; i < 32; i++)
            {
                long long int count0 = 0;
                long long int count1 = 0;
                for (int j = 0; j < n; j++)
                {
                    int x = nums[j];
                    if (x &(1 << i))
                    {
                        count1++;
                    }
                    else
                    {
                        count0++;
                    }
                }
                count += count1 * count0;
            }
            return (int) count;
        }
};