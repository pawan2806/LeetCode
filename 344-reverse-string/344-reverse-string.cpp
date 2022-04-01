class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size()-1, st=0;
        while(st<=n) swap(s[n--], s[st++]);
    }
};