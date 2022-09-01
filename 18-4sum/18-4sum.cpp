// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
// //         sort(nums.begin(), nums.end());
// //         int n=nums.size();
// //         vector<vector<int>> ans;
// //         if(n<4){
// //             return ans;
// //         }
// //         for(int i=0;i<n-3;i++){
// //             for(int j=i+1;j<n-2;j++){
// //                 int k=j+1, l=n-1;
// //                 while(k<l){
// //                     int s=nums[i]+nums[j]+nums[k]+nums[l];
// //                     if(s==target){
// //                         vector<int> gg;
// //                         gg.push_back(nums[i]);
// //                          gg.push_back(nums[j]);
// //                          gg.push_back(nums[k]);
// //                          gg.push_back(nums[l]);
// //                          ans.push_back(gg);
// //                         k++;
// //                         l--;
// //                             while(k+1<l && nums[k+1]==nums[k]){
// //                    k++;
// //                 }
// //                     while(l-1>k && nums[l-1]==nums[l]){
// //                    l--;
// //                 }
// //                     } else if(s>target){
// //                         l--;
// //                         while(l-1>k && nums[l-1]==nums[l]){
// //                    l--;
// //                 }
// //                     } else {
// //                         k++;
// //                          while(k+1<l && nums[k+1]==nums[k]){
// //                    k++;
// //                 }
// //                     }
                    
                    
                
                    
                    
// //                 }
                
                
                
// //                 while(j+1<n && nums[j+1]==nums[j]){
// //                    j++;
// //                 }
// //             }
            
// //             while(i+1<n && nums[i+1]==nums[i]){
// //                 i++;
// //             }
// //         }
        
        
        
// //         return ans;
//          vector<vector<int >> res; // creating a result vector
//         if(nums.empty()) { // If no element in given vector then empty vector iss returned
//             return res;
//         }
//         long long int n = nums.size();  // size of given vector
//         sort(nums.begin(), nums.end());  // sort the array in O(nlog(n)) for optimizing solution
        
//         for(int i = 0; i < n; i++) {    // i pointer from 0 to n
//             for(int j = i+1; j < n; j++) {  // j pointer from i+1 to n
//                 long long int  rem = target - nums[i] - nums[j]; // remaining value to find
//                 long long int  front = j+1;   // left pointer  just after j
//                 long long int  back = n-1;    // right pointer at last index
                
//                 while(front < back) { // loop till front and back pointer donot cross over
//                     long long int  two_sum = nums[front] + nums[back]; // now come to two sum problem where we need to check for rem
//                     if(two_sum < rem) front++;  // if(rem > two_sum) then logically we have to move front pointer ahead to increase value close to rem
                               
//                     else if(two_sum > rem) back--; // if(rem < two_sum) then logically move back pointer to back to minimise value to come closer to rem value 
                    
//                     else {           // if (rem == two_sum) then we got the quadruplet (i, j, front, back indexed values)
//                         vector<int > quadruplet(4, 0);
//                         quadruplet[0] = nums[i];
//                         quadruplet[1] = nums[j];
//                         quadruplet[2] = nums[front];
//                         quadruplet[3] = nums[back];
//                         res.push_back(quadruplet);
                        
//                         // processing the duplicates of number 3
//                         while(front < back && nums[front] == quadruplet[2]) ++front;
                        
//                         // processing the duplicates of number 4
//                         while(front < back && nums[back] == quadruplet[3]) --back;
//                     }
//                 }
//                 // processing the duplicates of number 2
//                 while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
//             }
//              // processing the duplicates of number 1
//                 while(i + 1 < n && nums[i + 1] == nums[i]) ++i;
//         }
//         return res;
//     }
// };
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
    }
	
    vector<vector<int>> kSum(vector<int>& nums, long long target, int start, int k) {
        vector<vector<int>> res;
        
        // If we have run out of numbers to add, return res.
        if (start == nums.size()) {
            return res;
        }
        
        // There are k remaining values to add to the sum. The 
        // average of these values is at least target / k.
        long long average_value = target / k;
        
        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest 
        // value in nums is smaller than target / k.
        if  (nums[start] > average_value || average_value > nums.back()) {
            return res;
        }
            
        if (k == 2) {
            return twoSum(nums, target, start);
        }
    
        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                for (vector<int>& subset : kSum(nums, static_cast<long>(target) - nums[i], i + 1, k - 1)) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset), end(subset));
                }
            }
        }
                                            
        return res;
    }
	
    vector<vector<int>> twoSum(vector<int>& nums, long long target, int start) {
        vector<vector<int>> res;
        unordered_set<long long> s;
    
        for (int i = start; i < nums.size(); ++i) {
            if (res.empty() || res.back()[1] != nums[i]) {
                if (s.count(target - nums[i])) {
                    res.push_back({int(target - nums[i]), nums[i]});
                }
            }
            s.insert(nums[i]);
        }
                                             
        return res;
    }  
};