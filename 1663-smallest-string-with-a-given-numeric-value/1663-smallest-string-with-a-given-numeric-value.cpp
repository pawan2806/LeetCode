class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        for(int i=0;i<n;i++){
            ans+='a';
            k--;
        }
        int gg=n-1;
        while(k>0){
            if(k>25){
                ans[gg]=ans[gg]+25;
                gg--;
                k-=25;
            } else {
                ans[gg]=ans[gg]+k;
                k=0;
            }
        }
        return ans;
    }
};