class Solution
{
    public:
    void rev(int st, int end,vector<vector < int>> &grid ){
        while(st<=end){
            swap(grid[st++], grid[end--]);
        }
    }
        vector<vector < int>> shiftGrid(vector<vector < int>> &grid, int k)
        {
            int n = grid.size();
            int m = grid[0].size();
            vector<int> dp(n*m, -1);
            int count=0;
            k=k%(m*n);
            if(k==0){
                return grid;
            }
            k=(n*m)-k;
            if(k==0){
                return grid;
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    dp[count++]=grid[i][j];
                }
            }
            count=0;
            //k=(n*m)-k;
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