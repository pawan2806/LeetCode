class Solution {
public:
    int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {-1,1,-1,0,1,-1,0,1};

typedef pair<int,pair<int,int>> pp;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid[0][0])return -1;                 // beginning node is blocked
	
    int n = grid.size();
    vector<vector<bool>> vis(n,vector<bool>(n,0));
    priority_queue<pp,vector<pp>,greater<pp>> q;
    q.push({1,{0,0}});
    vis[0][0] = 1;
	
    while(q.size()){
        auto cur = q.top();  q.pop();
        int d = cur.first, i = cur.second.first, j = cur.second.second;
		
        if(i == n-1 && j == n-1)return d;           // target node reached
		
        for(int k = 0; k < 8; k++){
            int ni = i+dx[k], nj = j+dy[k];
			
			//   check if the new position is valid
            if(ni >= 0 && nj >= 0 && ni < n && nj < n && !vis[ni][nj] && !grid[ni][nj]){
                vis[ni][nj] = 1;
                q.push({1+d,{ni,nj}});
            }
        }
    }
    return -1;       // target can't be reached
}
};