class Solution {
public:
    void helper(vector<vector<int>>& grid,queue<vector<int>>&q,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1)
        {
            return;
        }
        grid[i][j]=-1;
        q.push({i,j,0});
        helper(grid,q,i-1,j);
        helper(grid,q,i+1,j);
        helper(grid,q,i,j-1);
        helper(grid,q,i,j+1);
    }
    bool isSafe(int i,int j,vector<vector<int>>&grid)
    {
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]!=-1;
    }
    int shortestBridge(vector<vector<int>>& grid) 
    {
        queue<vector<int>>q;
        for(int i=0;i<grid.size();i++)
        {
            bool found=false;
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    helper(grid,q,i,j);
                    found=true;
                    break;
                }
            }
            if(found)
            {
                break;
            }
        }
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=node[0]+dx[i],y=node[1]+dy[i];
                if(isSafe(x,y,grid))
                {
                    if(grid[x][y]==1)
                    {
                        return node[2];
                    }
                    grid[x][y]=-1;
                    q.push({x,y,node[2]+1});
                }
            }
        }
        return 0;
    }
};