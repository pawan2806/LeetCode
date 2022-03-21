class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]==' ' || !((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57))){
                continue;
            } else if(s[i]>=65 && s[i]<=90){
                str+=s[i]+32;
            } else {
                str+=s[i];
            }
        }
        string ans=str;
        reverse(str.begin(), str.end());
        return ans==str;
    }
};