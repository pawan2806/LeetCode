class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<vector<int>> s;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<vector<int>> ans;
        s.push(intervals[0]);
        for(int i=1;i<n;i++){
            if(!s.empty() && s.top()[1]>=intervals[i][0]){
                s.top()[1]=max(s.top()[1], intervals[i][1]);
            } else if(!s.empty() && s.top()[1]<intervals[i][0]){
               s.push(intervals[i]);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         if(intervals.size()<= 1)
//         return intervals;
//     vector<vector<int>> res;
    
//     sort(intervals.begin(), intervals.end());

//     res.push_back(intervals[0]);
//         for(int i=1;i<intervals.size();i++){
//             if(res.back()[1]>=intervals[i][0]){
//                 res.back()[1]=max(res.back()[1],intervals[i][1]);
//             } else {
//                 res.push_back(intervals[i]);
//             }
            
//         }
        
//         return res;
    }
};