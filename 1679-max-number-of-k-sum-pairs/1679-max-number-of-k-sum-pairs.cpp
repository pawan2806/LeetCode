class Solution
{
    public:
        int maxOperations(vector<int> &num, int k)
        {
            sort(num.begin(), num.end());
            int st = 0, end = num.size() - 1;
            int ans = 0;
            while (st < end)
            {
                if (num[st] + num[end] == k)
                {
                    ans++;
                    st++;
                    end--;
                }
                else if (num[st] + num[end] > k)
                {
                    end--;
                }
                else
                {
                    st++;
                }
            }

            return ans;
        }
};