class Solution {
public:
    int lengthOfLastWord(string s) {
        string ans;
        while(s!="" && s[s.length()-1]==' '){
            s.pop_back();
        }
        int n=s.length()-1;
        while(n>=0 && s[n]!=' '){
            ans+=s[n];
            n--;
        }
        return ans.length();
        
    }
};