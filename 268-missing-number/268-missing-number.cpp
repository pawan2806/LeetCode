class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        long long int sum=(n*(n+1))/2;
        long long int temp=0;
        for(int i=0;i<n;i++){
            temp+=nums[i];
        }
        return sum-temp;
    }
};