class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
   unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int ans = 0;
        for(auto it:mp){
            int findd = it.first + k;
            if(mp.find(findd) != mp.end()){
                if(findd == it.first && mp[findd] > 1){
                    ans++;
                }else if(findd != it.first){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};