class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> gg(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                gg[i][j]=board[i][j];
            }
        }
        
        int dx[8]={-1,-1,-1,0,1,1,1,0};
        int dy[8]={-1,0,1,1,1,0,-1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int nei=0;
                for(int k=0;k<8;k++){
                    int xind=dx[k]+i;
                    int yind=dy[k]+j;
                    if(xind>=0 && xind<n && yind>=0 && yind<m){
                        if(board[xind][yind]==1){
                            nei++;
                        }
                    }
                }
                if(board[i][j]==1 && (nei<2 || nei>3)){
                    gg[i][j]=0;
                } else if(board[i][j]==1 && (nei==2 || nei==3)) {
                    gg[i][j]=1;
                } else if(board[i][j]==0 && nei==3){
                    gg[i][j]=1;
                }
            }
        }
        board=gg;
    }
};