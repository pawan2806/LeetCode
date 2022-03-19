class Solution
{
    public:
        int firstMissingPositive(vector<int> &nums)
        {

            auto i = 0;
            int n=nums.size();
            while (i < n)
            {
               	// cout << i << endl;
                if (nums[i] == i + 1)
                {
                    i++;
                }
                else if (nums[i] <= 0 || nums[i] > n)
                {
                    nums[i++] = 0;
                }
                else if (nums[nums[i] - 1] == nums[i])
                {
                    nums[i++] = 0;
                }
                else
                {
                    swap(nums[i], nums[nums[i] - 1]);
                }
            }
            for (auto i = 0; i < n; i++)
            {
                if (nums[i] == 0)
                    return i + 1;
            }
            return n + 1;

           	//         int n=nums.size();
           	//         int maxim=INT_MIN;
           	//        	//bool npres=false;
           	//         for(int i=0;i < n;i++){
           	//             maxim=max(maxim, nums[i]);
           	//         }
           	//         for(int i=0;i < n;i++){
           	//             if(nums[i]<=0){
           	//                 nums[i]=maxim;
           	//             }

           	//         }
           	//         for(int i=0;i < n;i++){
           	//             if(abs(nums[i]) < n){
           	//                 if(nums[abs(nums[i])]>=0)
           	//                     nums[abs(nums[i])]*=(-1);
           	//             } 
           	//         }
           	//         for(int i=1;i < n;i++){
           	//             if(nums[i]>0){
           	//                 return i;
           	//             }
           	//         }

           	//         return maxim+1;
        }
};