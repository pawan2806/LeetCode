class Solution {
public:

    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans(2, 0);
        int low = INT_MAX;
        int high = INT_MIN;
        
        // Min Priority Queue to store num, pos(x, y)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; 
        
        for(int i=0;i<nums.size();i++){
            
            pq.push({nums[i][0], {i, 0}});
            // Updating the curr high and lows
            high = max(high, nums[i][0]);
            low = min(low, nums[i][0]);
            
        }
        
        
        // Updating the answer
        ans[0] = low;
        ans[1] = high;
        
        while(true){
            
            // Removing the lowest element
            pair<int, pair<int, int>> curr = pq.top();
            pq.pop();
            
            // Updating Low
            low = pq.top().first;

            
            int x = curr.second.first;
            int y = curr.second.second;
            
            // If any arr ends then we have to stop iterating
            if(nums[x].size() == y + 1)
                break;
            
            y = y+1;
            // Updating high and low checking the new number
            high = max(high, nums[x][y]);
            low = min(low, nums[x][y]);
            pq.push({nums[x][y], {x, y}});
            
            // Updating answer if better result is found
            if(high - low < ans[1] - ans[0]){
                ans[0] = low;
                ans[1] = high;
            }
        }
        
        
        return ans;
    }
};

// class Solution
// {
//     public:
//         typedef pair<int, int> pd;
//     struct comp
//     {
//         bool operator()(vector < int>
//             const &a, vector < int>
//             const &b)
//         {
//             return a[0] > b[0];
//         }
//     };
//     vector<int> smallestRange(vector<vector < int>> &nums)
//     {
//         int n = nums.size();
//         vector<int> ans = {(int)-pow(10, 5),(int)pow(10, 5)};
//         priority_queue<vector < int>, vector< vector< int >>, comp> q;
//         int currmax=INT_MIN;
//        // for (int i = 0; i < n; i++)
//         //{
//             //vector<int> gg = { nums[i][0], i,0};
//             //currmax=max(currmax, nums[i][0]);
//            // q.push(gg);
//        // }
//         while(true){
//             vector<int> gg=q.top();
//             q.pop();
//             //if(ans[1]-ans[0]>currmax-gg[0]){
//                //  ans[1]=currmax;
//                //  ans[0]=gg[0];
//                //  gg[2]++;
//                //  if(gg[2]>=nums[gg[1]].size()){
//                //      break;
//                //  }
//                // // currmax=max(currmax, nums[gg[1]][gg[2]]);
//                 //vector<int> xx = { nums[gg[1]][gg[2]], gg[1],gg[2]};
//                // q.push(xx);
//            // }
//         }
        

//         return ans;
//     }
// };