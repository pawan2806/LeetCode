class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        if(n==1){
            return ans;
        }
        for(int i=1;i<n;i++){
            string temp;
            ans+='$';
            int len=ans.length();
            int count=1;
            char begin=ans[0];
            int j=1;
            while(ans[j]!='$'){
                if(ans[j]==begin){
                    count++;
                } else {
                    temp+=to_string(count);
                    temp+=ans[j-1];
                    begin=ans[j];
                    count=1;
                }
                j++;
            } 
            temp+=to_string(count);
            temp+=ans[j-1];
            ans=temp;
        }
        return ans;
    }
};