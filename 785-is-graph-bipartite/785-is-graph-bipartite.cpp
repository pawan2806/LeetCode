class Solution {
public:
    
int dfs(int node, int c, int col[], vector<vector<int>> &adj){
    col[node]=c;
    for(int child:adj[node]){
        // if colour of child is same as that of node return 0
        if(col[child]==c) return 0;
        // col[child]==-1 means child is not visited
        if(col[child]==-1 && dfs(child, (c^1), col, adj)==0) return 0;
    }
    return 1;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int A=graph.size();
        int col[A];
    memset(col, -1, sizeof(col));
    for(int i=0; i<A; i++){
        if(col[i]==-1 && dfs(i, 0, col, graph)==0) return 0;
    }
    return 1;
      
    }
};