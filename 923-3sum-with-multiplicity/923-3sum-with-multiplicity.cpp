class Solution
{
    public:
        int threeSumMulti(vector<int> &arr, int target)
        {
            long long int ans = 0;
            long long int mod = pow(10, 9) + 7;

            map<int, long> m;
            int n = arr.size();
            for (int i = 0; i < n; i++)
            {
                m[arr[i]]++;
            }

            for (auto it: m)
            {
                for (auto itr: m)
                {
                    int i = it.first, j = itr.first, k = target - i - j;
                    if (!m[k])
                    {
                        continue;
                    }
                    if (i == j && j == k)
                    {
                        ans += ((m[i] *(m[i] - 1) *(m[i] - 2)) / 6) % mod;
                    }
                    else if (i == j && j != k)
                    {
                        ans += ((m[i] *(m[i] - 1) *(m[k])) / 2) % mod;
                    }
                    else if(i<j && j<k)
                    {
                        ans += (m[i] *m[j] *m[k]) % mod;
                    }
                }
            }
            return ans % mod;
        }
};