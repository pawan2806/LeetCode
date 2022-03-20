class Solution {
public:
    string convertToTitle(int x) {
        string ans="";
        while(x>0){
            int mod=x%26;
            if(mod==0){
                ans+='Z';
                x=x/26;
                x--;
                continue;
            } else {
                ans+='A'+mod-1;
            }
            x=x/26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};