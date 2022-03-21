class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minlen=INT_MAX;
        string minstr;
        string ans;
        int n=strs.size();
        if(n==1){
            return strs[0];
        }
        for(int i=0;i<n;i++){
            if(minlen>strs[i].length()){
                minlen=strs[i].length();
                minstr=strs[i];
            }
        }
        if(minlen==0){
            return "";
        }
       cout<<minstr<<endl;
        for(int i=0;i<minlen;i++){
            bool check=true;
            for(int j=0;j<n;j++){
                if(strs[j][i]!=minstr[i]){
                    check=false;
                    break;
                }
            }
            if(check){
                ans+=minstr[i];
            } else {
                return ans;
            }
            
        }
        return ans;
    }
};