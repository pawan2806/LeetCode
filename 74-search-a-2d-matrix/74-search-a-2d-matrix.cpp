class Solution
{
    public:
        bool searchMatrix(vector<vector < int>> &arr, int target)
        {
            int m = arr.size(), n = arr[0].size();
            int i = 0, j = n - 1;
            while (i < m and j >= 0 and min(i, j) >= 0)
            {
                if (arr[i][j] == target) return true;
                else if (arr[i][j] > target) --j;
                else ++i;
            }
            return false;
        }
};