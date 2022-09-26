class Solution {
public:
   int maximumScore(vector<int>& nums, int k) { 
        int n=nums.size();
        vector<int>r(n,n);
        vector<int>l(n,-1);
        
        for(int i=1;i<n;i++)
        {
            int j=i-1;
            while(j>=0 and nums[j]>=nums[i])
            {
                j=l[j];
            }
            
            l[i]=j;
        }
        
        for(int i=n-2;i>=0;i--)
        {
            int j=i+1;
            while(j<n and nums[j]>=nums[i])
            {
                j=r[j];
            }
            r[i]=j;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int val=(r[i]-l[i]-1);
            if(k<=r[i]-1 and k>=l[i]+1)
            {
                ans=max(ans,val*(nums[i]));
            }
        }
        return ans; 
    }
};