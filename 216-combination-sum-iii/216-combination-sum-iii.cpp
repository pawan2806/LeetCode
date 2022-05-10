class Solution
{
    public:
        void helper(int idx, int sum, vector<vector < int>> &ans, vector< int > &v, int k, int n)
        {

           	//base case
            if (sum == n && k == 0)
            {
                ans.push_back(v);
                return;
            }

            if (sum > n)
            {
            	//when sum exceedes n -> return
                return;
            }

            for (int i = idx; i <= 9; i++)
            {
            	//nos that can be used are from 1 to 9

                v.push_back(i);	//if chosen i
                helper(i + 1, sum + i, ans, v, k - 1, n);	//recursive call -> from i+1 since we do not want to repeat nos
                v.pop_back();	//backtrack
            }
        }

    vector<vector < int>> combinationSum3(int k, int n)
    {
        vector<vector < int>> ans;

        vector<int> v;

        helper(1, 0, ans, v, k, n);
        return ans;
    }
};