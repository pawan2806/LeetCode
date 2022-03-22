class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string temp="";
        int n=s.length();
        reverse(s.begin(), s.end());
        for(int i=0;i<n;i++){
            
            if(s[i]!=' '){
                temp+=s[i];
            } else if(temp!=""){
                reverse(temp.begin(), temp.end());
                ans+=temp;
                ans+=" ";
                temp="";
            }
        }
        if(temp!=""){
            reverse(temp.begin(), temp.end());
            ans+=temp;
        }
        if(ans[ans.size()-1]==' '){
            ans.pop_back();
        }
       
        return ans;
    }
};