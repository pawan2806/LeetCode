class Solution {
public:
    bool util(int s, vector<bool> &vis, vector<bool> &rec, vector<vector<int>> &adj ){
        if(!vis[s]){
            vis[s]=true;
            rec[s]=true;
            vector<int> init=adj[s];
            
            for(int i=0;i<init.size();i++){
                
                if(!vis[init[i]]){
                    if(util(init[i],vis,rec,adj)){
                        return true;
                    }
                } else if(rec[init[i]])
                     return true;
               
            }
        }
        
        rec[s]=false;
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<n;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> visited;
        vector<bool> recStack;
        for(int i=0;i<numCourses;i++){
            visited.push_back(false);
            recStack.push_back(false);
            
        }
        
         for(int u=0;u<numCourses;u++){
           
                if(util(u,visited,recStack,adj))
                    return false;
        }
        
        return true;
    }
};