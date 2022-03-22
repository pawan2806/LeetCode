class Solution {
public:
    int lengthOfLastWord(string s) {
        string ans;
        int n=s.length()-1;
        while(n>=0 && s[n]==' '){
            n--;
        }
        while(n>=0 && s[n]!=' '){
            ans+=s[n];
            n--;
        }
        return ans.length();
        
    }
};