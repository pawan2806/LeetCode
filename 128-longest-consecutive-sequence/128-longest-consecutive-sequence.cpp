class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int maxans=0;
         for(int i=0;i<n;i++){
            if(m[nums[i]]==0){
                continue;
            } else {
                int count=1;
                int x=nums[i];
                int st=x+1, end=x-1;
                while(m[st]!=0){
                    count++;
                    m[st++]=0;
                }
                while(m[end]!=0){
                    count++;
                    m[end--]=0;
                }
                maxans=max(maxans, count);
            }
        }
        return maxans;
    }
};