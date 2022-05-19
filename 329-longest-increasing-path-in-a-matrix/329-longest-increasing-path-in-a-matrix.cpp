class Solution {
public:
   int dp[200][200]; // constraints are small enough that we can just set them to MAX
int cnt, n, m;
int longestIncreasingPath(vector<vector<int>>& matrix) {
	cnt = 0, n = size(matrix), m = size(matrix[0]);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cnt = max(cnt, solve(matrix, i, j, -1));            
	return cnt;
}
int solve(vector<vector<int>>& mat, int i, int j, int prev){
	if(i < 0 || j < 0 || i >= n || j >= m || mat[i][j] <= prev) return 0;
	if(dp[i][j]) return dp[i][j];
	return dp[i][j] = 1 + max({ solve(mat, i + 1, j, mat[i][j]),
							    solve(mat, i - 1, j, mat[i][j]),
							    solve(mat, i, j + 1, mat[i][j]),
							    solve(mat, i, j - 1, mat[i][j]) });       
}
};