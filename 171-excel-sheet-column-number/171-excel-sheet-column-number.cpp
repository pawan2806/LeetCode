class Solution {
public:
    int titleToNumber(string str) {
        int n=str.length();
        long long int ans=str[0]-'A'+1;
        for(int i=1;i<n;i++){
            ans=ans*26+(str[i]-'A'+1);
        }
        //ans+=str[n-1]-'0';
        return (int)ans;
    }
};