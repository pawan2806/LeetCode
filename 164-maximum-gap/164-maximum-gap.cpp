class Solution
{
    public:
        int maximumGap(vector<int> &nums)
        {
            const int n = nums.size();
            if (n < 2) return 0;
            int ans = 0;
            const auto &[minV, maxV] = minmax_element(nums.begin(), nums.end());
            const int range = *maxV - *minV;
            const int bucket_size = max(1, range / (n - 1));	// minimum possible maximum gap, to prove it, refer to[1]
            const int bucket_num = range / bucket_size + 1;	// minimum bucket number to hold ALL the array items 
            vector<int> bucket_mins(bucket_num, INT_MAX);
            vector<int> bucket_maxs(bucket_num, INT_MIN);
            for (auto &num: nums)
            {
                int bucket_idx = (num - *minV) / bucket_size;
                bucket_mins[bucket_idx] = min(bucket_mins[bucket_idx], num);
                bucket_maxs[bucket_idx] = max(bucket_maxs[bucket_idx], num);
            }

            int pre_maxV = bucket_maxs[0];
            for (int i = 1; i < bucket_num; i++)
            {
                if (bucket_mins[i] != INT_MAX)
                {
                	// ensure current bucket is non-empty
                    ans = max(ans, bucket_mins[i] - pre_maxV);
                    pre_maxV = bucket_maxs[i];
                }
            }
            return ans;
        }
   	//         int maximumGap(vector<int> &nums)
   	//         {
   	//             long long int n = nums.size();
   	//             if (n < 2)
   	//             {
   	//                 return 0;
   	//             }

   	//             double intervals;
   	//             long long int minim = nums[0];
   	//             long long int maxum=nums[0];
   	//             for (int i = 1; i < n; i++)
   	//             {

   	//                 if (nums[i] < minim)
   	//                 {
   	//                     minim = nums[i];
   	//                 }
   	//                 if(nums[i]>maxum){
   	//                     maxum=nums[i];
   	//                 }
   	//             }
   	//             intervals = ceil((maxum-minim+0.0) / (n - 1));

   	//             long long int interval = int(intervals);
   	//             vector < long long int > buckmin(n-1, INT_MAX);
   	//             vector < long long int > buckmax(n-1, -1);

   	//             long long int ans = 0;

   	//             for (int i = 0; i < n; i++)
   	//             {
   	//                 if(nums[i]==minim || nums[i]==maxum){
   	//                     continue;
   	//                 }
   	//                 long long int magic = (nums[i] - minim) / interval;
   	//                 if (nums[i] < buckmin[magic])
   	//                 {
   	//                     buckmin[magic] = nums[i];
   	//                 }

   	//                 if (buckmax[magic] < nums[i])
   	//                 {
   	//                     buckmax[magic] = nums[i];
   	//                 }
   	//             }
   	//             for (int i = 1; i < interval; i++)
   	//             {
   	//                 if (ans < buckmin[i] - buckmax[i - 1])
   	//                 {
   	//                     ans = buckmin[i] - buckmax[i - 1];
   	//                 }
   	//             }
   	//             return ans;
   	//         }
};