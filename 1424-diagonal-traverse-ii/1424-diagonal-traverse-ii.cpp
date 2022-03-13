class Solution
{
    public:
        vector<int> findDiagonalOrder(vector<vector < int>> &mat)
         {
            int m=mat.size(),n=mat[0].size();
        vector<int>res;
        map<int,vector<int>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<mat[i].size();j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        for(auto x:mp){
            
            reverse(x.second.begin(),x.second.end());

            for(auto i:x.second){
                res.push_back(i);
            }
        }

        return res;
//             vector<int> ans;
//             int n = nums.size();
//             for (int i = 0; i < n; i++)
//             {
//                 int count = 0;
//                 ans.push_back(nums[i][count]);
//                 count++;
//                 int j = i - 1;
//                 while (j >= 0)
//                 {
//                     if (nums[j].size() <= count)
//                     {
//                         count++;
//                         j--;
//                         continue;
//                     }
//                     ans.push_back(nums[j][count]);
//                     count++;
//                     j--;
//                 }
//             }

//             for (int i = 1; i < nums[n - 1].size(); i++)
//             {
//                 int count = n - 1;
//                 ans.push_back(nums[count][i]);
//                 count--;
//                 int j = i + 1;
//                 while (j <= n && nums[count].size() > j)
//                 {
//                     if (nums[count].size() <= j)
//                     {
//                         count--;
//                         j++;
//                         continue;
//                     }
//                     ans.push_back(nums[count][j]);
//                     count--;
//                     j++;
//                 }
//             }

//             return ans;
        }
};