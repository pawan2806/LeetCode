class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        for(int i=0;i<n;i++){
            ans+='a'; 
            k--;
        }
        // now we have a lexicographically smallest string of size n with score n;
        // remaining score = k-n;
        // we iterate from back of string and incrementing the score of the string. 
        // Iterating from behind because we have to find smallest string.
        int gg=n-1;
        while(k>0){
            if(k>25){
                ans[gg]=ans[gg]+25;
                gg--;
                k-=25;
            } else {
                ans[gg]=ans[gg]+k;
                // updating remaining score to 0
                k=0;
            }
        }
        return ans;
    }
};