class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        int min_el = INT_MIN;
        for(int i = nums.size() - 1 ; i >= 0 ; i--)
        {
           if(nums[i] < min_el) return true;
            
            while(!stk.empty() && nums[i] > stk.top())
            {
                min_el = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};