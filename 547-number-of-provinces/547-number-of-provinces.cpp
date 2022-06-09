class Solution {
public:
    
    void helper(int i, vector<vector<int>> isConnected,  vector<bool> &vis){
      
        vis[i]=true;
         for (int j = 0; j < vis.size(); j++) {
            if (i != j && isConnected[i][j] && !vis[j]) {
                helper(j, isConnected, vis);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> vis(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                helper(i, isConnected, vis);
            }
        }
        
        
        
        return count;
        
    }
};