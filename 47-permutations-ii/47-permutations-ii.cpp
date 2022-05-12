class Solution {
public:
    set<vector<int>> ans;
    void helper(vector<int>& nums, vector<int> &temp, int start, int n){
        if(start==n-1){
            ans.insert(nums);
            return ;
        }
       
        for(int i=start;i<n;i++){
            if(i==start || nums[start]!=nums[i]){
                swap(nums[start], nums[i]);
                helper(nums, temp, start+1, n);
                swap(nums[start], nums[i]);
            }
            
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        helper(nums, temp, 0, n);
        vector<vector<int>> res;
        for(auto x: ans){
            res.push_back(x);
        }
        
        return res;
    }
};