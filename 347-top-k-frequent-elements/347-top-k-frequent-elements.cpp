class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto i: mp){
            int num = i.first;
            int freq = i.second;
            pq.push({freq, num});
        }
        vector<int> vv;
        while(k--){
            vv.push_back(pq.top().second);
            pq.pop();
        }
        return vv;
    }
};