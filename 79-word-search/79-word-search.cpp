class Solution {
public:
    
    bool dfs(vector<vector<bool>> &vis, string word,vector<vector<char>>& board , int i, int j, int index) {
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0){
            return false;
        }
        
        if(index==word.length()){
            return true;
        }
        int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
        bool ans=false;
        for(int k=0;k<4;k++){
            int x=dx[k]+i;
            int y=dy[k]+j;
            if(x>=0 && y>=0 && x<board.size() && y<board[0].size()){
                if(!vis[x][y] && board[x][y]==word[index]){
                    vis[x][y]=true;
                    ans|= dfs(vis, word, board ,x,y, index+1);
                    vis[x][y]=false;
                    
                }
            }
        }
        return ans;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        
         vector<vector<bool>> vis(n, vector<bool>(m, false));
        bool ans=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                   
                    vis[i][j]=true;
                   ans |= dfs(vis, word, board ,i, j, 1);
                    vis[i][j]=false;
                }
            }
        }
        return ans;
        
    }
};