class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==k){
            return ;
        }
       
        if(k>n){
            k=k%n;
        }
       
       
        int st=0, end=n-k-1;
        while(st<end){
            int temp=nums[st];
            nums[st]=nums[end];
            nums[end]=temp;
            st++;
            end--;
        }
        st=n-k, end=n-1;
        while(st<end){
            int temp=nums[st];
            nums[st]=nums[end];
            nums[end]=temp;
            st++;
            end--;
        }
        reverse(nums.begin(), nums.end());
    }
};