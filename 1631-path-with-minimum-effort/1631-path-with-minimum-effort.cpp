class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    
    bool valid(int &newX, int &newY, int &m, int &n)
    {
        return newX>=0 && newX<m && newY >= 0 && newY < n;
    }
    
    int minimumEffortPath(vector<vector<int>>& het) 
    {
        
        int m = het.size();
        int n = het[0].size();
        if(m==1&&n==1) return 0;
        
        // store the max effort required till now in the path
        vector<vector<int>> strength(m, vector<int>(n, INT_MAX)); // store maximum cost till the point
        strength[0][0] = 0;

        // take a queue to process
        queue<pair<int,int>> q;
        q.push({0,0});
        
        
        while(!q.empty())
        {
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(auto it: dir) // BFS travel to all nodes
            {
                int newX = x+it[0];
                int newY = y+it[1];
                
                if(valid(newX,newY,m,n))
                {
                    int effort = abs(het[x][y]-het[newX][newY]);  // get the efforts to reach out to that point from neighbouring point
                    effort = max(strength[x][y], effort);  // compare to all the max value till path 
                    
                    if(strength[newX][newY] > effort)  // store the minimum path val in matrix
                    {
                         strength[newX][newY] = effort;
                         q.push({newX,newY});
                    
                     }
                      
                }
            }
        }
        return strength[m-1][n-1];
    }
};