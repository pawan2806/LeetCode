class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st=0, end=nums.size()-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>target){
                end=mid-1;
            } else {
                st=mid+1;
            }
        }
        return -1;
    }
};