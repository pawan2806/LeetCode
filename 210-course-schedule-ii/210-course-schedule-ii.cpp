class Solution {
public:
    stack<int> s;
    
   	bool util(int V, vector<bool> &visited, vector<bool> &recStack,const  vector<vector<int>> &adj){
        
        if(visited[V]==false){
        
         visited[V]=true;
         recStack[V]=true;
        vector<int> it=adj[V];
        
        for(int i=0;i<it.size();i++){
          
          if(!visited[it[i]])
          {
              if (util(it[i],visited, recStack, adj))
                  return true;
          } 
          else if(recStack[it[i]])
              return true;
          
        }   
    }
    s.push(V);
    recStack[V]=false;
    return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);
        vector<vector<int>> adj(numCourses);
       
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            vector<int> temp=prerequisites[i];
            adj[temp[0]].push_back(temp[1]);
        }
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(!visited[i])
           if(util(i,visited,recStack,adj))
	                return ans;
            
        }
        
        while(!s.empty()){
            int x=s.top();
            ans.push_back(x);
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};