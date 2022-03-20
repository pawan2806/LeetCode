class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long int ans=0;
        int temp=x;
        while(x){
            ans=ans*10+ x%10;
            if(ans>INT_MAX){
                return false;
            }
            x=x/10;
        }
        cout<<ans<<endl;
        return (temp==(int)ans)?true:false;
    }
};