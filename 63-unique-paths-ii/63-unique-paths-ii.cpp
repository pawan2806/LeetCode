class Solution {
public:
    int row, col;
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        
        //base cases
        if(i < 0 || j < 0
          || i >= row
          || j >= col)
            return 0;
        
        if(grid[i][j]){
            dp[i][j] = 0;
            return dp[i][j];
        }
        
        if(i == row - 1 && j == col - 1)
            return 1;
        
        if(dp[i][j])
            return dp[i][j];
        
        dp[i][j] = dfs(grid, i + 1, j, dp) + dfs(grid, i, j + 1, dp);
        
        return dp[i][j];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        row = obstacleGrid.size();
        col = obstacleGrid[0].size();
        
        vector<vector<int>> dp(row, vector<int>(col, 0));
        
        return dfs(obstacleGrid, 0, 0, dp);
    }
};