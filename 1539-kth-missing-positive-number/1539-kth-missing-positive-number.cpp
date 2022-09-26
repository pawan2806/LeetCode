class Solution
{
    public:
        int findKthPositive(vector<int> &arr, int k)
        {
            int size = arr.size(), ll = 0, ul = size - 1, ans = 0;
            if (k < arr[0])
                return k;
            while (ll <= ul)
            {
                int mid = ll + (ul - ll) / 2, diff = arr[mid] - (mid + 1);
                if (diff == k)
                {
                    ans = arr[mid] - 1;
                    ul = mid - 1;
                }
                else if (diff < k)
                    ll = mid + 1;
                else
                    ul = mid - 1;
            }
            if (ans)
                return ans;
            int diff = arr[ul] - (ul + 1);
            return arr[ul] + (k - diff);
        }
};