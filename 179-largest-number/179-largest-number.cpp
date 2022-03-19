class Solution {
public:
     static bool oper(int x, int y){
        string X=to_string(x);
        string Y=to_string(y);
        return X+Y>Y+X;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), oper);
        string ans;
        for(int i=0;i<nums.size();i++){
            ans+=to_string(nums[i]);
        }
        while(ans.length()>1 && ans[0]=='0'){
            ans=ans.substr(1);
        }
        return ans;
    }
};