class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> ans;
        int maxlen=0;
        int currlen=0;
        int n=s.length();
        if(n<=1){
            return n;
        }
        int st=0;
        int i=0;
        while(i<n){
            ans[s[i]]++;
            if(ans[s[i]]>1){
                while(ans[s[i]]>1){
                    ans[s[st]]--;
                    st++;
                }
            }
            currlen=i-st+1;
            maxlen=max(maxlen, currlen);
            i++;
        }
        return maxlen;
    }
};