class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int count=1;
        vector<vector<int>> ans(n, vector<int>(n,0));
        int rowStart=0,rowEnd=n-1, colStart=0, colEnd=n-1;
        while(count<=n*n){
            for(int i=colStart;i<=colEnd;i++){
                ans[rowStart][i]=count;
                count++;
            }
            rowStart++;
            
            for(int i=rowStart;i<=rowEnd;i++){
                ans[i][colEnd]=count;
                count++;
            }
            colEnd--;
            
            for(int i=colEnd;i>=colStart;i--){
                ans[rowEnd][i]=count;
                count++;
            }
            rowEnd--;
            
            for(int i=rowEnd;i>=rowStart;i--){
                ans[i][colStart]=count;
                count++;
            }
            colStart++;
            
        }
        
        return ans;
    }
};