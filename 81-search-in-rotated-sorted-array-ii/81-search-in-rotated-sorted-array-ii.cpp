// class Solution {
// public:
//     int binserach(int l, int r, vector<int> nums, int target){
//         if(r<l){
//             return -1;
//         }
//         int mid=(l+r)/2;
//         if(nums[mid]==target){
//             return mid;
//         } else if(nums[mid]>target){
//           return binserach(l,mid-1, nums, target);
//         } else {
//            return binserach(mid+1, r, nums, target);
//         }
         
//     }
//     bool search(vector<int>& nums, int target) {
//         int l=0, r=nums.size()-1;
//         int index=-1;
//         while(l<=r){
//             int mid=(l+r)/2;
//             if(mid>0 && mid<nums.size() && nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
//                 index=mid;
//                 break;
//             } else if(nums[mid]>nums[l]){
//                // index=l;
//                 l=mid+1;
//             } else {
//                 r=mid-1;
//             }
//         }
//         if(index==-1){
//             if(binserach(0, nums.size()-1, nums, target)==-1){
//                 return false;
//             }
//             return true;
//         } else {
//             if(binserach(0,  index, nums, target)!=-1 || binserach(index+1, nums.size()-1, nums, target)!=-1){
//                 return true;
//             }
//             return false;
//         }
//     }
// };
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r)
        {
            int mid = l + (r-l) / 2;
            if (nums[mid] == target)
                return true;
			// with duplicates we can have this contdition, just update left & right
            if((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
            {
                l++;
                r--;
            }
			// first half
			// first half is in order
            else if(nums[l] <= nums[mid])
            {
				// target is in first  half
                if((nums[l] <= target) && (nums[mid] > target))
                    r = mid - 1;
                else
                    l = mid + 1;
            }
			// second half
			// second half is order
			// target is in second half
            else
            {
                if((nums[mid] < target) && (nums[r]>= target))
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
	// for github repository link go to my profile.
};