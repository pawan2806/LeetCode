class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
		// prefix vector will store the minimum len of subarray with sum equal to target till the current index
		// suffix vector will also store the minimum len of subarray with sum equal to target till the current index 'but from end'
        vector<int> prefix,suffix;
        int sum = 0;
        int mini = INT_MAX;
        int i = 0,j = 0;
        while(j<n){
            sum += arr[j];
            while(sum>target){
                sum -= arr[i];
                i++;
            }
            if(sum==target){
                mini = min(mini,j-i+1);
            }
            prefix.push_back(mini);
            j++;
        }
        i = n-1,j = n-1;
        mini = INT_MAX;
        sum = 0;
        while(j>=0){
            sum += arr[j];
            while(sum>target){
                sum -= arr[i];
                i--;
            }
            if(sum==target){
                mini = min(mini,i-j+1);
            }
            suffix.push_back(mini);
            j--;
        }
        reverse(suffix.begin(),suffix.end());
        int ans = INT_MAX;
        for(int i = 0;i<n-1;i++){
            if(suffix[i+1]!=INT_MAX && prefix[i]!=INT_MAX){
                ans = min(ans,suffix[i+1]+prefix[i]);
                }
           
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};