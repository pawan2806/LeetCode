class Solution
{
    public:
        const int cost_maxi = 1000001;
    int dp[101][101][21];	// dp[i][curGroups][prevColor]
    long long int minCostPaint(vector<int> &houses, vector<vector< int>> &cost, int target, int i, int currGroups, int prevColor, int n)
    {
        if (i == houses.size())
        {
            if (currGroups == target) return 0;
            return cost_maxi;
        }
        if (currGroups > target) return cost_maxi;
        if (dp[i][currGroups][prevColor] != -1) return dp[i][currGroups][prevColor];
        if (houses[i] == 0)
        {
           	//paint these houses
           	//options to color  -> 1 to n
            long long int ans = cost_maxi;
            for (int color = 1; color <= n; color++)
            {

                ans = min(ans, cost[i][color - 1] + minCostPaint(houses, cost, target, i + 1, currGroups + (color != prevColor), color, n));
            }
            return dp[i][currGroups][prevColor] = ans;
        }
        else
        {
           	//already painted
            return dp[i][currGroups][prevColor] = minCostPaint(houses, cost, target, i + 1, currGroups + (prevColor != houses[i]), houses[i], n);
        }
    }
    int minCost(vector<int> &houses, vector<vector< int>> &cost, int m, int n, int target)
    {
        memset(dp, -1, sizeof(dp));
        long long int res = minCostPaint(houses, cost, target, 0, 0, 0, n);
        if (res >= cost_maxi) return -1;
        return res;
    }
};