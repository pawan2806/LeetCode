class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // vector<int> eve;
        // vector<int> odd;
        // int n=nums.size();
        int oddindex=nums.size()-1, evenindex=0;
        
        while(oddindex>evenindex){
            while(oddindex>=0 && nums[oddindex]%2==1){
                oddindex--;
            }
            while(evenindex<nums.size() && nums[evenindex]%2==0){
                evenindex++;
            }
            if(oddindex>evenindex){
                int temp=nums[oddindex];
                nums[oddindex]=nums[evenindex];
                nums[evenindex]=temp;
              
                oddindex--;
                evenindex++;
            }
            
        }
       return nums;
        
    }
};