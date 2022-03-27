class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        // int i=m-1, j=0, minindex=0;
        // vector<int> ans;
        // for(;i>=0;i--){
        //     bool check=true;
        //     for(;j<n;j++){
        //         if(mat[j][i]==1){
        //             check=false;
        //             break;
        //         }
        //     }
        //     if(!check){
        //         break;
        //     }
        // }
        int minzero=INT_MAX;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    count++;
                } else {
                    break;
                }
            }
            if(minzero>count){
                minzero=count;
            }
        }
        vector<int> ans;
        map<int,int> man;
        if(minzero==m){
            while(k--){
                int gg=0;
                ans.push_back(gg++);
            }
            return ans;
        } else {
            int start=minzero,gg=0;
            cout<<k<<endl;
            for(int j=minzero;j<m && k;j++){
                for(int i=0;i<n && k;i++){
                    if(mat[i][j]==0 && man[i]==0){
                        ans.push_back(i);
                        man[i]++;
                        k--;
                    }
                }
            }
            for(int i=0; i<n;i++){
                if(k && man[i]==0){
                    ans.push_back(i);
                    k--;
                }
            }
            return ans;
        }
        
    }
};