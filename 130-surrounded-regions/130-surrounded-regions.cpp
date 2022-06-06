class Solution {
public:
    void dfs(vector<vector<char>>& board , int i, int j){
        if(i>=board.size() || i<0 || j<0 || j>=board[0].size()){
            return ;
        }
        if(board[i][j]=='X' || board[i][j]=='1'){
            return;
        }
        board[i][j]='1';
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        for(int k=0;k<4;k++){
            dfs(board, i+dx[k], j+dy[k]);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                q.push(make_pair(0,i));
            }
        }
        for(int i=1;i<n;i++){
            if(board[i][m-1]=='O'){
                q.push(make_pair(i,m-1));
            }
        }
        for(int i=m-2;i>=0;i--){
            if(board[n-1][i]=='O'){
                q.push(make_pair(n-1,i));
            }
        }
        for(int i=n-2;i>=0;i--){
            if(board[i][0]=='O'){
                q.push(make_pair(i,0));
            }
        }
        
        
        while(!q.empty()){
            auto x=q.front();
            q.pop();
           // board[x.first][x.second]='1';
            dfs(board, x.first, x.second);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='1'){
                    board[i][j]='O';
                }else {
                    board[i][j]='X';
                }
            }
        }
        
    }
};