class Solution
{
    public:
   
        vector<vector < int>> shiftGrid(vector<vector < int>> &grid, int k)
        {
            int n = grid.size();
            int m = grid[0].size();
            vector<int> dp(n*m, -1);
            int count=0;
            k=k%(m*n);
            k=(n*m)-k;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    dp[count++]=grid[i][j];
                }
            }
            count=0;
            reverse(dp.begin()+k, dp.end());
            reverse(dp.begin(),dp.begin()+k);
            reverse(dp.begin(),dp.end());
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    grid[i][j]=dp[count++];
                }
            }
            return grid;
            
        }
};