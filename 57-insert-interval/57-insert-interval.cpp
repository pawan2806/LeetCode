class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int isInserted = 0;
        vector<vector<int>> res;
        for(int i = 0; i < intervals.size(); i++){
            
            if(isInserted || newInterval[0] > intervals[i][1]){
                res.push_back(intervals[i]);
            }
           
            else if(newInterval[1] < intervals[i][0]){
                res.push_back(newInterval);
                res.push_back(intervals[i]);
                isInserted = 1;
            }
            // if interval overlap the newInterval, update the newInterval
            else{
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        // if newInterval has not been inserted
        if(!isInserted){
            res.push_back(newInterval);
        }
        return res;
//         vector<vector<int>> ans;
//         int n=intervals.size();
       
//         if(n==0){
//             ans.push_back(newInterval);
//             return ans;
//         } else if(intervals[n-1][1]<newInterval[0]){
//             intervals.push_back(newInterval);
//             return intervals;
//         } else if(intervals[0][0]>newInterval[1]){
//             reverse(intervals.begin(), intervals.end());
//             intervals.push_back(newInterval);
//             reverse(intervals.begin(), intervals.end());
//             return intervals;
//         }
        
//         int i=0;
//         while(i<n && intervals[i][1]<newInterval[0]){
//             ans.push_back(intervals[i]);
//             i++;
//         }
       
    
//         intervals[i][1]=max(intervals[i][1], newInterval[1]);
//         intervals[i][0]=min(intervals[i][0], newInterval[0]);
//         ans.push_back(intervals[i]);
//         i++;
//         for(i;i<intervals.size();i++){
//             vector<int> x=intervals[i];
//             if(x[0]<=ans[ans.size()-1][1]){
//                 ans[ans.size()-1][1]=max(ans[ans.size()-1][1], x[1]);
//             } else if(x[0]>ans[ans.size()-1][1]){
//                 ans.push_back(x);
//             }
//         }
//        return ans;
    }
};